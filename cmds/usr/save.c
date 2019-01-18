// save.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object link_ob;
	int  cur_time;

	seteuid(getuid());

	if( !objectp(link_ob = me->query_temp("link_ob")) )
		return notify_fail("�㲻�Ǿ����������߽��룬���ܴ��档\n");

	cur_time = time();
	if( (cur_time - me->query("last_save")) < 60 ) {
		return notify_fail("��ٵ�ſ��Դ��档\n");
        }
        // mon shortened the no_save time. 4/2/98
		
	me->set("last_save", cur_time);	
	if( environment(me)->query("valid_startroom") ) {
		me->set("startroom", base_name(environment(me)));
		write("�����´����߽���ʱ��������￪ʼ��\n");
	}

	if( (int)link_ob->save() && (int)me->save() ) {
        write("����������ϡ�\n");
		return 1;
	} else {
		write("����ʧ�ܡ�\n");
		return 0;
	}
}

int help(object me)
{
	write(@HELP
ָ���ʽ��save

��������ܶ��Ľ����������
HELP
	);
	return 1;
}
