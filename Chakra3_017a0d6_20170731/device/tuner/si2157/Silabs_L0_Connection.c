/*************************************************************************************************************/
/*                                  Silicon Laboratories                                                     */
/*                                  Broadcast Video Group                                                    */
/*                     Layer 0      Communication Functions                                                  */
/*-----------------------------------------------------------------------------------------------------------*/
/*   This source code contains all i2c functions to communicate with i2c components                          */
/*     All functions are declared in Silabs_L0_API.h                                                         */
/*************************************************************************************************************/
/* Change log:

 As from 3.3.8:
  Declaring parameter strings as 'const char*' instead of 'char*' to limit -Wwrite-strings warnings

  As from 3.3.7:
  Adding L0_SlowI2C and L0_FastI2C for easier control of the i2c speed from the above layers

 As from 3.3.6:
  Improved porting comments in L0_ReadBytes

 As from 3.3.5:
  casting calls to strlen as (int) for greater compatibility with VisualStudio

 As from 3.3.4:
  Added help for 'resume' / "suspend'

 As from 3.3.3:
  Adding 'suspend' / 'resume' in traces to keep control of the traces destination at application level.
  This is required to avoid having the traces routed to file after each FW download with 'command mode' parts.

 As from 3.3.2:
 Correction on last character when changing traces file name
 Correction in traces file name management
 *************************************************************************************************************/
 /* TAG ROM40_0_A_build_10_V0.2 */

#include "Silabs_L0_API.h"
#include "si2157_i2c_api.h"

#ifdef    USB_Capability
  #include "CyAPIUser.h"
  typedef enum NN6_RET {
    RET_OK = 0,
    RET_KO = 2
  } NN6_RET;
#endif /* USB_Capability */

L0_Context  rawI2C_context;
L0_Context *rawI2C;

#define  SIMULATOR_SCOPE 1
int      Byte[SIMULATOR_SCOPE];

unsigned char  registerDataBuffer[8];
unsigned char *pucAddressBuffer;
unsigned char *pucBuffer;
unsigned char  ucAddressBuffer[4];
unsigned char  ucBuffer[1000];
unsigned char  cypress_checks_done    = 0;
char           L0_error_buffer_0[ERROR_MESSAGE_MAX_LENGH];
char           L0_error_buffer_1[ERROR_MESSAGE_MAX_LENGH];
char          *stored_error_message;
char          *L0_error_message;

#ifdef    __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef    SiTRACES
#define   SiTRACES_BUFFER_LENGTH  100000
#define   SiTRACES_NAMESIZE           30
#define   SiTRACES_FUNCTION_NAMESIZE  30
#if       SiTRACES_FEATURES == SiTRACES_FULL
    #define SiTRACES_DEFAULT_FILE "SiLabs_Traces.txt"
#endif /* SiTRACES_FEATURES */

typedef enum TYPE_OF_OUTPUT {
    TRACE_NONE = 0,
    TRACE_STDOUT,
    TRACE_EXTERN_FILE,
    TRACE_MEMORY,
}TYPE_OF_OUTPUT;

TYPE_OF_OUTPUT trace_output_type;

unsigned char trace_init_done        = 0;
unsigned char trace_suspend          = 0;
unsigned char trace_skip_info        = 0;
unsigned char trace_config_lines     = 0;
unsigned char trace_config_files     = 0;
unsigned char trace_config_functions = 0;
unsigned char trace_config_rename    = 0;
unsigned char trace_config_time      = 0;
unsigned char trace_lost_traces      = 0;
unsigned char trace_config_verbose   = 0;
int           trace_linenumber       = 0;
int           trace_current_index    = 0;
int           trace_count            = 0;

char trace_buffer[SiTRACES_BUFFER_LENGTH];
char trace_stockInt[25];
char trace_timer[50];
char trace_elapsed_time[20];
char trace_source_file[100];
char trace_file_name[SiTRACES_NAMESIZE+1];
char trace_source_function[SiTRACES_FUNCTION_NAMESIZE+1];
char trace_message[1000];
char trace_L0_message[1000];

