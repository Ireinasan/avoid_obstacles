int i,j,k;
int TimeSeed , SeedNum ;
char LeftMost,RightMost ;
char SEG[9] ;         //��λ��������ϰ����ֵ
char SEG1_CtrlNum = 0 ;//��ҿ��Ƶ������ֵ
char SEG1_DispNum = 0 ;//1���������ʾ��ֵ������1��������ϴ�����ҿ��Ƶ����壬����һ���������ʾ��ֵ����SEG[1]
int Angry_Real = -7 ;   //��ʵŭ��ֵ
int Angry_Disp = 0 ;   //��ʾŭ��ֵ
int UB = 0 ;           //���ܲ���
int Led_Disp = 0 ;     //LED�ƹ���ʾֵ
int Score = -8 ;
int BGM = 0 ;
void INIT()                                     //��ʼ��
{
	LeftMost = 0 ;
	RightMost = 7 ; 
	SeedNum = 1 ;
	for(i = 0 ; i < 9 ; i++ )
	{
		SEG[i] = 10 ; 
	}
	SEG1_CtrlNum = 12 ;
}
void Scroll()                                   //������ʾ
{
	for( i = 1 ; i < 8 ; i ++ )
	{
		SEG[i] = SEG[i+1] ;
	}//�����ƶ�һ��
	
	srand(TL0) ;
	SeedNum += 1 ;
	TimeSeed = rand() ;
	srand (TimeSeed+SeedNum) ;
	SEG[8] = rand()%3+11 ;    ///��ȡһ�������������һ�����ɵ��������Ϊ���������µ�������������ש����α��������㹻����������
	
	while( (SEG[8]-SEG[7])==(SEG[7]-SEG[6]) )
	{
		SeedNum += 1 ;
		TimeSeed = rand() ;
		srand (TimeSeed+SeedNum) ;
		SEG[8] = rand()%3+11 ;
	}//��ֹ����б�������������������Ϸ�Ѷ�
	
	Angry_Real +=1 ;
	Score += 1 ;
	if(Angry_Real>0)
	{
		UB = Angry_Real/5 ;
		if(Angry_Real>=6)
		{
			if(Angry_Real >= 16 )
			{
				Angry_Real = 15 ;
			}
			Angry_Disp = Angry_Real%5 ;
			if(Angry_Disp == 0 )
			{
				Angry_Disp = 5 ;
			}
		}
		else
		{
			Angry_Disp = Angry_Real ;
		}
		SEG[0]= Angry_Disp ;
		//SEG[0] = Angry_Real ;
	}
	
	if(UB>=4)
	{
		UB = 3 ;
	}
	else if(UB == 0 )
	{
		Led_Disp = 0 ;
	}
	else if(UB == 1 )
	{
		Led_Disp = 1 ;
	}
	else if(UB == 2 )
	{
		Led_Disp = 3 ;
	}
	else if(UB == 3 )
	{
		Led_Disp = 7 ;
	}
	
}


void PlayBGM()
{
		MusicPlayerInit();	
		Music_PM=85 ;
		Music_tone=0xFA;
// 		SetMusic(Music_PM,Music_tone,&song,sizeof(song),enumMscNull);
// 		SetMusic(Music_PM,Music_tone,&PvZRoof,sizeof(PvZRoof),enumMscNull);
		SetMusic(Music_PM,Music_tone,&PinkiePromise,sizeof(PinkiePromise),enumMscNull);
		SetPlayerMode(enumModePlay);
}

void StopBGM()
{
		SetPlayerMode(enumModeStop);
}

void dealwithmyKN()		                  
{	 
	if(GetAdcNavAct(enumAdcNavKeyCenter) == enumKeyPress)//�������������°�ʱ����/ֹͣBGM
	{
		if(BGM == 0)
		{
			PlayBGM();
			BGM = 1 ;
		}
		else if(BGM == 1)
		{
			StopBGM();
			BGM = 0 ;
		}
	}
	if(SEG1_CtrlNum != SEG[1])
	{
		if(GetAdcNavAct(enumAdcNavKeyUp) == enumKeyPress)//���������ϰ�ʱĿ�������ƶ�
		{
			SEG1_CtrlNum += 1 ;
			if(SEG1_CtrlNum == 14)
			{
				SEG1_CtrlNum = 11 ;
			}
		}
		if(GetAdcNavAct(enumAdcNavKeyDown)== enumKeyPress) 	          //���������°�ʱĿ�������ƶ�
		{	    
			SEG1_CtrlNum -= 1 ;
			if(SEG1_CtrlNum == 10)
			{
				SEG1_CtrlNum = 13 ;
			}
		}
		if(GetAdcNavAct(enumAdcNavKey3)== enumKeyPress)          //����key3���ͷ�3�׼���
		{
			if(UB==3)
			{
				for(i =2 ; i < 8 ; i ++ )
				{
					SEG[i] = 10 ;
				}
				UB= 0 ;
				Angry_Real = 0 ;
			}
			else 
			{
				SEG1_DispNum = SEG1_DispNum ;
			}
		}
	}
	else if(SEG1_CtrlNum == SEG[1])                                //������ײ���ϰ�ʱ������ʧЧ
	{
		if(GetAdcNavAct(enumAdcNavKey3) == enumKeyPress)
		{
			SEG1_DispNum = SEG1_DispNum ;
		}
		if(GetAdcNavAct(enumAdcNavKey3) == enumKeyPress) 	          
		{	    
			SEG1_DispNum = SEG1_DispNum ;
		}
	}
	
	if(UB>=4)
	{
		UB = 3 ;
	}
	else if(UB == 0 )
	{
		Led_Disp = 0 ;
	}
	else if(UB == 1 )
	{
		Led_Disp = 1 ;
	}
	else if(UB == 2 )
	{
		Led_Disp = 3 ;
	}
	else if(UB == 3 )
	{
		Led_Disp = 7 ;
	}
	LedPrint(Led_Disp);
}

