//说明见工程文件夹下的Doc文件夹内Readme.txt文件
//============================================================================

#include "includes.h"   //包含总头文件

int main(void)
{
	//1. 声明主函数使用的变量
	uint_32  mRuncount;     //主循环计数器
	//2. 关总中断
	DISABLE_INTERRUPTS;
	//3. 初始化外设模块
	light_init(RUN_LIGHT_BLUE,LIGHT_OFF);     //初始化蓝灯
	light_init(RUN_LIGHT_RED,LIGHT_OFF);
	//4. 给有关变量赋初值
	mRuncount=0;            //主循环计数器
	//5. 使能模块中断
	//6. 开总中断
	ENABLE_INTERRUPTS;

	//进入主循环
	//主循环开始==================================================================
	for(;;)
	{
	    //运行指示灯闪烁-----------------------------------------------
	    mRuncount++;			   //主循环次数计数器+1
	    if (mRuncount >= RUN_COUNTER_MAX)  //主循环次数计数器大于设定的宏常数
	    {
		mRuncount=0;		   //主循环次数计数器清零
		light_change(RUN_LIGHT_BLUE);      //蓝灯（RUN_LIGHT_BLUE）状态变化
	    }
	   //以下加入用户程序----------------------------------------------
	}  //主循环end_for
       //主循环结束==========================================================
}

 