/************************************************************************************************************************
  SiTraceDefaultConfiguration function
  Use:        SiTRACES initialization function.
              It is called on the first call to L0_Init (only once).
              It defines the default output and inserts date and time in the default file.
  Returns:    void
  Porting:    Not compiled if SiTRACES is not defined in Silabs_L0_API.h.
************************************************************************************************************************/
void  SiTraceDefaultConfiguration(void) {
#if       SiTRACES_FEATURES == SiTRACES_FULL
    FILE *file;
#endif /* SiTRACES_FEATURES == SiTRACES_FULL */
    time_t rawtime;
    struct tm * timeinfo;

    if (trace_init_done) return;
    trace_output_type=TRACE_EXTERN_FILE;
    trace_init_done=1;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    strftime (trace_timer,50,"%A %B %d   %I:%M%p   %Y",timeinfo);
#if       SiTRACES_FEATURES == SiTRACES_FULL
    sprintf(trace_file_name, "%s", SiTRACES_DEFAULT_FILE);
    file = fopen(trace_file_name,"w");
    if (file != NULL) {
      fprintf(file,"            SiTraceFunction log created on %s\n",trace_timer);
      fclose(file);
    } else {
      printf("%s file access not possible.\n",trace_file_name);
    }
#endif /* SiTRACES_FEATURES == SiTRACES_FULL */
}
/************************************************************************************************************************
  traceHelp function
  Use:        SiTRACES configuration help function.
  Returns:    the help menu text
  Porting:    Not compiled if SiTRACES is not defined in Silabs_L0_API.h.
************************************************************************************************************************/
char* traceHelp              (void) {
  return (char *)"\
-------------------------------------------------------------------------------------------\n\
 Possible traces commands:\n\
-------------------------------------------------------------------------------------------\n\
traces  -output   <memory/stdout/file/none>. select the trace destination (don't use 'stdout' in wish)\n\
traces  -file     <on/off> . . . . . . . . . select file name   mode (adding C source file name)\n\
traces  -line     <on/off> . . . . . . . . . select line number mode (adding C source file line number)\n\
traces  -function <on/off> . . . . . . . . . select function    mode (adding C source file function name)\n\
traces  -time     <on/off> . . . . . . . . . select time tag    mode (adding elapsed time as hh:mm:ss.ms)\n\
traces  -name     <file_name>. . . . . . . . select traces file name (default 'SiLabs_traces.txt' and '' gives the current file used)\n\
traces  -verbose  <on/off> . . . . . . . . . select verbose mode (traces in console even if '-output' not 'stdout')\n\
traces  show . . . . . . . . . . . . . . . . display buffered traces in console (not visible in wish)\n\
traces  get. . . . . . . . . . . . . . . . . display buffered traces (visible in wish)\n\
traces  count. . . . . . . . . . . . . . . . display number of traces since start\n\
traces  suspend. . . . . . . . . . . . . . . suspend tracing until 'resume'\n\
traces  resume . . . . . . . . . . . . . . . resume  tracing after 'suspend'\n\
traces  lost . . . . . . . . . . . . . . . . display number of traces lost since start\n\
traces  save . . . . . . . . . . . . . . . . save    buffered traces to file\n\
traces  flush. . . . . . . . . . . . . . . . erase   buffered traces\n\
traces  erase. . . . . . . . . . . . . . . . erase   file content\n\
traces  status . . . . . . . . . . . . . . . display the current traces flags\n\
traces  help . . . . . . . . . . . . . . . . display this help\n\
";
}
/************************************************************************************************************************
  traceFlushBuffer function
  Use:        SiTRACES buffer erasing function.
              It is called to empty the buffer.
  Porting:    Not compiled if SiTRACES is not defined in Silabs_L0_API.h.
  Parameter:  buffer  the trace buffer content.
  Returns:    void
************************************************************************************************************************/
void  traceFlushBuffer       (char *buffer) {
  trace_current_index=0;
  trace_lost_traces=0;
  buffer[0]=0;
}
/************************************************************************************************************************
  traceElapsedTime function
  Use:        SiTRACES time formatting function.
              It allows the user to know when the trace has been treated.
              It is used to insert the time before the trace when -time 'on'.
  Returns:    text containing the execution time in HH:MM:SS.ms format.
  Porting:    Not compiled if SiTRACES is not defined in Silabs_L0_API.h.
************************************************************************************************************************/
char *traceElapsedTime       (void) {
    int timeElapsed, ms, sec, min, hours;
    timeElapsed = system_time();
    ms=timeElapsed%1000;
    timeElapsed=timeElapsed/1000;
    sec=timeElapsed%60;
    timeElapsed=timeElapsed/60;
    min=timeElapsed%60;
    timeElapsed=timeElapsed/60;
    hours=timeElapsed%60;
    sprintf(trace_elapsed_time,"%02d:%02d:%02d.%03d ",hours,min,sec,ms);
    return trace_elapsed_time;
}
/************************************************************************************************************************
  traceToStdout function
  Use:        SiTRACES stdout display function.
              It displays the current trace in the command window.
              It adds file name, line number,function name and time if selected.
  Parameter:  trace
  Returns:    void
************************************************************************************************************************/
void  traceToStdout          (char* trace) {
    if (!trace_skip_info) {
        if (trace_config_files    ) { CUSTOM_PRINTF("%-40s ", trace_source_file    ); }
        if (trace_config_lines    ) { CUSTOM_PRINTF("%5d "  , trace_linenumber     ); }
        if (trace_config_functions) { CUSTOM_PRINTF("%-30s ", trace_source_function); }
    }
        if (trace_config_time     ) { CUSTOM_PRINTF("%s ",    traceElapsedTime()   ); }
                                      CUSTOM_PRINTF("%s",     trace);
}
#if       SiTRACES_FEATURES == SiTRACES_FULL
/************************************************************************************************************************
  traceToFile function
  Use:        SiTRACES file saving function.
              It writes the current trace in an extern file.
              It adds file name, line number,function name and time if selected.
  Parameter:  trace
  Returns:    void
  Porting:    Not compiled if SiTRACES is not defined in Silabs_L0_API.h.
************************************************************************************************************************/
void  traceToFile            (char* trace) {
    FILE *file;
    file = fopen(trace_file_name,"a+");

    if (file != NULL) {
      if (!trace_skip_info) {
          if (trace_config_files    ) { fprintf(file,"%-40s " , trace_source_file    ); }
          if (trace_config_lines    ) { fprintf(file,"%5d "   , trace_linenumber     ); }
          if (trace_config_functions) { fprintf(file, "%-30s ", trace_source_function); }
      }
          if (trace_config_time     ) { fprintf(file,"%s "    , traceElapsedTime()   ); }
      fprintf(file,"%s", trace);
      fclose(file);
    } else {
      trace_output_type=TRACE_MEMORY;
      printf("writing in %s failed, routing traces to memory.", trace_file_name);
    }
}
#endif /* SiTRACES_FEATURES == SiTRACES_FULL */
/************************************************************************************************************************
  traceToBuffer function
  Use:        SiTRACES buffer saving function.
              It adds file name, line number,function name and time if selected.
  Comment:    The trace buffer length is limited (it is set by SiTRACES_BUFFER_LENGTH).
              If the buffer is full, the oldest traces will be lost to write the new trace.
  Parameter:  trace
  Returns:    void
  Porting:    Not compiled if SiTRACES is not defined in Silabs_L0_API.h.
************************************************************************************************************************/
void  traceToBuffer          (char* trace) {
    char tmp[120];
    char *pBuffer;
    int new_string_length, lenTmp, lenTrace;

    pBuffer = trace_buffer;
    new_string_length=0;

    sprintf(tmp,"%s","");
    if (((trace_config_files || trace_config_lines) && (!trace_skip_info))  ||  trace_config_time) {
        if(trace_buffer[strlen(trace_buffer)-1] != '\n') {strcat(tmp, "\n");}
    }
    if (!trace_skip_info) {
        if (trace_config_files    ) { sprintf(tmp,"%s%-40s ", tmp, trace_source_file    ); }
        if (trace_config_lines    ) { sprintf(tmp,"%s%5d ",   tmp, trace_linenumber     ); }
        if (trace_config_functions) { sprintf(tmp,"%s%-30s ", tmp, trace_source_function); }
        }
    if (  trace_config_time       ) { strcat (tmp,                 traceElapsedTime() ); }

    lenTmp   = (int)strlen(tmp);
    lenTrace = (int)strlen(trace);
    new_string_length = lenTmp + lenTrace;

    if( (trace_current_index+new_string_length) > SiTRACES_BUFFER_LENGTH) {
        if( (trace_current_index+lenTmp) > SiTRACES_BUFFER_LENGTH) { /* tmp is cut */
            /* Copy the beginning of the TMP string at the end of the buffer */
            strncat(trace_buffer+trace_current_index ,tmp, SiTRACES_BUFFER_LENGTH-trace_current_index);

            /* Copy the end of the TMP string at the beginning of the buffer */
            sprintf(trace_buffer, "%s",               tmp+SiTRACES_BUFFER_LENGTH-trace_current_index);
            trace_current_index = lenTmp-(SiTRACES_BUFFER_LENGTH-trace_current_index);

            /* Copy the whole TRACE string after TMP*/
            strcat(trace_buffer+trace_current_index ,trace);
            trace_current_index += lenTrace;
        }
        else { /* trace is cut */
            /* Copy the whole TRACE string at the end of the buffer*/
            strcat(trace_buffer+trace_current_index ,tmp);
            trace_current_index += lenTmp;

            /* Copy the beginning of the TRACE string after TMP */
            strncat(trace_buffer+trace_current_index ,trace, SiTRACES_BUFFER_LENGTH-trace_current_index);

            /* Copy the end of the TRACE string at the beginning of the buffer */
            sprintf(trace_buffer, "%s",               trace+SiTRACES_BUFFER_LENGTH-trace_current_index);
            trace_current_index = lenTrace-(SiTRACES_BUFFER_LENGTH-trace_current_index);
        }
        trace_lost_traces++;
    }
    else {
        strcat(trace_buffer+trace_current_index ,tmp);
        trace_current_index += lenTmp;
        strcat(trace_buffer+trace_current_index ,trace);
        trace_current_index += lenTrace;
        if (trace_lost_traces) trace_lost_traces++;
    }
}
/************************************************************************************************************************
  traceToDestination function
  Use:        switch the trace in the selected output mode.
  Comment:    In verbose mode, the trace is always displayed in stdout.
  Parameter:  trace, the trace string
  Returns:    void
  Porting:    Not compiled if SiTRACES is not defined in Silabs_L0_API.h.
************************************************************************************************************************/
void  traceToDestination     (char* trace) {
    int last;
    if (trace_suspend) {return;}
    /* If trace is a single CrLf, do not print the file/line/function info           */
    if (strcmp(trace,"\n")==0) {trace_skip_info = 1;}
    /* If file/line/function info printed, make sure there is a CrLf after each line */
    if (trace_config_files + trace_config_lines + trace_config_functions + trace_config_time) {
      last = (int)strlen(trace)-1;
      if (trace[last] != 0x0a) {sprintf(trace, "%s\n", trace);}
    }
    switch(trace_output_type) {
        case TRACE_MEMORY      : traceToBuffer(trace); break;
        case TRACE_STDOUT      : traceToStdout(trace); break;
#if       SiTRACES_FEATURES == SiTRACES_FULL
        case TRACE_EXTERN_FILE : traceToFile  (trace); break;
#endif /* SiTRACES_FEATURES == SiTRACES_FULL */
        case TRACE_NONE        : return;               break;
        default :                                      break;
    }
    if ((trace_config_verbose) & (trace_output_type!=TRACE_STDOUT))  {traceToStdout(trace);}
    if (strcmp(trace,"\n")==0) {trace_skip_info = 0;}
    trace_count++;
}
/************************************************************************************************************************
  SiTraceConfiguration function
  Use:        SiTRACES configuration function.
              It is used to configure the traces or trace a custom string..
  Comments:   If the trace entered starts by 'traces', analyze the configuration string trace
              and define which type of arguments there are.
              (Each argument refers to a particular treatment).
              The trace message may include several series of (-<param> <value>) pairs.
  Parameter:  config, the configuration string or trace to add (if not a configuration string)
  Returns:    The help if 'traces help' or 'traces'
              The configuration  status if 'traces -<param> <value>'
              The traces buffer content if 'traces get'
              The number of      traces if 'traces count'
              The number of lost traces if 'traces lost'
              Nothing otherwise.
  Porting:    Not compiled if SiTRACES is not defined in Silabs_L0_API.h.
************************************************************************************************************************/
char *SiTraceConfiguration   (const char *config) {
#if       SiTRACES_FEATURES == SiTRACES_FULL
    FILE *file;
    time_t rawtime;
    struct tm * timeinfo;
    char c;
    unsigned int i;
    char *pArray;
#endif /* SiTRACES_FEATURES == SiTRACES_FULL */
    char saved;
    int loop, nbArgs, trace_configuration_message, lenTraceBuffer, destination, start, origine;
    char *array[50];
    char *pBuffer;

    loop                        = 0;
    trace_configuration_message = 0;
    trace_stockInt[0]           = 0;
    lenTraceBuffer              = (int)strlen(trace_buffer);
    destination                 = lenTraceBuffer%SiTRACES_BUFFER_LENGTH;
    start                       = lenTraceBuffer;
    saved                       = trace_buffer[start];
    pBuffer                     = trace_buffer;

    sprintf(trace_message, "%s", config);
    if (!strncmp(trace_message,"traces",6)) {
        /* strtok splitting input and storing all items, returning first item */
        array[0] = strtok(trace_message+7," ");
        if(array[0]==NULL) {return traceHelp();}

        /* retrieving all remaining items */
        for(loop=1;loop<50;loop++) {
            array[loop] = strtok(NULL," ");
            if(array[loop]==NULL) break;
        }
        nbArgs=loop;
        /*treatment of the buffer according to the output*/
        for(loop=0;loop<nbArgs;loop++) {
            if(!strcmp_nocase_n(array[loop],"help",4)) {
                /*print the help menu*/
                trace_configuration_message=1;
              /* display the trace help on stdout */
                return traceHelp();
            }
#if       SiTRACES_FEATURES == SiTRACES_FULL
            else if(!strcmp_nocase_n(array[loop],"erase"   ,5) ) {
                file = fopen(trace_file_name,"w");
                if(!file) {
                  trace_output_type=TRACE_MEMORY;
                  sprintf(trace_message,"traces can not be written to file %s, routing traces to memory.\n", trace_file_name);
                } else {
                sprintf(trace_message,"traces in %s erased.\n", trace_file_name);
                fclose(file);
              }
              return trace_message;
            }
            else if(!strcmp_nocase_n(array[loop],"save"    ,4) ) {
                /*save the trace buffer content in an extern file */
                file = fopen(trace_file_name,"a+");
              if(!file) {
                trace_output_type=TRACE_MEMORY;
                sprintf(trace_message,"traces can not be written to file %s, routing traces to memory.\n", trace_file_name);
              } else {
                if(trace_lost_traces) {fprintf(file,"\n[...lost traces : %4d...]\n",trace_lost_traces);}
                fprintf(file,"%s\n",trace_buffer);
                fclose(file);
              }
              return trace_message;
            }
            else if(!strcmp_nocase_n(array[loop],"show"    ,4) ) {
                /*print the buffer content on stdout*/
                if(trace_lost_traces) {
                    CUSTOM_PRINTF("[...lost traces : %4d...]\n",trace_lost_traces);
                    c=trace_buffer[SiTRACES_BUFFER_LENGTH-1];
                    trace_buffer[SiTRACES_BUFFER_LENGTH-1]='\0';
                    pBuffer+=strlen(trace_buffer)+1;
                    CUSTOM_PRINTF("%s",pBuffer);
                    if(c) {CUSTOM_PRINTF("%c",c);}
                    trace_buffer[SiTRACES_BUFFER_LENGTH-1]=c;
                 }
                CUSTOM_PRINTF("%s\n",trace_buffer);
                return (char *)"";
            }
            else if(!strcmp_nocase_n(array[loop],"-name"   ,5) ) {
                trace_configuration_message=1;
                if(!array[loop+1]) {
                  sprintf(trace_message,"%s\n", trace_file_name);
                  return trace_message;
                }
                else if(strlen(array[loop+1]) < 40) {
                    pArray = array[loop+1];
                    for (i=0;i<strlen(array[loop+1]);i++) {
                        trace_file_name[i] = *pArray;
                        pArray++;
                    }
                    trace_file_name[i] = 0x00;
                    trace_config_rename=1;
                    file = fopen(trace_file_name,"a+");
                    if(!file) CUSTOM_PRINTF("rename file operation failed");
                    else {
                        /*print the actual date and time */
                        time ( &rawtime );
                        timeinfo = localtime ( &rawtime );
                        strftime (trace_timer,50,"%A %B %d   %I:%M%p   %Y",timeinfo);
                        fprintf(file,"            SiTraceFunction log created on %s\n",trace_timer);
                        fclose(file);
                    }
                }
                else {CUSTOM_PRINTF("rename file operation failed");}
            }
#endif /* SiTRACES_FEATURES == SiTRACES_FULL */
            else if(!strcmp_nocase_n(array[loop],"-verbose",8) ) {
                trace_configuration_message=1;
                if((!strcmp_nocase_n(array[loop+1],"on" ,2)) || (!strncmp(array[loop+1],"1",1))) trace_config_verbose=1;
                if((!strcmp_nocase_n(array[loop+1],"off",3)) || (!strncmp(array[loop+1],"0",1))) trace_config_verbose=0;
            }
            else if(!strcmp_nocase_n(array[loop],"count"   ,5) ) {
                sprintf(trace_stockInt,"%d\n",trace_count);
                trace_count=0;
                return trace_stockInt;
            }
            else if(!strcmp_nocase_n(array[loop],"suspend" ,7) ) {
                trace_suspend = 1;
                sprintf(trace_stockInt,"%d\n",trace_suspend);
                return trace_stockInt;
            }
            else if(!strcmp_nocase_n(array[loop],"resume"  ,6) ) {
                trace_suspend=0;
                sprintf(trace_stockInt,"%d\n",trace_suspend);
                return trace_stockInt;
            }
            else if(!strcmp_nocase_n(array[loop],"lost"    ,4) ) {
                sprintf(trace_stockInt,"%d\n",trace_lost_traces);
                return trace_stockInt;
            }
            else if(!strcmp_nocase_n(array[loop],"flush"   ,5) ) {
                trace_configuration_message=1;
              /* empty the trace buffer */
                if(strlen(trace_buffer)) {traceFlushBuffer(trace_buffer);}
                return (char *)"traces memory flushed\n";
              }
            else if(!strcmp_nocase_n(array[loop],"get"     ,3) ) {
                /*reorder the trace buffer content and return a pointer on the trace buffer address*/
                if(trace_lost_traces) {
                     for (loop=0;loop<SiTRACES_BUFFER_LENGTH;loop++) {
                        origine = (destination - (SiTRACES_BUFFER_LENGTH - 1 - lenTraceBuffer) ) % SiTRACES_BUFFER_LENGTH;
                        if (destination < 0) {destination += SiTRACES_BUFFER_LENGTH;}
                        if (origine < 0) {origine += SiTRACES_BUFFER_LENGTH;}
                        if (origine == start) {
                            trace_buffer[destination] = saved;
                            destination = origine+1;
                            start = destination;
                            saved = trace_buffer[start];
            }
                        else {
                            trace_buffer[destination] = trace_buffer[origine];
                            destination = origine;
            }
            }
            }
                return trace_buffer;
            }
            else if(!strcmp_nocase_n(array[loop],"status"  ,6) ) {
                switch(trace_output_type) {
                    case TRACE_MEMORY      : sprintf(trace_message," -output memory " ); break;
                    case TRACE_STDOUT      : sprintf(trace_message," -output stdout " ); break;
#if       SiTRACES_FEATURES == SiTRACES_FULL
                    case TRACE_EXTERN_FILE : sprintf(trace_message," -output file "   ); break;
#endif /* SiTRACES_FEATURES == SiTRACES_FULL */
                    case TRACE_NONE        : sprintf(trace_message," -output none "   ); break;
                    default                : sprintf(trace_message," -output unknown "); break;
                 }
#if       SiTRACES_FEATURES == SiTRACES_FULL
                                             sprintf(trace_message,"%s -name %s "        , trace_message, trace_file_name);
#endif /* SiTRACES_FEATURES == SiTRACES_FULL */
                                             sprintf(trace_message,"%s-file "            , trace_message);
                if (trace_config_files    ) {sprintf(trace_message,"%s on "              , trace_message);}
                else {                       sprintf(trace_message,"%soff "              , trace_message);}
                                             sprintf(trace_message,"%s-line "            , trace_message);
                if (trace_config_lines    ) {sprintf(trace_message,"%s on "              , trace_message);}
                else {                       sprintf(trace_message,"%soff "              , trace_message);}
                                             sprintf(trace_message,"%s-function "        , trace_message);
                if (trace_config_functions) {sprintf(trace_message,"%s on "              , trace_message);}
                else {                       sprintf(trace_message,"%soff "              , trace_message);}
                                             sprintf(trace_message,"%s-time "            , trace_message);
                if (trace_config_time     ) {sprintf(trace_message,"%s on "              , trace_message);}
                else {                       sprintf(trace_message,"%soff "              , trace_message);}
                                             sprintf(trace_message,"%s-verbose "         , trace_message);
                if (trace_config_verbose  ) {sprintf(trace_message,"%s on "              , trace_message);}
                else {                       sprintf(trace_message,"%soff "              , trace_message);}
                sprintf(trace_message,"%s\n", trace_message);
                return trace_message;
            }
            else if(!strcmp_nocase_n(array[loop],"-output"  ,7) ) {
                trace_configuration_message=1;
                if (!strcmp_nocase_n(array[loop+1],"none"  ,4)) trace_output_type=TRACE_NONE;
                if (!strcmp_nocase_n(array[loop+1],"memory",6)) trace_output_type=TRACE_MEMORY;
                if (!strcmp_nocase_n(array[loop+1],"stdout",6)) trace_output_type=TRACE_STDOUT;
#if       SiTRACES_FEATURES == SiTRACES_FULL
                if (!strcmp_nocase_n(array[loop+1],"file"  ,4)) trace_output_type=TRACE_EXTERN_FILE;
#endif /* SiTRACES_FEATURES == SiTRACES_FULL */
            }
            else if(!strcmp_nocase_n(array[loop],"-file"    ,5) ) {
                trace_configuration_message=1;
                if((!strcmp_nocase_n(array[loop+1],"on" ,2)) || (!strncmp(array[loop+1],"1",1))) trace_config_files=1;
                if((!strcmp_nocase_n(array[loop+1],"off",3)) || (!strncmp(array[loop+1],"0",1))) trace_config_files=0;
            }
            else if(!strcmp_nocase_n(array[loop],"-line"    ,5) ) {
                trace_configuration_message=1;
                if((!strcmp_nocase_n(array[loop+1],"on" ,2)) || (!strncmp(array[loop+1],"1",1))) trace_config_lines=1;
                if((!strcmp_nocase_n(array[loop+1],"off",3)) || (!strncmp(array[loop+1],"0",1))) trace_config_lines=0;
            }
            else if(!strcmp_nocase_n(array[loop],"-function",9) ) {
                trace_configuration_message=1;
                if((!strcmp_nocase_n(array[loop+1],"on" ,2)) || (!strncmp(array[loop+1],"1",1))) trace_config_functions=1;
                if((!strcmp_nocase_n(array[loop+1],"off",3)) || (!strncmp(array[loop+1],"0",1))) trace_config_functions=0;
            }
            else if(!strcmp_nocase_n(array[loop],"-time"    ,5) ) {
                trace_configuration_message=1;
                if((!strcmp_nocase_n(array[loop+1],"on" ,2)) || (!strncmp(array[loop+1],"1",1))) trace_config_time=1;
                if((!strcmp_nocase_n(array[loop+1],"off",3)) || (!strncmp(array[loop+1],"0",1))) trace_config_time=0;
            }
        }
    }
    if (!trace_configuration_message) {
      trace_skip_info = 1;
      traceToDestination((char*)config+7);
      trace_skip_info = 0;
      return (char *)"";
    }
    return SiTraceConfiguration("traces status");
}
/************************************************************************************************************************
  SiTraceFunction function
  Use:        SiTRACES trace formatting function.
              It formats the trace message with file name and line number and time if selected
              then saves it to the trace output.
  Parameter:  name    the file name where the trace is written.
  Parameter:  number  the line number where the trace is written.
  Parameter:  fmt     string content of trace message. Others arguments are sent thanks to the ellipse.
  Returns:    void
  Porting:    Not compiled if SiTRACES is not defined in Silabs_L0_API.h.
************************************************************************************************************************/
void  SiTraceFunction        (const char *name, int number, const char *func, const char *fmt, ...) {
    char        message[1000];
    const char *pname;
    const char *pfunc;
    va_list     ap;
    if (trace_output_type == TRACE_NONE) return;
    /* print the line number in trace_linenumber */
    trace_linenumber = number;
    pname=name;

    /* print the file name in trace_source_file */
    if(strlen(pname)>SiTRACES_NAMESIZE) {
      pname+=strlen(pname)-SiTRACES_NAMESIZE;
    }
    strncpy(trace_source_file,pname,SiTRACES_NAMESIZE);

    /*print the function name in trace_source_function */
    pfunc=func;
    sprintf(trace_source_function,"%s","");
    if(strlen(pfunc)>SiTRACES_FUNCTION_NAMESIZE) {
      pfunc+=(strlen(pfunc)-SiTRACES_FUNCTION_NAMESIZE)+2;
      strcpy(trace_source_function,"..");
    }
    strncat(trace_source_function,pfunc,SiTRACES_FUNCTION_NAMESIZE-2);

    va_start(ap, fmt);
    vsprintf(message,fmt,ap);
    traceToDestination(message);
    va_end(ap);
    return;
}
#endif /* SiTRACES */
/************************************************************************************************************************
  strcmp_nocase function
  Use:        case-insensitive string comparison function
              Used to compare 2 strings without case sensitivity
  Comments:   As long as this function is only used for SiTRACES, it can be left in the TRACES code
  Returns:    0 if identical
************************************************************************************************************************/
#if 0
int  strcmp_nocase   (const char* str1, const char* str2) {
    size_t       l;
    unsigned int i;
    int       diff;
    l = strlen(str1);
    if (l != strlen(str2)) return 1;
    for (i=0;i<l;i++) {
        if (str1[i] != str2[i]) {
            diff = str1[i]-str2[i];
            if (diff < 0) {diff = - diff;}
            if (diff !=32) {
                return 2;
            } else {
                if ((((str1[i]+str2[i])/2) < 81) || (((str1[i]+str2[i])/2)>106))  return 3;
            }
        }
    }
    return 0;
}
/************************************************************************************************************************
  strcmp_nocase_n function
  Use:        case-insensitive string comparison function with size limit
              Used to compare 2 strings without case sensitivity, with a limit on the number of characters
  Comments:   As long as this function is only used for SiTRACES, it can be left in the TRACES code
  Returns:    0 if identical
************************************************************************************************************************/
int  strcmp_nocase_n (const char* str1, const char* str2, unsigned int n) {
    size_t       l;
    size_t       l1;
    size_t       l2;
    unsigned int i;
    int       diff;
    l1 = strlen(str1);
    l2 = strlen(str2);
    if (l1 < l2) {l = l1;} else {l = l2;};
    if (l  > n ) {l = n;}
    for (i=0;i<l;i++) {
        if (str1[i] != str2[i]) {
            diff = str1[i]-str2[i];
            if (diff < 0) {diff = - diff;}
            if (diff !=32) {
                return 2;
            } else {
                if ((((str1[i]+str2[i])/2) < 81) || (((str1[i]+str2[i])/2)>106))  return 3;
            }
        }
    }
    return 0;
}
int  L0_StoreError   (const char *message) {
  int length;
  int length_new_msg;
  length         = (int)strlen(stored_error_message);
  length_new_msg = (int)strlen(message);
  if ( (length + length_new_msg) >= ERROR_MESSAGE_MAX_LENGH ) {
    stored_error_message[ERROR_MESSAGE_MAX_LENGH-40] = 0x00;
    length = sprintf(stored_error_message, "%s%s", stored_error_message, "...There are lost errors...\n");
  } else {
    length = sprintf(stored_error_message, "%s%s", stored_error_message, message);
  }
  return length;
}
int  L0_ErrorMessage (void) {
  int length;
  length = sprintf(L0_error_message   , stored_error_message);
  sprintf(stored_error_message, "%s", "");
  return length;
}
#endif
/************************************************************************************************************************
  system_wait function
  Use:        current system wait function
              Used to wait for time_ms milliseconds while doing nothing
  Parameter:  time_ms the wait duration in milliseconds
  Returns:    The current system time in milliseconds
  Porting:    Needs to use the final system call for time retrieval
************************************************************************************************************************/
int     system_wait          (int time_ms) {
  int ticks1, ticks2;
  ticks1=system_time();
  ticks2=ticks1;
  /* <porting> Replace 'clock' by whatever is necessary to return the system time in milliseconds */
  while((ticks2-ticks1)<time_ms) {ticks2=system_time();}
  return (int)ticks2;
}
/************************************************************************************************************************
  system_time function
  Use:        current system time retrieval function
              Used to retrieve the current system time in milliseconds
  Returns:    The current system time in milliseconds
  Porting:    Needs to use the final system call
************************************************************************************************************************/
int     system_time          (void)        {
  /* <porting> Replace 'clock' by whatever is necessary to return the system time in milliseconds */
  return (int)MsOS_GetSystemTime();
}
int     L0_SimulatorRead     (int AdrSize, unsigned char * Adr, int ReadSize, unsigned char *Buffer) {
  int I2cIndex, relativeAdd, i;
  I2cIndex =0;
  for (i = 0; i < AdrSize; i++) {
    I2cIndex = (I2cIndex << 8) + Adr[i];
  }
  if (I2cIndex + ReadSize >= SIMULATOR_SCOPE) {
    CUSTOM_PRINTF("trying to access an address out of the simulator's scope !!");
    return 0;
  }
  for (relativeAdd = 0; relativeAdd < ReadSize; relativeAdd ++) {
    Buffer[relativeAdd]=Byte[I2cIndex + relativeAdd];
  }
  return ReadSize;
}
int     L0_SimulatorWrite    (int AdrSize, int BufSize, unsigned char * Buffer){
  int I2cIndex, relativeAdd, i;
  I2cIndex =0;
  for (i = 0; i < AdrSize; i++) {
    I2cIndex = (I2cIndex <<8) + Buffer[i];
  }
  if (I2cIndex + BufSize >= SIMULATOR_SCOPE) {
    CUSTOM_PRINTF("trying to access an address out of the simulator's scope !!");
    return 0;
  }
  for (relativeAdd = AdrSize; relativeAdd < BufSize; relativeAdd ++) {
     Byte[I2cIndex + relativeAdd -AdrSize] = Buffer[relativeAdd];
  }
  return BufSize;
}
/************************************************************************************************************************
  L0_Init function
  Use:        layer 0 initialization function
              Used to set the layer 0 context parameters to startup values.
              It must be called first and once per Layer 1 instance (i.e. once for the tuner and once for the demodulator).
              It is automatically called by the Layer 1 init function.
  Parameters: mustReadWithoutStop has been added to manage the case when some components do not allow a stop in a 'read'.
              i2c usually allows 'write 0xc8 0x01 0x02' followed by 'read 0xc9 1' to read the byte at index 0x0102.
              This should return the same data as 'read 0xc8 0x01 0x02 1'.
              If this is not allowed, set mustReadWithoutStop at 1.
              NB: at the date of writing, this behavior has only been detected in the RDA5812 satellite tuner.
  Returns:    void
  Porting:    If some members of the L0_Context structure are removed, they need to be removed from here too
************************************************************************************************************************/
void    L0_Init              (L0_Context *i2c) {
  int i;
  #ifdef    USB_Capability
  char rettxtBuffer[200];
  char *rettxt;
  double dval;
  rettxt = rettxtBuffer;
  #endif /* USB_Capability */

  pucAddressBuffer = (unsigned char *)&ucAddressBuffer;
  pucBuffer        = (unsigned char *)&ucBuffer;
  i2c->address             = 0;
  i2c->indexSize           = 0;
  i2c->connectionType      = CUSTOMER; //SIMU;
  i2c->trackWrite          = 0;
  i2c->trackRead           = 0;
  i2c->mustReadWithoutStop = 0;
  for (i=0; i<SIMULATOR_SCOPE; i++) {Byte[i]=0x00;}
  rawI2C = &rawI2C_context;
  rawI2C->indexSize = 0;
  stored_error_message = L0_error_buffer_0;
  L0_error_message     = L0_error_buffer_1;
  // sprintf(stored_error_message, "%s", "");
  #ifdef    USB_Capability
  if (!cypress_checks_done) {
    L0_Connect (i2c, USB);
    L0_Cypress_Process("dll_version", "", 0, &dval, &rettxt);
    SiTRACE("dll_version %s (recommended minimal version 10.23)\n", rettxt);
    L0_Cypress_Process("fw_version" , "", 0, &dval, &rettxt);
    SiTRACE("fw_version  %s (recommended minimal version 10.20)\n", rettxt);
    cypress_checks_done = 1;
  }
  #endif /* USB_Capability */
#ifdef    SiTRACES
  if (!trace_init_done) {
    CUSTOM_PRINTF("\n********** SiTRACES activated *********\nComment the '#define SiTRACES' line\nin Silabs_L0_API.h to de-activate all traces.\n\n");
    SiTraceDefaultConfiguration();
  }
#endif /* SiTRACES */
}
/************************************************************************************************************************
  L0_InterfaceType function
  Use:        function to return the communication mode string
              Used to display a clear text related to the communication mode.
  Returns:    the string correspopnding to the current connection mode
************************************************************************************************************************/
char*   L0_InterfaceType     (L0_Context* i2c) {
  switch (i2c->connectionType) {
  #ifdef USB_Capability
    case USB:
      return (char *)"USB";
      break;
  #endif /* USB_Capability */
    case SIMU:
      return (char *)"SIMU";
      break;
    case CUSTOMER:
      return (char *)"CUST";
      break;
    default:
      return (char *)"?";
      break;
   };
}
/************************************************************************************************************************
  L0_SetAddress function
  Use:        function to set the device address
              Used to set the I2C address of the component.
              It must be called only once at startup per Layer 1 instance, as the addresses are not expected to change over time.
  Returns:    1 if OK, 0 otherwise
************************************************************************************************************************/
int     L0_SetAddress        (L0_Context* i2c, unsigned int add, int addSize) {
  i2c->address   = add;
  i2c->indexSize = addSize;
  switch (i2c->connectionType) {
  #ifdef USB_Capability
    case USB:
      L0_Connect (i2c, i2c->connectionType);
      return 1;
      break;
  #endif /* USB_Capability */
    case SIMU:
      return 1;
      break;
    default:
      break;
   };
  return 0;
}
/************************************************************************************************************************
  L0_Connect function
  Use:        Core layer 0 connection function
              Used to switch between various connection modes
              If a single connection  mode is used, this function can be removed, and the corresponding calls from the Layer 1 code can be removed as well.
              It can be useful during SW development, to easily switch between the simulator and the actual HW.
  Returns:    1 if connected to actual hw
  Porting:    Depending on the i2c layer, this function could be removed if a single connection mode is allowed
************************************************************************************************************************/
int     L0_Connect           (L0_Context *i2c, CONNECTION_TYPE connType) {
  #ifdef    USB_Capability
  if (i2c->connectionType == USB) {
    Cypress_USB_Close();
  }
  #endif /* USB_Capability */
  switch (connType) {
    #ifdef    USB_Capability
    case USB:
      Cypress_USB_Open();
      i2c->connectionType =  USB;
      return 1;
      break;
    #endif /* USB_Capability */
    case CUSTOMER:
      i2c->connectionType =  CUSTOMER;
      return 1;
      break;
    default:
      i2c->connectionType =  SIMU;
      return 0;
    break;
  };
  return 0;
}
/************************************************************************************************************************
  L0_TrackRead function
  Use:        layer 0 initialization function
              Used to toggle the read traces for the related Layer 1 instance.
              It is useful for debug purpose, mostly to control that data is properly transmitted to the above layers.
  Returns:    void
************************************************************************************************************************/
void    L0_TrackRead         (L0_Context* i2c, unsigned int track) {
  i2c->trackRead  = track;
}
/************************************************************************************************************************
  L0_TrackWrite function
  Use:        layer 0 initialization function
              Used to toggle the write traces for the related Layer 1 instance.
              It is useful for debug purpose, mostly to control that data is properly written to the desired Layer 1 instance.
  Returns:    void
************************************************************************************************************************/
void    L0_TrackWrite        (L0_Context* i2c, unsigned int track) {
  i2c->trackWrite = track;
}
/************************************************************************************************************************
  L0_ReadBytes function
  Use:        lowest layer read function
              Used to read a given number of bytes from the Layer 1 instance.
  Parameters: i2c, a pointer to the Layer 0 context.
              iI2CIndex, the index of the first byte to read.
              iNbBytes, the number of bytes to read.
              *pbtDataBuffer, a pointer to a buffer used to store the bytes.
  Returns:    the number of bytes read.
  Porting:    If a single connection mode is allowed, the entire switch can be replaced by a call to the final i2c read function
************************************************************************************************************************/
int     L0_ReadBytes         (L0_Context* i2c, unsigned int iI2CIndex, int iNbBytes, unsigned char *pucDataBuffer) {
  int r,i,nbReadBytes;
  nbReadBytes = 0;
  for (i=0;i<i2c->indexSize;i++) {
    r = 8*(i2c->indexSize -1 -i);
    pucAddressBuffer[i] = (unsigned char)((iI2CIndex & (0xff<<r) ) >> r);
  }
  switch (i2c->connectionType) {
#ifdef    USB_Capability
    case USB:
      if (RET_OK == Cypress_USB_ReadI2C(i2c->address>>1, i2c->indexSize, pucAddressBuffer, iNbBytes, pucDataBuffer)) {
        nbReadBytes = iNbBytes;
      }
      break;
#endif /* USB_Capability */
    case CUSTOMER:
      if (SI215X_ucI2cReadOnly(i2c->address,pucDataBuffer,iNbBytes) == 0)
      {
          nbReadBytes = iNbBytes;
      }
      else
      {
          mcSHOW_HW_MSG(("[Silabs]:<= I2C Read Error\n"));
      }
	  
      mcSHOW_DBG_MSG4(("SI215X_ucI2cReadOnly:i2c->address =%x;iNbBytes=%d\n",i2c->address,iNbBytes));
      for(i=0;i<iNbBytes;i++)
       {mcSHOW_DBG_MSG4(("pucDataBuffer[%x]\n",pucDataBuffer[i]));}
	  
      break;
    case SIMU:
      nbReadBytes = L0_SimulatorRead (i2c->indexSize, pucAddressBuffer, iNbBytes, pucDataBuffer);
      break;
    default:
      break;
  }
#ifdef    SiTRACES
  trace_skip_info = 1;
    if (i2c->trackRead==1) {
    sprintf(trace_L0_message, "reading 0x%02x ",i2c->address + 1);
    if (i2c->indexSize) {
      sprintf(trace_L0_message, "%sat", trace_L0_message);
      for (i=0;i<i2c->indexSize;i++) {
        r = 8*(i2c->indexSize -1 -i);
        sprintf(trace_L0_message, "%s 0x%02x", trace_L0_message, ((iI2CIndex & (0xff<<r))>> r)&0xff );
      }
    }
    sprintf(trace_L0_message, "%s <%s", trace_L0_message, L0_InterfaceType(i2c));
    if (nbReadBytes != iNbBytes) {sprintf(trace_L0_message, "%s READ  ERROR!", trace_L0_message);}
    for ( i=0 ; i < nbReadBytes ; i++ ) {  sprintf(trace_L0_message, "%s 0x%02x" ,trace_L0_message , (pucDataBuffer)[i]); }
    SiTRACE("%s\n", trace_L0_message);
    }
    trace_skip_info = 0;
#endif /* SiTRACES */
    return nbReadBytes;
}
/************************************************************************************************************************
  L0_WriteBytes function
  Use:        lowest layer write function
              Used to write a given number of bytes from the Layer 1 instance.
  Parameters: i2c, a pointer to the Layer 0 context.
              iI2CIndex, the index of the first byte to write.
              iNbBytes, the number of bytes to write.
              *pbtDataBuffer, a pointer to a buffer containing the bytes to write.
  Returns:    the number of bytes read.
  Porting:    If a single connection mode is allowed, the entire switch can be replaced by a call to the final i2c write function
************************************************************************************************************************/
int     L0_WriteBytes        (L0_Context* i2c, unsigned int iI2CIndex, int iNbBytes, unsigned char *pucDataBuffer) {
  int r, i, nbWrittenBytes, write_error;
  nbWrittenBytes = 0;
  write_error    = 0;
  for (i=0; i <i2c->indexSize;i++) {
    r = 8*(i2c->indexSize -1 -i);
    pucBuffer[i] = (unsigned char)((iI2CIndex & (0xff<<r) ) >> r);
    pucAddressBuffer[i] = pucBuffer[i];
  }
  for (i=0; i < iNbBytes ;    i++) {
    pucBuffer[i+i2c->indexSize] = pucDataBuffer[i];
  }
  switch (i2c->connectionType) {
#ifdef    USB_Capability
    case USB:
      pucDataBuffer = &pucBuffer[i2c->indexSize];
      if (RET_OK == Cypress_USB_WriteI2C (i2c->address>>1, i2c->indexSize, pucAddressBuffer, iNbBytes, pucDataBuffer)) {
        nbWrittenBytes = iNbBytes + i2c->indexSize;
      } else {
        write_error++;
      }
      break;
#endif /* USB_Capability */
    case CUSTOMER:
	  if (SI215X_ucI2cWriteOnly(i2c->address,pucDataBuffer,iNbBytes) == 0)
      {
          nbWrittenBytes = iNbBytes + i2c->indexSize;
      }
      else
	  {
          write_error++;
		  mcSHOW_HW_MSG(("[Silabs]:<= I2C Write Error\n"));
	  }

	  mcSHOW_DBG_MSG4(("SI215X_ucI2cWriteOnly:i2c->address =%x;iI2CIndex=%x;iNbBytes=%d\n",i2c->address,iI2CIndex,iNbBytes));
	  for(i=0;i<iNbBytes;i++)
		  { mcSHOW_DBG_MSG4(("pucDataBuffer[%x]\n",pucDataBuffer[i]));}

        break;
    case SIMU:
      nbWrittenBytes = L0_SimulatorWrite(i2c->indexSize, (iNbBytes + i2c->indexSize), pucBuffer);
      break;
    default:
      break;
  }
#ifdef    SiTRACES
  trace_skip_info = 1;
  if (i2c->trackWrite     == 1) {
    sprintf(trace_L0_message, "writing 0x%02x ",i2c->address);
    if (i2c->indexSize) {
      sprintf(trace_L0_message, "%sat", trace_L0_message);
      for (i=0;i<i2c->indexSize;i++) {
        r = 8*(i2c->indexSize -1 -i);
        if (i2c->indexSize) sprintf(trace_L0_message, "%s 0x%02x", trace_L0_message, ((iI2CIndex & (0xff<<r))>> r)&0xff );
      }
    }
    sprintf(trace_L0_message, "%s %s>", trace_L0_message, L0_InterfaceType(i2c));
    if (write_error) { sprintf(trace_L0_message, "%s WRITE ERROR! (", trace_L0_message); }
      for ( i=0 ; i < iNbBytes ; i++ ) {
      sprintf(trace_L0_message, "%s 0x%02x", trace_L0_message, pucDataBuffer[i]);
      }
    if (write_error) { sprintf(trace_L0_message, "%s )", trace_L0_message); }
    SiTRACE("%s\n", trace_L0_message);
  }
  trace_skip_info = 0;
#endif /* SiTRACES */
  if (write_error) return 0;
  return nbWrittenBytes - i2c->indexSize;
}
/************************************************************************************************************************
  L0_ReadCommandBytes function
  Use:        'command mode' bytes reading function
              Used to read a given number of bytes from the Layer 1 instance in 'command mode'.
  Comment:    The 'command mode' is a specific mode where the indexSize is always 0 and the index is always 0x00
  Parameters: i2c, a pointer to the Layer 0 context.
              iNbBytes, the number of bytes to read.
              *pucDataBuffer, a pointer to a buffer used to store the bytes.
  Returns:    the number of bytes read.
************************************************************************************************************************/
int     L0_ReadCommandBytes  (L0_Context* i2c, int iNbBytes, unsigned char *pucDataBuffer) {
  return L0_ReadBytes (i2c, 0x00, iNbBytes, pucDataBuffer);}
