// eating-force.c  by angell
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) 
{ 
        if( ((int)me->query("food") - (int)me->max_food_capacity()) < (int)me->query_skill("eating-force", 1) )
                return notify_fail("��ʳ�񹦣�����Ҫ�Եı����������ٱ�����ȥ������������ѧ��\n");

        return 1; 
        if( ((int)me->query("water") - (int)me->max_water_capacity()) < (int)me->query_skill("eating-force", 1) )
                return notify_fail("�Ա���Ҫ���㡣ȥ���ȹ�������ѧ��\n");
       return 1; 
}

int practice_skill(object me)
{
        return notify_fail("��ʳ��ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}
string exert_function_file(string func)
{
        return CLASS_D("tianpeng") + "/eating-force/" + func;
}
