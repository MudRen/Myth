// modified by vikee for xlqy
// 2000-11-26 11:08
// reply.c

#include <ansi.h>
#include <net/dns.h>
#include "/cmds/std/block_tell.h";
#include <localtime.h>

inherit F_CLEAN_UP;
#define DEBUG "xjh"
#ifdef DEBUG
void debug(string x)
{
    object monitor;
    if (!stringp(x) || !stringp(DEBUG))     return;
    monitor=find_player(DEBUG);
    if(monitor && monitor->query("env/debug"))     tell_object(monitor,x+"\n");
}
#else
#define debug(x)
#endif

object find_player(string target)
{
        int i;
        object *str;
        str=users();
        for (i=0;i<sizeof(str);i++)
                if (str[i]->query("id")==target)
                        return str[i];
        return 0;
}
int help(object me);
void create() {seteuid(getuid());}

int main(object me, string arg)
{
        mixed lt = localtime(time());
        string target, mud;
        object obj;

        if(!block_tell(me)) return 1;

        if( !arg || arg=="" )
                return notify_fail("��Ҫ�ش�ʲô��\n");

        if( !stringp(target = me->query_temp("reply")) )
                return notify_fail("�ղ�û���˺���˵������\n");

        if( sscanf(target, "%s@%s", target, mud)==2 ) {
                GTELL->send_gtell(lower_case(mud), lower_case(target), me, arg);
                write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
                return 1;
        }

        obj = find_player(target);
        if( !obj ) return notify_fail(
          "�ղź���˵�����������޷������㣬�����Ѿ��뿪��Ϸ�ˡ�\n");
          
        if(!living(obj) || !interactive(obj)) 
          return notify_fail(obj->name(1)+"������������˵�Ļ���\n");
debug(sprintf( YEL "%s(%s)�ش�%s(%s)��%s" NOR,me->name(1),me->query("id"),obj->name(1),obj->query("id"), arg));             
write(HBBLU "��ش�" + obj->name(1) + "��" + arg + "\n" NOR);
        tell_object(obj, sprintf(HBBLU"%s�ش��㣺%s\n"NOR,
                me->name(1), arg ));

        obj->set_temp("reply", me->query("id"));
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ��reply|huida <ѶϢ>

����������ָ��͸ղ��� tell ����˵����ʹ����˵����

see also : tell
HELP
        );
        return 1;
}

