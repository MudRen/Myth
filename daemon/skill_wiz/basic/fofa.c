//fofa.c

inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
	if( (int)me->query_skill("spells") <= (int)me->query_skill("fofa") )
		return notify_fail("��ķ�����Ϊ����������޷�ѧϰС�˷𷨡�\n");
	if( (int)me->query("bellicosity") > 100 )
		return notify_fail("���ɱ��̫�أ��޷�����С�˷𷨡�\n");
	return 1;
}

string cast_spell_file(string spell)
	{
return CLASS_D("bonze") + "/fofa/" + spell;

	}



