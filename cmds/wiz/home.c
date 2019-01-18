// home.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string msg, loc;
	object ridee;

	if( file_size(user_path(geteuid(me)) + "workroom.c") <= 0 )
		return notify_fail("��û���Լ��Ĺ����ҡ�\n");

	if( stringp(msg = me->query("env/msg_home")) )
		if (msg != "") message_vision(msg + "\n", me);
	loc = user_path(geteuid(me)) + "workroom";
	if (ridee = me->ride())
		ridee->move(loc);
	me->move(loc);	
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : home

���ô�һָ���ֱ�ӻص��Լ��Ĺ����ҡ�
������� 'msg_home' ����趨, ���ڳ����˶��ῴ���Ǹ�ѶϢ.
HELP
    );
    return 1;
}
