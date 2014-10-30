#include "includes.h"

int main(void)
{
	uint_32 mRuncount; 								//主循环计数器
	uint_32 lightCount;                                //控制灯颜色的改变
	DISABLE_INTERRUPTS;

	light_init(RUN_LIGHT_RED,LIGHT_OFF);	   //初始化红灯
	light_init(RUN_LIGHT_GREEN,LIGHT_OFF);  //初始化绿灯
	light_init(RUN_LIGHT_BLUE,LIGHT_OFF);     //初始化蓝灯

	mRuncount = 0;
	lightCount = 0;

	ENABLE_INTERRUPTS;

	while(1) {
		mRuncount++;
		if (mRuncount > RUN_COUNTER_MAX)
		{
			lightCount++;
			switch(lightCount % 8)
			{
				case 1:
					light_change(RUN_LIGHT_BLUE);
					break;
				case 2:
					light_change(RUN_LIGHT_GREEN);
					break;
				case 3:
					light_change(RUN_LIGHT_BLUE);
					break;
				case 4:
					light_change(RUN_LIGHT_RED);
					break;
				case 5:
					light_change(RUN_LIGHT_BLUE);
					break;
				case 6:
					light_change(RUN_LIGHT_GREEN);
					break;
				case 7:
					light_change(RUN_LIGHT_BLUE);
					break;
				case 0:
					light_change(RUN_LIGHT_RED);
					lightCount=0;
					break;
			}
			mRuncount=0;
		}

	}
}


