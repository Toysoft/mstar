/* ----------------------------------------------------------------------------
 File Name: Hdic2311.h

 Description:

 Version 1.0 : Created   2012.03.21  Sharp Wang
  			 2.0 ��Modified  2013.03.05  Sharp Wang	 

 ---------------------------------------------------------------------------- */ 

enum
{
	HDIC_NO_ERROR = 0,				/* no error */
	HDIC_OTHER_ERROR					/* other error*/
};

enum
{
	HDIC2311_CABLE_16QAM,			/*Cable Mode, 16QAM*/
	HDIC2311_CABLE_32QAM,			/*Cable Mode, 32QAM*/
	HDIC2311_CABLE_64QAM,			/*Cable Mode, 64QAM*/
	HDIC2311_CABLE_128QAM,		/*Cable Mode, 128QAM*/
	HDIC2311_CABLE_256QAM			/*Cable Mode, 256QAM*/
};

enum
{
	HDIC2311_DTMB_SELECT,			/*WorkMode, DTMB*/
	HDIC2311_CABLE_SELECT 		/*WorkMode, Cable*/
};

enum
{
	HDIC2311_CRYSTAL_27M,			/*CrystalSelect, 27MHz*/
	HDIC2311_CRYSTAL_304M,		/*CrystalSelect, 30.4MHz*/
	HDIC2311_CRYSTAL_24M,			/*CrystalSelect, 24MHz*/
	HDIC2311_CRYSTAL_16M			/*CrystalSelect, 16MHz*/
};

enum
{
	HDIC_TUNER_NORMAL,				/*TunerType, Normal IF*/
	HDIC_TUNER_ZERO_IF				/*TunerType, Zero IF*/
};

enum
{
	HDIC_DTMB_4QAM_NR,				/*DTMB Mode, 4QAM NR*/
	HDIC_DTMB_4QAM,						/*DTMB Mode, 4QAM*/
	HDIC_DTMB_16QAM,					/*DTMB Mode, 16QAM*/	
	HDIC_DTMB_32QAM,					/*DTMB Mode, 32QAM*/
	HDIC_DTMB_64QAM						/*DTMB Mode, 64QAM*/
};

enum
{
	HDIC_PN_VARIABLE,				/*����λ*/
	HDIC_PN_FIXED						/*����λ*/
};

enum
{
	HDIC_RATE_04,					/*0.4*/
	HDIC_RATE_06,					/*0.6*/
	HDIC_RATE_08					/*0.8*/
};

enum
{
	HDIC_CARRIER_SINGLE,			/*���ز�*/
	HDIC_CARRIER_MULTI				/*���ز�*/
};

enum{
	HDIC_PN_945,					/*PN945*/
	HDIC_PN_595,					/*PN595*/
	HDIC_PN_420						/*PN420*/
};

enum
{
	HDIC_INTERLEAVER_720,			/*��֯����720*/
	HDIC_INTERLEAVER_240			/*��֯����240*/
};

enum
{
	HDIC_TS_OUTPUT_PARALLEL,			/* TS parallel output */
	HDIC_TS_OUTPUT_SERIAL					/* TS serial output */
};

enum
{
	HDIC_TS_DATA_SAMPLE_RISING,			/* TS Data should be sampled at the falling edge of TS_CLK */
	HDIC_TS_DATA_SAMPLE_FALLING			/* TS Data should be sampled at the falling edge of TS_CLK */
};

enum
{
	HDIC_TS_CLK_ALWAYS,						/* TS TS_CLK is always on */
	HDIC_TS_CLK_WITH_TSVLD				/* TS TS_CLK is set to 0 when TS_VLD is low */
};

enum
{
	HDIC_TS_NULLPACKET_ENABLED,			/* TS Null packets are enabled.*/
	HDIC_TS_NULLPACKET_DELETED			/* TS Null packets are deleted.*/
};

enum
{
	HDIC_TS_SERIAL_OUTPUT_D7,			/* When TS is serial,TS_D7 is valid.*/
	HDIC_TS_SERIAL_OUTPUT_D0			/* When TS is serial,TS_D0 is valid*/
};

//#define HDICTBX_Print(x)	printf(x)

/*HD2311��I2C�豸��ַ*/
#define HDIC2311_I2C_ADDRESS				0xE0//(((U16)TUNER_IIC_BUS<<8)|0xE0)

