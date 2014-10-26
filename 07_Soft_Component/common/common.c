//===========================================================================
//文件名称：common.h
//功能概要：公共要素源文件
//版权所有：苏州大学飞思卡尔嵌入式中心(sumcu.suda.edu.cn)
//更新记录：2012-10-12 V1.0
//         2013-02-02 V2.0(WYH)
//===========================================================================

#include "common.h"    //包含公共要素头文件

static  uint_32  int_disable_level; // 静态变量，当前中断嵌套层数

//=========================================================================
//函数名称：init_critical
//参数说明：无
//函数返回：无
//功能概要：初始化临界区访问控制
//=========================================================================
void  init_critical(void) 
{
    ENABLE_INTERRUPTS;
    int_disable_level = 0;
}

//=========================================================================
//函数名称：enter_critical
//参数说明：无
//函数返回：无
//功能概要：进入临界区
//=========================================================================
void  enter_critical(void)
{
    if (0 == int_disable_level)
    {
        DISABLE_INTERRUPTS;
    }
    int_disable_level++;
}

//=========================================================================
//函数名称：exit_critical
//参数说明：无
//函数返回：无
//功能概要：离开临界区
//=========================================================================
void  exit_critical(void) 
{
    if (int_disable_level)
{
        int_disable_level--;
        if (0 == int_disable_level)
        {
            ENABLE_INTERRUPTS;
        }
    }
}

//============================================================================
//函数名称：enable_irq
//函数返回：无  
//参数说明：irq：irq号
//功能概要：使能irq中断 
//============================================================================
void enable_irq (uint_16 irq)
{
    //确定irq号为有效的irq号
    if (irq > 32)	irq=32;
    
    NVIC_ICPR |= (1<<(irq%32));
    NVIC_ISER |= (1<<(irq%32));

}

//============================================================================
//函数名称：disable_irq
//函数返回：无      
//参数说明：irq：irq号
//功能概要：禁止irq中断 
//============================================================================
void disable_irq (uint_16 irq)
{

    //确定irq号为有效的irq号
    if (irq > 32)	irq=32;
    
    NVIC_ICER = (1<<(irq%32));     
}
 
//============================================================================
//函数名称：set_irq_priority
//函数返回：无      
//参数说明：irq：irq号         											   
//         prio：优先级
//功能概要：设置irq中断和优先级 
//============================================================================
void set_irq_priority (uint_16 irq, uint_16 prio)
{   
    uint_8 *prio_reg;
    uint_8 err = 0;
    uint_8 div = 0;
   
    if (irq > 32)
    {    
        err = 1;
    }
    if (prio > 3)
    {     
        err = 1;
    }
    if (err != 1)
    {  
       div = irq / 4;
       prio_reg = (uint_8 *)((uint_32)&NVIC_IP(div));
       *prio_reg = ( (prio&0x3) << (8 - ARM_INTERRUPT_LEVEL_BITS) );             
    }
}
