// whisper.c

#include <ansi.h>
#include "/cmds/std/block_tell.h";

inherit F_CLEAN_UP;
#include <localtime.h>

int main(object me, string arg)
{

        mixed lt = localtime(time());

        string dest, msg;
        object ob;

        if(!block_tell(me)) return 1;

        if( !arg || sscanf(arg, "%s %s", dest, msg)!=2 )
                return notify_fail("��Ҫ��˭����Щʲô��\n");

        ob = present(dest, environment(me));
        if( !ob || !ob->is_character() )
                return notify_fail("��Ҫ��˭���\n");

        write( CYN "����" + ob->name() + "�Ķ�������˵����" + msg + "\n" NOR);

        tell_room( environment(me), me->name() + "��" + ob->name()
                + "����С����˵��Щ����\n", ({ me, ob }) );
        if( !userp(ob) ) ob->relay_whisper(me, msg);
        else
                tell_object( ob, CYN + me->name() + "����Ķ�������˵����" + msg + "\n" NOR);
        return 1;
}

int help(object me)
{
        write( @TEXT
ָ���ʽ��whisper <ĳ��> <ѶϢ>

���ָ�����������ͬһ�����е��˶������ NPC ���ڡ�
TEXT
        );
        return 1;
}

