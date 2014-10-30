#include "includes.h"

int main(void)
{
	uint_32 mRuncount; 								//��ѭ��������
	uint_32 lightCount;                                //���Ƶ���ɫ�ĸı�
	DISABLE_INTERRUPTS;

	light_init(RUN_LIGHT_RED,LIGHT_OFF);	   //��ʼ�����
	light_init(RUN_LIGHT_GREEN,LIGHT_OFF);  //��ʼ���̵�
	light_init(RUN_LIGHT_BLUE,LIGHT_OFF);     //��ʼ������

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


