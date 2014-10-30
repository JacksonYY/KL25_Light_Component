//˵���������ļ����µ�Doc�ļ�����Readme.txt�ļ�
//============================================================================

#include "includes.h"   //������ͷ�ļ�

int main1(void)
{
	//1. ����������ʹ�õı���
	uint_32  mRuncount;     //��ѭ��������
	uint_32 lightCount;
	int flag;
	//2. �����ж�
	DISABLE_INTERRUPTS;
	//3. ��ʼ������ģ��
	light_init(RUN_LIGHT_RED,LIGHT_OFF);	   //��ʼ�����
	light_init(RUN_LIGHT_GREEN,LIGHT_OFF);  //��ʼ���̵�
	light_init(RUN_LIGHT_BLUE,LIGHT_OFF);     //��ʼ������
	//4. ���йر�������ֵ
	mRuncount=0;            //��ѭ��������
	lightCount=0; 			//��״̬�仯��
	flag = 0;
	//5. ʹ��ģ���ж�
	//6. �����ж�
	ENABLE_INTERRUPTS;

	//������ѭ��
	//��ѭ����ʼ==================================================================
	for(;;)
	{
	    //����ָʾ����˸-----------------------------------------------
	    mRuncount++;			   //��ѭ������������+1
	    if (mRuncount >= RUN_COUNTER_MAX)  //��ѭ�����������������趨�ĺ곣��
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
	    				lightCount=0;            //�ж�С�Ƽ���������
	    				break;
	    	}
	    	mRuncount=0;		   //��ѭ����������������

	    	flag=1;
	    }
	   //���¼����û�����----------------------------------------------
	}  //��ѭ��end_for
       //��ѭ������==========================================================
}

 
