/*     音乐编码规则： 1，常规音乐简谱发音编码（成对出现，不可分开，即中间不能插入其它编码和控制字）   
			                         音高（1字节），节拍数（1字节），音高，节拍，.......        // 音高： 00          ：休止符
															                                                                      0x11 — 0x17 ：对应低音 do、re、mi、fa、so、la、si
																																																	  0x21 — 0x27 ：对应中音 do、re、mi、fa、so、la、si
                      															                                                0x31 — 0x37 ：对应高音 do、re、mi、fa、so、la、si
																																														 节拍： 1-255（0x01-0xFF）： 单位1/16拍
																																														        或十六进制中，高4位表示整拍数，低4位表示分拍数
																																																		    如：发音2拍：  0x20
																																																				    发音半拍： 0x08
																																																				    发音1拍半：0x18
											2，音乐编码中可以插入以下控制字，用于设定音乐播放参数等（前6个也可以通过函数，用程序设定和实现）
                                    Use_null           ：  不用LED和Light
																		Use_LED            ：  启用LED
																		Use_Light          ：  启用Light
																		Use_LEDandLight    ：  启用LED和Light
																		Set_beatsPM        ：  设置节拍率， 后面再跟 节拍率（1字节）
																		Set_tone           ：  设置音调，   后面再跟 音调（1字节）：0xFA 或 0xFB 或 0xFC 或 0xFD 或 0xFE 或 0xFF 或 0xF9
																		Repeat_begin       ：  设置音乐播放重复开始处。重复一次（暂不能多次），暂不能嵌套（嵌套无效或可能导致不可预期结果）
																		Repeat_end         ：  设置音乐播放重复结束处
*/
code unsigned char PvZRoof[]={         //PvZRoof
0x00,0x10,
	
0x16,0x06,
0x23,0x04,
0x23,0x04,
0x26,0x04,
0x23,0x04,
0x00,0x10,
	
0x23,0x06,
0x00,0x10,
	
0x23,0x06,
0x00,0x10,

0x16,0x06,
0x23,0x06,
0x23,0x06,
0x26,0x06,
0x23,0x06,
0x00,0x10,
	
0x23,0x06,
0x00,0x10,


0x22,0x06,
0x23,0x06,
0x26,0x06,
0x00,0x08,

0x22,0x06,
0x23,0x06,
0x16,0x06,
0x00,0x10,

0x22,0x06,
0x23,0x06,
0x21,0x06,
0x22,0x06,
0x23,0x06,
0x25,0x06,
0x23,0x06,
0x00,0x10,

0x25,0x06,
0x23,0x06,
0x22,0x06,
0x23,0x06,
0x22,0x06,
0x21,0x06,
0x16,0x06,
0x00,0x10,

0x15,0x06,
0x16,0x06,
0x21,0x06,
0x22,0x06,
0x23,0x06,
0x22,0x06,
0x21,0x06,
0x00,0x10,

0x22,0x06,
0x16,0x06,
0x00,0x10,
// 0x25,0x10,
// 0x31,0x10,
// 0x32,0x10,
// 0x33,0x30,
// 0x32,0x08,
// 0x31,0x08,
// 0x32,0x20,
// 0x31,0x10,
// 0x26,0x10,
// 0x31,0x40,  
// 0x31,0x08,
// 0x26,0x08,
// 0x25,0x08,
// 0x23,0x08,
// 0x21,0x08,
// 0x16,0x08,
// 0x15,0x08,
// 0x13,0x08,
// enumMscRepeatBegin,            
// 0x15,0x20,
// 0x21,0x10,
// 0x22,0x10,
// 0x23,0x18,
// 0x24,0x08,
// 0x23,0x10,
// 0x21,0x10,
// 0x22,0x20,
// 0x21,0x10,
// 0x16,0x10,
// 0x21,0x40,  
// 0x15,0x20,
// 0x21,0x10,
// 0x22,0x10,

// 0x23,0x10,
// 0x23,0x08,
// 0x24,0x08,
// 0x25,0x10,
// 0x21,0x10,
// 0x24,0x18,
// 0x23,0x08,
// 0x25,0x10,
// 0x22,0x08,
// 0x23,0x08,
// 0x23,0x08,
// 0x22,0x08,
// 0x22,0x30,
// 0x23,0x20,
// 0x25,0x10,
// 0x31,0x10,

// 0x27,0x18,
// 0x26,0x08,
// 0x26,0x20,
// 0x25,0x10,
// 0x25,0x08,
// 0x26,0x08,
// 0x27,0x10,
// 0x26,0x08,
// 0x25,0x08,
// 0x23,0x40,
// 0x24,0x18,
// 0x24,0x08,
// 0x25,0x10,
// 0x26,0x10,

// 0x25,0x10,
// 0x24,0x08,
// 0x23,0x08,
// 0x22,0x20,
// 0x17,0x10,
// 0x17,0x08,
// 0x16,0x08,
// 0x15,0x10,
// 0x16,0x10,
// 0x21,0x80,

enumMscDrvSeg7,                    //改变显示
enumMscSetTone, 0xFA,             //设置音调
enumMscSetBeatsPM,120,            //设置节拍�
enumMscRepeatEnd		              //设置重复结束
};
