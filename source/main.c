//******* �û������1���û���������ļ� *************//
#include "main.H"                              //���롣��дӦ�ó���ʱ�������д main.h �� main.c�ļ� 
#include "stdio.h"
#include "stdlib.h"
#include "song.c" 
#include "PvZRoof.c"
#include "PinkiePromise.c"
//������song.c�б�д�����֣�ͬһ�׸裩����
//******* �û������2���û��Զ��庯������ *************//


// //******* �û������3���û�����ȫ�ֱ������� *************//        
unsigned char Music_tone,Music_PM;             //������ ���ֲ����������ڴգ�ÿ���ӽ�������
int TimeSeed = 100; 

//******* �û������4���û��Զ��庯��ԭ�� *************//
#include "function.c" 


void myKN_callback()			               	                                                        //���������������¼��ص�����
{
		dealwithmyKN() ;
}

void mykey_callback()		                            // ������Key1��Key2���¼��ص�����
{	
		  dealwithmykey() ;
}

//******* main()���� *************//	
void main() {         //������ main() ��ʼ         //���б��룡���� 
	  DisplayerInit();                                 //����
		//PlayBGM();
		INIT();
		my1S_callback();
		
//******* �û������5���û�main()�����ڲ��ֲ��������� *************//
	
//******* �û������6���û�main()��������ʼ������� *************//		
//1,������Ҫ�õ�ģ��(�ɸ�ģ���ṩ���غ���)
    Key_Init();                                      //��������Ҫ�õ���ģ�鼰�亯������������������ʼ��������׼������������Ӧ����̨����
	  BeepInit();	                                     //����
 	  AdcInit(ADCexpEXT);                              //������ADCģ���ʼ�����в�����ѡ����չ�ӿ�EXT��P1.0��P1.1�Ƿ�Ҳ��ADC����
		
//2,�����¼��ص�����(��sys�ṩ���ú���SetEventCallBack())	
		SetEventCallBack(enumEventKey, mykey_callback);            //����
		SetEventCallBack(enumEventSys1S, my1S_callback);           //����
 		SetEventCallBack(enumEventNav, myKN_callback);             //���������õ��������ص�����

//3,�û�����״̬��ʼ�� 	
		//SetDisplayerArea(0,7);                           //����
		
/*****************  MySTC_OS ��ʼ������ؿ�ʼ  ********************************/   
	  MySTC_Init();	    // MySTC_OS ��ʼ��         //���б��룡����   
	while(1)            // ϵͳ��ѭ��              //���б��룡����   	
		{ MySTC_OS();     // MySTC_OS ����           //���б��룡����
/*****************  MySTC_OS ��ʼ������ؽ���  ********************************/  
			
//******* �û������7���û�main()��������ѭ������ *************//
			
			
		}	              //��ѭ��while(1)����         //���б��룡���� 
}                   //������ main() ����         //���б��룡���� 