void dealwithmykey()
{
	if(SEG1_CtrlNum != SEG[1])
	{
		if(GetKeyAct(enumKey1) == enumKeyPress)//1����ʱ�ͷ�1�׼���
		{
			if(UB>=1)
			{
				//SetBeep(1000, 20);
				for(i = 2 ; i < 5 ; i ++ )
				{
					SEG[i] = 10 ;
				}
				UB -= 1 ;
				Angry_Real -= 5 ;
				//Angry_Real += Angry_Disp ;
			}
			else 
			{
				SEG1_DispNum = SEG1_DispNum ;
			}
		}
		if(GetKeyAct(enumKey2) == enumKeyPress)//2����ʱ�ͷ�2�׼���
		{
			if(UB>=2)
			{
				//SetBeep(1000, 20);
				for(i = 2 ; i < 8 ; i ++ )
				{
					if(SEG[i]==SEG1_CtrlNum)
					{
						//SetBeep(1000, 20);
						SEG[i] = 10 ;
					}
				}
				UB -= 2 ;
				Angry_Real -= 10 ;
				//Angry_Real += Angry_Disp ;
			}
			else 
			{
				SEG1_DispNum = SEG1_DispNum ;
			}
		}
	}
	else if(SEG1_CtrlNum == SEG[1])                                //������ײ���ϰ�ʱkey��ʧЧ
	{
		if(GetKeyAct(enumKey1) == enumKeyPress)
		{
			SEG1_DispNum = SEG1_DispNum ;
		}
		if(GetKeyAct(enumKey2) == enumKeyPress)	          
		{	    
			SEG1_DispNum = SEG1_DispNum ;
		}
	}
	if(UB>=4)
	{
		UB = 3 ;
	}
	else if(UB == 0 )
	{
		Led_Disp = 0 ;
	}
	else if(UB == 1 )
	{
		Led_Disp = 1 ;
	}
	else if(UB == 2 )
	{
		Led_Disp = 3 ;
	}
	else if(UB == 3 )
	{
		Led_Disp = 7 ;
	}
	LedPrint(Led_Disp);
	
}
/* ���:   0   1    2	   3    4	    5    6	  7   8	   9	 10	   11		12   13    14     15   16 */
	/* ��ʾ:   0   1    2    3    4     5    6    7   8    9  (��)   ��-  ��-  ��-  ����-  ����-  ����- */  
void DecideSEG1Disp()
{
	if(SEG[1]==10)//��
	{
		SEG1_DispNum = SEG1_CtrlNum ;
	}
	else if(SEG[1]==11)//��-
	{
		if(SEG1_CtrlNum==11)//����
		{
			SEG1_DispNum = 11 ;
		}
		if(SEG1_CtrlNum==12)//����
		{
			SEG1_DispNum = 15 ;
		}
		if(SEG1_CtrlNum==13)//����
		{
			SEG1_DispNum = 16 ;
		}
	}
	else if(SEG[1]==12)//��-
	{
		if(SEG1_CtrlNum==11)//����
		{
			SEG1_DispNum = 15 ;
		}
		if(SEG1_CtrlNum==12)//����
		{
			SEG1_DispNum = 12 ;
		}
		if(SEG1_CtrlNum==13)//����
		{
			SEG1_DispNum = 14 ;
		}
	}
	else if(SEG[1]==13)//��-
	{
		if(SEG1_CtrlNum==11)//����
		{
			SEG1_DispNum = 16 ;
		}
		if(SEG1_CtrlNum==12)//����
		{
			SEG1_DispNum = 14 ;
		}
		if(SEG1_CtrlNum==13)//����
		{
			SEG1_DispNum = 13 ;
		}
	}
}
void my1S_callback()			                //������1S�¼��ص�����
{ 
		if(SEG1_CtrlNum != SEG[1])
		{
			Scroll() ;
			DecideSEG1Disp() ;
			LedPrint(Led_Disp);
			SetDisplayerArea(LeftMost,RightMost);						               //������Ч��ʾ����
			Seg7Print(SEG[0],SEG1_DispNum,SEG[2],SEG[3],SEG[4],SEG[5],SEG[6],SEG[7]);        //������������	
		}
		else if(SEG1_CtrlNum == SEG[1])
		{
			SetDisplayerArea(LeftMost,RightMost);						               //������Ч��ʾ����
			Seg7Print((Score/10000000)%10,(Score/1000000)%10,(Score/100000)%10,(Score/10000)%10,(Score/1000)%10,(Score/100)%10,(Score/10)%10,Score%10);
			LedPrint(0xFF);
		}
}

