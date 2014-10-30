//说明见工程文件夹下的Doc文件夹内Readme.txt文件
//============================================================================

#include "includes.h"   //包含总头文件

int main1(void)
{
	//1. 声明主函数使用的变量
	uint_32  mRuncount;     //主循环计数器
	uint_32 lightCount;
	int flag;
	//2. 关总中断
	DISABLE_INTERRUPTS;
	//3. 初始化外设模块
	light_init(RUN_LIGHT_RED,LIGHT_OFF);	   //初始化红灯
	light_init(RUN_LIGHT_GREEN,LIGHT_OFF);  //初始化绿灯
	light_init(RUN_LIGHT_BLUE,LIGHT_OFF);     //初始化蓝灯
	//4. 给有关变量赋初值
	mRuncount=0;            //主循环计数器
	lightCount=0; 			//灯状态变化器
	flag = 0;
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
	    	lightCount++;
	    	switch (lightCount % 3)
	    	{
	    			case 1:
	    				if (flag == 1) {
	    					light_change(RUN_LIGHT_BLUE);
	    				}
	    				light_change(RUN_LIGHT_RED);
	    				break;
	    			case 2:
	    				light_change(RUN_LIGHT_RED);
	    				light_change(RUN_LIGHT_GREEN);
	    				break;
	    			case 0:
	    				light_change(RUN_LIGHT_GREEN);
	    				light_change(RUN_LIGHT_BLUE);
	    				lightCount=0;            //判断小灯计数器清零
	    				break;
	    	}
	    	mRuncount=0;		   //主循环次数计数器清零

	    	flag=1;
	    }
	   //以下加入用户程序----------------------------------------------
	}  //主循环end_for
       //主循环结束==========================================================
}

 
