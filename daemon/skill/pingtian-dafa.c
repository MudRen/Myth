// dao
inherit SKILL;


int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells", 1) < 20 )
        return notify_fail("��ķ�����Ϊ����������޷�ѧϰƽ��󷨡�\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("yaomo") + "/kusong/pingtian-dafa/" + spell;
}


