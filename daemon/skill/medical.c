//����ҽ�� by koker@sjsh 2001
/*������V2.0�汾*/
 
inherit SKILL;
int valid_enable(string usage)
{
        return usage=="literate";
}

#include <ansi.h>

int valid_learn(object me)
{
   object ob;

   if( (int)me->query("level") < 5 )
    return notify_fail(""HIW"��ĵȼ�����������ѧϰҽ��."NOR"\n");

   if ((int)me->query_skill("medical", 1) + 1>800)//��߿���ѧ��800��
    return notify_fail(""HIW"���ѵ�ҽ���ľ����ˣ�������ѧ�ˡ�"NOR"\n");

   if ((int)me->query_skill("medical", 1)*6 > ( (int)me->query("level")+4))
//��5-100�ȼ�ÿһ���ȼ�����ѧ4��ҽ�����ܡ�100�Ժ�ÿ��һ���ȼ�����ѧ2��ҽ��
    return notify_fail(""HIW"��ĵȼ�����,���ܼ���ѧϰҽ�����������ˡ�"NOR"\n");

   return 1;
}