typedef struct HDIC2311_Init_Info_t
{
	UINT8 WorkMode;					/*����ģʽ�����������*/
	UINT8 TunerType;				/*��Ƶͷ���ͣ�����Ƶ������*/
	double TunerIF;					/*��Ƶͷ��Ƶ���Ƶ�ʣ���λMHZ*/
	UINT8 CrystalSelect;		/*����ѡ��*/	
	UINT8 TsType;						/*���л���*/
	UINT8 TsClockPolarity;	/*���ݲ�������ʱ�������ػ��½���*/
	UINT8 TsClockValid;			/*ʱ����Ч��ʽ��һֱ��Ч����valid�ź�*/
	UINT8 TsNullPacket;			/*�հ�ʹ�����*/
	UINT8 TsSerialOutPut;		/*����TSʱ�������TS_D7��TS_D0*/
}HDIC2311_Init_Info;

/*
HD2311 �ڲ�ʹ����غ���
*/
UINT8 HDIC2311_SetWorkMode(UINT8 WorkMode);
UINT8 HDIC2311_SetAutoMode(void);
UINT8 HDIC2311_SetNCOValue(UINT32 NCOValue);
UINT8 HDIC2311_SetTunerType(UINT8 Type);
UINT8 HDIC2311_SetTsFormat(UINT8 Serial, UINT8 CLK_Polarity, UINT8 CLK_Valid, UINT8 Null_Packet, UINT8 Serial_Output);
UINT8 HDIC2311_SetManualMode(UINT8 CarrierMode, UINT8 mode,UINT8 rate, UINT8 interleaverLength,UINT8 pnmode,UINT8 PnVariable);
UINT8 HDIC2311_GetNCOValue(UINT32 *NCOValue);
UINT8 HDIC2311_GetTimingRecovery(UINT32 *ControlWord);
UINT8 HDIC2311_GetAutoParameters(UINT8 *CarrierMode, UINT8 *pmode,UINT8 *prate, UINT8 *pinterleaverLength,UINT8 *Pnmode,UINT8 *PnVariable);
UINT8 HDIC2311_GetSignalSNRSC(double *SignalSNR);
UINT8 HDIC2311_GetSignalSNRMC(double *SignalSNR);
UINT8 HDIC2311_GetLdpcBER(double *pLdpcBER);
UINT8 HDIC2311_GetSignalBER(double *pSignalBER);
UINT8 HDIC2311_GetCableSignalSNR(double *SignalSNR);
UINT8 HDIC2311_GetCableLdpcBER(double *pLdpcBER);
UINT8 HDIC2311_GetCableSignalBER (double *pSignalBER);
UINT8 HDIC2311_GetFieldStrength(UINT32 *FieldStrength);
UINT8 HDIC2311_GetSignalSNR(double *SignalSNR);
UINT8 HDIC2311_OpenTunerI2C(UINT8 Address);
UINT8 HDIC2311_CloseTunerI2C(void);
UINT8 HDIC2311_CalculateNCOValue(double TunerIF,UINT8 CrystalSelect,UINT32 *NCOValue);
UINT8 HDIC2311_SoftReset(void);

UINT8 HDIC2311_WriteRegister(UINT16 Register,UINT8 Data);
UINT8 HDIC2311_ReadRegister(UINT16 Register,UINT8 *Data);
UINT8 HDIC2311_SetTuner(UINT32 Frequency);
/*
ϵͳ��ʼ����������Ҫ���ݿͻ�ƽ̨������޸�
*/
UINT8 HDIC2311_Init(void);

/*
HD2311 Cable��غ���
*/
UINT8 HDIC2311_Cable_SetMode(UINT8 Mode);
UINT8 HDIC2311_Cable_SetRate(UINT16 Rate);

/*
HD2311��Ƶ����
*/
UINT8 HDIC2311_DTMB_SetFrequency(UINT32 Frequency);
UINT8 HDIC2311_Cable_SetFrequency(UINT32 Frequency, UINT8 CableMode, UINT16 CableRate);

/*
HD2311��ȡ�ź�������ǿ�Ⱥ���
*/
/*�����Ƶͷ�������ṩ�ź�ǿ�ȵĽӿڣ���ʹ�ø�Ƶͷ�����Ľӿ�*/
UINT8 HDIC2311_GetSignalStrength(UINT16 *SignalStrength);
UINT8 HDIC2311_GetSignalQuality(UINT16 *SignalQuality);

/*
HD2311�ж��Ƿ���Ƶ�ɹ�����
*/
BOOL HDIC2311_IsDemodLocked(UINT8 *Status);
void HDIC2311_SetGPIO(BOOL HighLow);


