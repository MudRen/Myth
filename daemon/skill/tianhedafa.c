// tianhe_dafa
// by Calvin and Leox ��ͬ����
//��Ȩ����,δ����ɲ��÷�¼

inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells",1) < 20 )
        return notify_fail("��ķ�����Ϊ����������޷�ѧϰ��Ӵ󷨡�\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("tianpeng") + "/tianhedafa/" + spell;
}

string type() { return "magic";} 
