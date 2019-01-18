// enchant.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int pts;

	if( !arg || !sscanf(arg, "%d", pts) ) 
		return notify_fail("ָ���ʽ��enchant <��������>\n");

	if( pts > ((int)me->query("max_mana")/20+1) )
		return notify_fail("��ķ������㣬��������ôǿ��������\n");

	if( pts < 0 ) return notify_fail("��������������������\n");	
	me->set("mana_factor", pts);
	write("Ok.\n");
	return 1;
}

int help (object me)
{
	write(@HELP
ָ���ʽ: enchant <��������>
 
���ָ�������趨ʹ��ħ������ʱҪ������������ħ�����õķ���ǿ�ȡ�
��������Խ�ߣ�ħ��������ɱ����ҲԽǿ��

HELP
	);
	return 1;
}