/************************************************************************************************************************
  L0_WriteCommandBytes function
  Use:        'command mode' bytes writing function
              Used to write a given number of bytes to the Layer 1 instance in 'command mode'.
  Comment:    The 'command mode' is a specific mode where the indexSize is always 0 and the index is always 0x00
  Parameters: i2c, a pointer to the Layer 0 context.
              iNbBytes, the number of bytes to write.
              *pucDataBuffer, a pointer to a buffer containing the bytes.
  Returns:    the number of bytes written.
************************************************************************************************************************/
int     L0_WriteCommandBytes (L0_Context* i2c, int iNbBytes, unsigned char *pucDataBuffer) {
  return L0_WriteBytes(i2c, 0x00, iNbBytes, pucDataBuffer);}
/************************************************************************************************************************
  L0_ReadRawBytes function
  Use:        raw i2c read function
              Used to read a given number of bytes from the Layer 1 instance while managing the indexSize at this level.
  Parameters: i2c, a pointer to the Layer 0 context.
              iI2CIndex, the index of the first byte to read.
              iNbBytes, the number of bytes to read.
              *pbtDataBuffer, a pointer to a buffer used to store the bytes.
  Comment:    This function splits a 'read' operation in
              1- 'writing' the chip's i2c adress plus the index bytes
              2- 'reading' iNbBytes bytes from the chip
  Porting:    Can be used to manage the 16 bit case at this level
  Returns:    the number of bytes read.
************************************************************************************************************************/
int     L0_ReadRawBytes      (L0_Context* i2c, unsigned int iI2CIndex, int iNbBytes, unsigned char *pbtDataBuffer) {
  int i,r,ret;
  unsigned char pbtIndexBuffer [2];
  rawI2C->address        = i2c->address;
  rawI2C->trackRead      = i2c->trackRead;
  rawI2C->trackWrite     = i2c->trackWrite;
  rawI2C->connectionType = i2c->connectionType;
  if (i2c->indexSize >0) {
    for (i=0;i<i2c->indexSize;i++) {
      r = 8*(i2c->indexSize -1 -i);
      pbtIndexBuffer[i] = (unsigned char)((iI2CIndex & (0xff<<r) ) >> r);
    }
    /* First write the index bytes (if any) */
    ret = L0_WriteBytes(rawI2C, 0, i2c->indexSize, pbtIndexBuffer);
    if (ret == 0) return 0; /* There has been a communication error, do not attempt to read */
  }
  /* Now read the data bytes */
  ret = L0_ReadBytes (rawI2C, 0, iNbBytes, pbtDataBuffer);
  return ret;
}
/************************************************************************************************************************
  L0_WriteRawBytes function
  Use:        raw i2c write function
              Used to write a given number of bytes from the Layer 1 instance while managing the indexSize at this level.
  Parameters: i2c, a pointer to the Layer 0 context.
              iI2CIndex, the index of the first byte to write.
              iNbBytes, the number of bytes to write.
              *pbtDataBuffer, a pointer to a buffer containing the bytes.
  Porting:    Can be used to manage the 16 bit case at this level
  Returns:    the number of bytes written.
************************************************************************************************************************/
int     L0_WriteRawBytes     (L0_Context* i2c, unsigned int iI2CIndex, int iNbBytes, unsigned char *pbtDataBuffer) {
  int i,r,ret;
  unsigned char *pbtBuffer;
  rawI2C->address        = i2c->address;
  rawI2C->trackRead      = i2c->trackRead;
  rawI2C->trackWrite     = i2c->trackWrite;
  rawI2C->connectionType = i2c->connectionType;
  pbtBuffer = (unsigned char*) malloc((iNbBytes + i2c->indexSize)*sizeof(unsigned char));
  /* Store the index bytes in the first bytes of the write buffer */
  for (i=0;i<i2c->indexSize;i++) {
      r = 8*(i2c->indexSize -1 -i);
      pbtBuffer [i] = (unsigned char)((iI2CIndex & (0xff<<r) ) >> r);
  }
  /* Store the data bytes following the index bytes */
  for (i=i2c->indexSize; i< i2c->indexSize+iNbBytes;i++) {
      pbtBuffer[i] = pbtDataBuffer[i - i2c->indexSize];
  }
  /* Write all bytes as a single buffer */
  ret = L0_WriteBytes (rawI2C, 0, iNbBytes + i2c->indexSize, pbtBuffer) - i2c->indexSize;
  free(pbtBuffer);
  return ret;
}
/************************************************************************************************************************
  L0_ReadRegister function
  Use:        register read function
              Used to read a register based on its address, size, offset
  Parameter:  add              register address
  Parameter:  offset           register offset
  Parameter:  nbbit            register size in bits
  Parameter:  isSigned         register sign info
  Behavior:          This function uses the characteristics of the register to read its value from hardware
                       it reads the minimum number of bytes required to retrieve the register based on the number of bits and the offset
                       it masks all bits not belonging to the register before returning
                       it handles the sign-bit propagation for signed registers
  Returns: the value read. O if error during the read
************************************************************************************************************************/
long    L0_ReadRegister      (L0_Context *i2c, unsigned int iI2CIndex, unsigned char offset, unsigned char nbbit, unsigned int isSigned) {
  int iNbBytes, i, nbReadBytes, iNbPrefixBitsToCancel;
  long iVal;
  unsigned char  prefixByte, postfixByte;
  iNbBytes = (nbbit + offset + 7)/8;
  iVal = 0;

  if (i2c->mustReadWithoutStop==0) {
    nbReadBytes = L0_ReadRawBytes(i2c    , iI2CIndex, iNbBytes, registerDataBuffer);
  } else {
    nbReadBytes = L0_ReadBytes   (i2c    , iI2CIndex, iNbBytes, registerDataBuffer);
  }

  if (nbReadBytes != iNbBytes) {
    return 0;
  }

  for (i = 0; i < iNbBytes; i++) {iVal = iVal + ( registerDataBuffer[i] << (8*(i)));}

  prefixByte  = registerDataBuffer[iNbBytes - 1];
  iNbPrefixBitsToCancel = 8*(iNbBytes) - nbbit - offset;
  prefixByte  = prefixByte  >> (8 - iNbPrefixBitsToCancel);
  prefixByte  = prefixByte  << (8 - iNbPrefixBitsToCancel);
  postfixByte = registerDataBuffer[0];
  postfixByte = postfixByte << (8 - offset);
  postfixByte = postfixByte >> (8 - offset);

  iVal = -( prefixByte << (8*(iNbBytes - 1))) + ( iVal ) - postfixByte ;

  /* sign bit propagation, if required */
  if (isSigned) {
    iVal = (long)iVal >> offset;
    iVal = (long)iVal << (32-nbbit);
    iVal = (long)iVal >> (32-nbbit);
  } else {
    iVal = (unsigned long)iVal >> offset;
  }

  return iVal;
}
/************************************************************************************************************************
  L0_WriteRegister function
  Use:        register write function
              Used to write a register based on its address, size, offset
  Parameter:  add              register address
  Parameter:  offset           register offset
  Parameter:  nbbit            register size in bits
  Parameter:  alone            register loneliness info (1 if all other bits can be overwritten without checking)
  Parameter:  Value            the required value for the register
  Behavior:          This function uses all characteristics of the register to write its value in the hardware
                       if the required value is out of range, no operation is performed and an error code is returned
                       before writing, the current register value is retrieved (if required because of adjacent registers),
                          in order to preserve the contain of adjacent registers
                       it reads the minimum number of bytes required to retrieve the register based on:
                          the number of bits and the offset
                       it keeps all bits not belonging to the register intact
                       it handles the sign-bit propagation for signed registers
  Returns: the value written. O if error during the write
************************************************************************************************************************/
long    L0_WriteRegister     (L0_Context *i2c, unsigned int iI2CIndex, unsigned char offset, unsigned char nbbit, unsigned char alone, long Value) {
  unsigned int  iNbBytes, i,nbWrittenBytes, iNbPrefixBitsToCancel, nbReadBytes;
  unsigned long iVal;
  unsigned char prefixByte, postfixByte;
  iNbBytes = (nbbit + offset + 7)/8;
  iNbPrefixBitsToCancel = 8*(iNbBytes) - nbbit - offset;
  /* removing sign-propagation bits for negative values of signed registers */
  Value = (unsigned long)Value << iNbPrefixBitsToCancel;
  Value = (unsigned long)Value >> iNbPrefixBitsToCancel;
  if (((iNbBytes*8 == nbbit) && (offset == 0)) || ((alone == 1))) {
    /*  If the register is the only one using the related bytes, do not read it before setting bits */
    iVal = (unsigned long)Value << offset;
  } else {
    /*  If the bytes are used by other registers, read them before setting register-specific bits */
    if (i2c->mustReadWithoutStop==0) {
      nbReadBytes = L0_ReadRawBytes(i2c    , iI2CIndex, iNbBytes, registerDataBuffer);
    } else {
      nbReadBytes = L0_ReadBytes   (i2c    , iI2CIndex, iNbBytes, registerDataBuffer);
    }

    if (nbReadBytes != iNbBytes) { return 0; }

    prefixByte  = registerDataBuffer[iNbBytes-1];
    prefixByte  = prefixByte  >> (8 - iNbPrefixBitsToCancel);
    prefixByte  = prefixByte  << (8 - iNbPrefixBitsToCancel);

    postfixByte = registerDataBuffer[0];
    postfixByte = postfixByte << (8 - offset);
    postfixByte = postfixByte >> (8 - offset);

    iVal = ( prefixByte << (8*(iNbBytes - 1))) + ( (unsigned long)Value << offset ) + postfixByte ;
  }

  for (i = 0 ; i < iNbBytes; i++ ) {registerDataBuffer[i] = (unsigned char)(iVal >> 8*(i));}

  nbWrittenBytes = L0_WriteBytes(i2c, iI2CIndex, iNbBytes, registerDataBuffer);

  if (nbWrittenBytes != iNbBytes) {SiTRACE("nbWrittenBytes != iNbBytes\n"); return 0;}
  return Value;
}
/************************************************************************************************************************
  L0_ReadRegisterTrace function
  Use:         trace and read function
               Used to read a register based on its address, size, offset, with traces
  Parameter:    add              register address
  Parameter:    offset           register offset
  Parameter:    nbbit            register size in bits
  Behavior:          This function traces the register information, then calls L1_ReadRegister with all the register parameters
                     It is used only when tracing register reads is required
  Comments: generally activated by changing the definition of the CONTEXT_READ function in the proper header file
  Returns: the value written. O if error during the write
************************************************************************************************************************/
long    L0_ReadRegisterTrace (L0_Context *i2c, char* name, unsigned int iI2CIndex, unsigned char offset, unsigned char nbbit, unsigned int isSigned) {
  long res = L0_ReadRegister (i2c, iI2CIndex, offset, nbbit, isSigned);
  unsigned int iNbBytes;
#ifdef    SiTRACES
  trace_skip_info = 1;
  iNbBytes = (nbbit + offset + 7)/8;
  sprintf(trace_L0_message, " << READ  %-30s       : %4ld (0x%04lx)", name, res, res);
  sprintf(trace_L0_message, "%s  @[0x%0x:%d", trace_L0_message, iI2CIndex+iNbBytes-1, (offset+nbbit-1)%8);
    if (iNbBytes == 1) {
     if (nbbit ==1) { sprintf(trace_L0_message, "%s]\n", trace_L0_message);
     } else         { sprintf(trace_L0_message, "%s-%d]\n", trace_L0_message, offset);
       }
  } else            { sprintf(trace_L0_message, "%s]-[0x%0x:%d]\n", trace_L0_message, iI2CIndex, offset);}
  SiTRACE("%s",trace_L0_message);
  trace_skip_info = 0;
#else
  name = name; /*to avoid compiler warning */
#endif /* SiTRACES */
  iNbBytes = (nbbit + offset + 7)/8;
    return res;
}
/************************************************************************************************************************
  L0_WriteRegisterTrace function
  Use:        register write and trace function
              Used to write a register based on its address, size, offset, with traces
  Parameter:  add              register address
  Parameter:  offset           register offset
  Parameter:  nbbit            register size in bits
  Parameter:  alone            register loneliness info (1 if all other bits can be overwritten without checking)
  Parameter:  Value            the required value for the register
  Behavior:          This function traces the register information, then calls L1_WriteRegister with all the register parameters
                     It is used only when tracing register writes is required
  Comments: generally activated by changing the definition of the CONTEXT_WRITE function in the proper header file
  Returns: the value written. O if error during the write
************************************************************************************************************************/
long    L0_WriteRegisterTrace(L0_Context *i2c, char* name, char* valtxt, unsigned int iI2CIndex, unsigned char offset, unsigned char nbbit, unsigned char alone, long Value) {
  unsigned int iNbBytes;
  long res;
  iNbBytes = (nbbit + offset + 7)/8;
#ifdef    SiTRACES
  trace_skip_info = 1;
  sprintf(trace_L0_message, " >> WRITE %-20s %-25s : %ld (0x%04x)", name, valtxt, Value, (int)Value);
  sprintf(trace_L0_message, "%s  @[0x%0x:%d", trace_L0_message, iI2CIndex+iNbBytes-1, (offset+nbbit-1)%8);
  if (iNbBytes == 1) {
      if (nbbit ==1) { sprintf(trace_L0_message, "%s]\n", trace_L0_message);
      } else         { sprintf(trace_L0_message, "%s-%d]\n", trace_L0_message, offset);
      }
  } else             { sprintf(trace_L0_message, "%s]-[0x%0x:%d]\n", trace_L0_message, iI2CIndex, offset); }
  SiTRACE("%s",trace_L0_message);
  trace_skip_info = 0;
#else
  name   = name;   /*to avoid compiler warning */
  valtxt = valtxt; /*to avoid compiler warning */
#endif /* SiTRACES */
  res = L0_WriteRegister (i2c, iI2CIndex, offset, nbbit, alone, Value);
  return res;
}
/************************************************************************************************************************
  L0_ReadString function
  Use:        L0 generic read function
              Used to read bytes based on a string input
  Behavior:   Split the input string in tokens (separated by 'space') and read the corresponding bytes
              The chip address is the first byte
              The number of bytes to read is equal to the last token
              The index size if the number of tokens - 2
  Example:    'L0_ReadString (i2c, "0xC8 0x12 0x34 5", pbtDataBuffer);' will read 5 bytes from the chip at address 0xc8 starting from index 0x1234
               0xC8 0x12 0x34  5
                |   ---------  |
                |       |      ----> 5 bytes to read
                |       -----------> index 0x1234 (on 2 bytes)
                -------------------> address = 0xc8
  Example:    'L0_ReadString (i2c, "0xA0 0x00 5"     , pbtDataBuffer);' will read 5 bytes from the chip at address 0xA0 starting from index 0x00 (This will return the content of the Cypress eeprom)
  Example:    'L0_ReadString (i2c, "0xC0 1"          , pbtDataBuffer);' will read 1 byte  from the chip at address 0xC0 (This will return the status byte for a command-mode chip)
  Returns:    The number of bytes written
************************************************************************************************************************/
int     L0_ReadString        (L0_Context* i2c, char *readString, unsigned char *pbtDataBuffer) {
    int i;
    int readBytes;
    int loop;
    int nbArgs;
    int indexSize;
    unsigned int address;
    unsigned int uintval = 0;
    unsigned int hexval = 0;
    char *input;
    char *array[50];
    int   bytes[50];
    unsigned int   iI2CIndex;
    int            iNbBytes;

    UNUSED(uintval);
    UNUSED(hexval);

    if (pbtDataBuffer == NULL) {
     SiTRACE("L0_ReadString can not store bytes in NULL buffer!\n");
     return 0;
    }

    input = readString;

    /* strtok splitting input and storing all items, returning first item */
    array[0] = strtok(input," ");
    if(array[0]==NULL) {return 0;}
    /* retrieving all remaining items */
    for(loop=1;loop<50;loop++) {
        array[loop] = strtok(NULL," ");
        if(array[loop]==NULL) break;
    }
    nbArgs = loop;
    /* scanning arguments, allowing decimal or hexadecimal input */
#if 0 // warning...  
    for(loop=0;loop<nbArgs;loop++) {
        hexval=0;
        sscanf(array[loop],"%u", &uintval);
        if (!uintval) sscanf(array[loop],"%x", &hexval);
        bytes[loop] = hexval + uintval;
    }
#endif
    address   = bytes[0];
    indexSize = nbArgs - 2;
    if (indexSize <0) return 0;
    iI2CIndex = 0;
    for (i=1; i<= indexSize; i++) {
      iI2CIndex = (iI2CIndex<<8) + bytes[i];
    }
    iNbBytes  = bytes[loop-1];

    L0_SetAddress   (i2c, address, indexSize);

/*    SiTRACE("L0_ReadString address 0x%02x, index 0x%02x (on %d bytes), %d bytes\n", address, iI2CIndex, indexSize, iNbBytes); */

    readBytes = L0_ReadBytes (i2c, iI2CIndex, iNbBytes, pbtDataBuffer);

    return readBytes;
}
/************************************************************************************************************************
  L0_WriteString function
  Use:        L0 generic write function
              Used to write bytes based on a string input
  Behavior:   Split the input string in tokens (separated by 'space') and write the corresponding bytes
              The chip address is the first byte
              The number of bytes to write is equal to the number of tokens -1
  Example:    'L0_WriteString (i2c, "0xC8 0x12 0x34 0x37");' will write '0x37' at index 0x1234 in the chip at address 0xc8
  Returns:    The number of bytes written
************************************************************************************************************************/
int     L0_WriteString       (L0_Context* i2c, char *writeString) {
    int i;
    int writeBytes;
    int loop;
    int nbArgs;
    int indexSize;
    unsigned int address;
    unsigned int uintval = 0;
    unsigned int hexval = 0;
    char *input;
    char *array[50];
    int  bytes[50];
    unsigned int iI2CIndex;
    int iNbBytes;
//    unsigned char ucBuffer[100];
    unsigned char *pbtDataBuffer;

    pbtDataBuffer = (unsigned char*)&ucBuffer;

    input = writeString;

    UNUSED(uintval);
    UNUSED(hexval);

    /* strtok splitting input and storing all items, returning first item */
    array[0] = strtok(input," ");
    if(array[0]==NULL) {return 0;}
    /* retrieving all remaining items */
    for(loop=1;loop<50;loop++) {
        array[loop] = strtok(NULL," ");
        if(array[loop]==NULL) break;
    }
    nbArgs = loop;
    /* scanning arguments, allowing decimal or hexadecimal input */
#if 0  // warning...    
    for(loop=0;loop<nbArgs;loop++) {
        hexval=0;
        sscanf(array[loop],"%u", &uintval);
        if (!uintval) sscanf(array[loop],"%x", &hexval);
        bytes[loop] = hexval + uintval;
    }
#endif
    address   = bytes[0];
    indexSize = 0;
    if (indexSize <0) return 0;
    iI2CIndex = 0;
    iNbBytes  = nbArgs-1;
    pbtDataBuffer = (unsigned char*)malloc(sizeof(unsigned char)*iNbBytes);
    for (i=0; i<iNbBytes; i++) { pbtDataBuffer[i] = bytes[i+1]; }
    L0_SetAddress   (i2c, address, indexSize);
    writeBytes = L0_WriteBytes (i2c, iI2CIndex, iNbBytes, pbtDataBuffer);
    return writeBytes;
}
char*   Si_I2C_TAG_TEXT  (void) { return (char *)"ROM40_0_A_build_10_V0.2"; }
/************************************************************************************************************************
  L0_FastI2C  function
  Use:        function to set the i2c speed
              Used to set the speed of the i2c interface to 'fast'
              The initial version only manages the Cypress Interface chip, which has only 2 possible speeds
  Returns:    1
************************************************************************************************************************/
int     L0_FastI2C           (void) {
#ifdef    USB_Capability
  double        retdval;
  char rettxtBuffer[256];
  char *rettxt;
  rettxt = rettxtBuffer;
  Cypress_Configure((char*)"-i2c" ,(char*)"400khz", 0 , &retdval, &rettxt);
#endif /* USB_Capability */
  return 1;
}
/************************************************************************************************************************
  L0_SlowI2C  function
  Use:        function to set the i2c speed
              Used to set the speed of the i2c interface to 'slow'
              The initial version only manages the Cypress Interface chip, which has only 2 possible speeds
  Returns:    1
************************************************************************************************************************/
int     L0_SlowI2C           (void) {
#ifdef    USB_Capability
  double        retdval;
  char rettxtBuffer[256];
  char *rettxt;
  rettxt = rettxtBuffer;
  Cypress_Configure((char*)"-i2c" ,(char*)"100khz", 0 , &retdval, &rettxt);
#endif /* USB_Capability */
  return 1;
}

