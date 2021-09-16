//******* 用户程序段1：用户程序包含文件 *************//
#include "main.H"                              //必须。编写应用程序时，仅需改写 main.h 和 main.c文件 
#include "stdio.h"
#include "stdlib.h"
#include "song.c" 
#include "PvZRoof.c"
#include "PinkiePromise.c"
//举例。song.c中编写了音乐（同一首歌）编码
//******* 用户程序段2：用户自定义函数声明 *************//


// //******* 用户程序段3：用户程序全局变量定义 *************//        
unsigned char Music_tone,Music_PM;             //举例。 音乐播放音调、节凑（每分钟节拍数）
int TimeSeed = 100; 

//******* 用户程序段4：用户自定义函数原型 *************//
#include "function.c" 


void myKN_callback()			               	                                                        //举例。导航按键事件回调函数
{
		dealwithmyKN() ;
}

void mykey_callback()		                            // 按键（Key1、Key2）事件回调函数
{	
		  dealwithmykey() ;
}

//******* main()函数 *************//	
void main() {         //主函数 main() 开始         //此行必须！！！ 
	  DisplayerInit();                                 //举例
		//PlayBGM();
		INIT();
		my1S_callback();
		
//******* 用户程序段5：用户main()函数内部局部变量定义 *************//
	
//******* 用户程序段6：用户main()函数（初始化类程序） *************//		
//1,加载需要用的模块(由各模块提供加载函数)
    Key_Init();                                      //举例，需要用到的模块及其函数、方法，必须对其初始化（让其准备、就绪和响应做后台服务）
	  BeepInit();	                                     //举例
 	  AdcInit(ADCexpEXT);                              //举例，ADC模块初始化，有参数，选择扩展接口EXT上P1.0、P1.1是否也做ADC功能
		
//2,设置事件回调函数(由sys提供设置函数SetEventCallBack())	
		SetEventCallBack(enumEventKey, mykey_callback);            //举例
		SetEventCallBack(enumEventSys1S, my1S_callback);           //举例
 		SetEventCallBack(enumEventNav, myKN_callback);             //举例，设置导航按键回调函数

//3,用户程序状态初始化 	
		//SetDisplayerArea(0,7);                           //举例
		
/*****************  MySTC_OS 初始化与加载开始  ********************************/   
	  MySTC_Init();	    // MySTC_OS 初始化         //此行必须！！！   
	while(1)            // 系统主循环              //此行必须！！！   	
		{ MySTC_OS();     // MySTC_OS 加载           //此行必须！！！
/*****************  MySTC_OS 初始化与加载结束  ********************************/  
			
//******* 用户程序段7：用户main()函数（主循环程序） *************//
			
			
		}	              //主循环while(1)结束         //此行必须！！！ 
}                   //主函数 main() 结束         //此行必须！！！ 

