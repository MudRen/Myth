// purge.c

#include <ansi.h>
#define SYNTAX	"ָ���ʽ��purge [<δ��������>] | <ʹ��������> because <ԭ��>\n"

inherit F_CLEAN_UP;

private int do_purge_players(int day);

int main(object me, string arg)
{
	string name, reason;
	string status;
	int day;
        if (! SECURITY_D->valid_grant(me, "(admin)")) return 0;

	status = wizhood(me);
	if( me!=this_player(1)
	|| wiz_level(me) < wiz_level(status) )
		return notify_fail("��û��Ȩ��ʹ�����ָ�\n");

	if( !arg ) return notify_fail(SYNTAX);

	if( sscanf(arg, "%s because %s", name, reason)!=2 )
		return notify_fail(SYNTAX);

	seteuid(getuid());
	if( file_size(DATA_DIR + "playerhomes/h_" + name + __SAVE_EXTENSION__)<0 )
		return notify_fail("û����λʹ���ߡ�\n");
	if( (string)SECURITY_D->get_status(name)!="(player)" )
		return notify_fail("����ҵķ��ݵ������ܱ�ɾ����\n"); 

	rm(DATA_DIR + "playerhomes/h_" + name + __SAVE_EXTENSION__);
	write( "ʹ���� " + capitalize(name) + " �ķ��ݵ�����ɾ�����ˡ�\n");
	log_file("static/PURGE", sprintf("[%s] %s purged %s's house because %s.\n",
		ctime(time())[0..15], geteuid(this_player(1)), name, reason));

	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ��purgehouse <ʹ��������> because <ԭ��>

���һ��ʹ���ߵķ��ݵ�����
HELP
	);
    return 1;
}