#ifdef    USB_Capability
/************************************************************************************************************************
  L0_Cypress_Process function
  Use:        Cypress chip command channel function
              Used to send a generic command to the Cypress chip.
  Comment:    The cypress chip commands are defined in the underlying Cypress USB dll, and are not relevant to non-Windows cases or when the i2c layer is not using the Cypress chip (after porting).
  Returns:    1 if the command is unknow
  Porting:    If not using the Cypress Fx2LP USB interface, comment the USB_Capability flag to avoid compiling this function
************************************************************************************************************************/
int     L0_Cypress_Process   (const char *cmd, const char *text, double dval, double *retdval, char **rettxt) {
  sprintf(*rettxt, "returning from the '%s' command",cmd);
  return Cypress_USB_Command ((char*)cmd, (char*)text, dval, retdval, rettxt);
}
/************************************************************************************************************************
  L0_Cypress_Configure function
  Use:        Cypress chip configuration function
              Used to send a configuration command to the Cypress chip.
  Comment:    The cypress chip commands are defined in the underlying Cypress USB dll, and are not relevant to non-Windows cases or when the i2c layer is not using the Cypress chip (after porting).
  Returns:    1 if the command is unknow
  Porting:    If not using the Cypress Fx2LP USB interface, comment the USB_Capability flag to avoid compiling this function
************************************************************************************************************************/
int     L0_Cypress_Configure (const char *cmd, const char *text, double dval, double *retdval, char **rettxt) {
  sprintf(*rettxt, "returning from the '%s' command",cmd);
  Cypress_Configure ((char*)cmd, (char*)text, dval, retdval,rettxt);
  return 1;
}
/************************************************************************************************************************
  L0_Cypress_Cget function
  Use:        Cypress chip configuration retrieval function
              Used to send a configuration info request to the Cypress chip.
  Comment:    The cypress chip commands are defined in the underlying Cypress USB dll, and are not relevant to non-Windows cases or when the i2c layer is not using the Cypress chip (after porting).
  Returns:    1 if the command is unknow
  Porting:    If not using the Cypress Fx2LP USB interface, comment the USB_Capability flag to avoid compiling this function
************************************************************************************************************************/
int     L0_Cypress_Cget      (const char *cmd, const char *text, double dval, double *retdval, char **rettxt) {
  sprintf(*rettxt, "returning from the '%s' command",cmd);
  Cypress_Cget ((char*)cmd, (char*)text, dval, retdval,rettxt);
  return 1;
}
#endif /* USB_Capability */
#ifdef    __cplusplus
}
#endif /* __cplusplus */
