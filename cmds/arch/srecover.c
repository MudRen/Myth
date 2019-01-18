// recovers.c
// by mudring

#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        string name, reason;
        string path, status;

        if (! SECURITY_D->valid_grant(me, "(arch)"))
                return 0;

        status = wizhood(me); 
        path = me->query("env/backup");

        if (wiz_level(me) < wiz_level(status))
                return notify_fail("��û��Ȩ��ʹ�����ָ�\n");
//        if (! path) return notify_fail("û���������·����\n");
//        if (! arg) return notify_fail("û������û���\n");

        if (!arg || sscanf(arg, "%s because %s", name, reason)!=2)
                return notify_fail("recovers <id> because <xxx>��\n");
        seteuid(getuid());

		path = DATA_DIR;
		
        if( file_size(path + "login/" + name[0..0] + "/" + name + ".s.o")<0 )
                return notify_fail("û����λʹ���ߡ�\n");
        if( file_size(DATA_DIR + "login/" + name[0..0] + "/" + name + ".o")>0 )
                return notify_fail("���ID�Ѿ�������ע���ˡ�\n���һ��Ҫ�ָ�������Purge��\n");
        cp( path + "login/" + name[0..0] + "/" + name + ".s.o", DATA_DIR + "login/" + name[0..0] + "/" + name + ".o" );
        cp( path + "user/" + name[0..0] + "/" + name + ".s.o", DATA_DIR + "user/" + name[0..0] + "/" + name + ".o" );

        write( "ʹ���� " + capitalize(name) + " �ĵ����ָ��ˡ�\n");
        log_file("static/recovers", sprintf("[%s] %s suicide recovers %s because %s.\n",
                ctime(time())[0..15], geteuid(this_player(1)), name, reason));
        seteuid(getuid(me));
       return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ��recovers <ʹ��������> because <ԭ��>
HELP
        );
    return 1;
}

