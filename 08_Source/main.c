//˵���������ļ����µ�Doc�ļ�����Readme.txt�ļ�
//============================================================================

#include "includes.h"   //������ͷ�ļ�

int main(void)
{
	//1. ����������ʹ�õı���
	uint_32  mRuncount;     //��ѭ��������
	//2. �����ж�
	DISABLE_INTERRUPTS;
	//3. ��ʼ������ģ��
	light_init(RUN_LIGHT_BLUE,LIGHT_OFF);     //��ʼ������
	//4. ���йر�������ֵ
	mRuncount=0;            //��ѭ��������
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
		mRuncount=0;		   //��ѭ����������������
		light_change(RUN_LIGHT_BLUE);      //���ƣ�RUN_LIGHT_BLUE��״̬�仯
	    }
	   //���¼����û�����----------------------------------------------
	}  //��ѭ��end_for
       //��ѭ������==========================================================
}

 