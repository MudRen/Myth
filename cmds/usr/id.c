// id.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i, j;
	object obj, *inv;
	string *id;

	if( !arg ) {
		inv = all_inventory(me);
		if( !sizeof(inv) )
			return notify_fail("������û���κζ�����\n");
        write( "������Я����Ʒ�ı������(�ҷ�) :\n");
		for(i=0; i<sizeof(inv); i++) {
			if( !me->visible(inv[i]) ) continue;
			printf("%-20s = %s\n", inv[i]->name(),
				implode(inv[i]->parse_command_id_list(), ", ") );
		}
		return 1;
	}

	if( arg=="here" ) {
		inv = all_inventory(environment(me));
		if( !sizeof(inv) )
			return notify_fail("����û���κζ�����\n");
        write( "�����������, ���Ｐ��Ʒ��(Ӣ��)�������� :\n");
		for(i=0; i<sizeof(inv); i++) {
			if( !me->visible(inv[i]) ) continue;
              if(inv[i]->query("taskguai")) continue;
			if (environment(me)->query("no_look")) {
			    	printf("%-20s = %s", "ģ����Ӱ��", "?");
				if (!wizardp(me)) {
				    	printf("\n");
					continue;
				}
				printf("   /   ");
			}
			printf("%-20s = %s\n", inv[i]->name(),
				implode(inv[i]->parse_command_id_list(), ", ") );
		}
		return 1;
	}
}
int help(object me)
{
write(@HELP
ָ���ʽ : id [here]
 
���ָ���������֪����Ʒ��Ӣ�����Ƽ�����. ֻ�� id ����ʾ
��������Я����Ʒ������. 'id here' ����ʾ���и�����ͬһ��
��������������.
 
HELP
    );
    return 1;
}
 
