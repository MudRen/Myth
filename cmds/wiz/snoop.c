// snoop.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg ) {
		if( objectp(ob = query_snooping(me)) )
			write("���������ڼ���" + ob->query("name") + "���յ���ѶϢ��\n");
		return 1;
	}
	 else if( arg=="-none" ) {
if( objectp(ob = query_snooping(me)) && wizardp(ob) )
                tell_object(me, HIW"��ֹͣ����"+ob->query("name")+"���յ���ѶϢ��\n" NOR);  
		snoop(me);
		write("Ok.\n");
		return 1;
	}
else if(query_snooping(me)) snoop(me);

	ob = find_player(arg);
	if(!ob) ob = find_living(arg);
	
	if(!ob) ob = LOGIN_D->find_body(arg);
	/* added by mon. 2/23/97 */

	if(!ob || !me->visible(ob)) return notify_fail("û������ˡ�\n");
        if(!interactive(ob)) return notify_fail("û������ˡ�\n");

	if( wizhood(me) != "(admin)"
	&&	wiz_level(me) <= wiz_level(ob) )
		return notify_fail("��û�м���" + ob->name() + "������ѶϢ��Ȩ����\n");

	if( me==ob ) return notify_fail("���� snoop -none ���������\n");
		
	snoop(me, ob);

	me->set_temp("snoop_encoding",
		(int)me->query_encoding()*10+ob->query_encoding());
	// added by mon 6/1/98

	write("�����ڿ�ʼ����" + ob->name(1) + "���յ���ѶϢ��\n");
        if( userp(ob) ) log_file("cmds/SNOOP_PLAYER",
                sprintf("%s(%s) snoops %s(%s) on %s.\n", me->name(1), geteuid(me), ob->name(1), geteuid(ob),
			ctime(time()) ) );
// if( wizardp(ob) && wizhood(me) != "(admin)")
if( wizardp(ob) && is_root(ob) )
		tell_object(ob, HIW + me->name(1) + "��ʼ���������յ���ѶϢ��\n" + NOR);

	return 1;
}

int help()
{
	write(@TEXT
ָ���ʽ��snoop <ĳ��>|-none

��������ʹ������������ѶϢ��snoop -none ��ȡ��������
TEXT
	);
	return 1;
}
