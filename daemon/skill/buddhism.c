// buddhism.c

inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
	if( (int)me->query_skill("spells") <= (int)me->query_skill("buddhism") )
		return notify_fail("��ķ�����Ϊ����������޷�ѧϰ��˷𷨡�\n");
	if( (int)me->query("bellicosity") > 100 )
		return notify_fail("���ɱ��̫�أ��޷�������˷𷨡�\n");
	return 1;
}

string cast_spell_file(string spell)
	{
return CLASS_D("bonze") + "/buddhism/" + spell;

	}

string type() { return "magic";}

