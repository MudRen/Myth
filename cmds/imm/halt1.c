// halt.c

#include "/doc/help.h"
inherit F_CLEAN_UP;

int main(object me, string arg)
{
       if (me != this_player()) return 0;
     if (! SECURITY_D->valid_grant(me, "(immortal)")) return 0;
        if( !me->is_fighting() )
                return notify_fail("�����ڲ�û����ս����\n");
        me->remove_all_killer();
        message_vision("$N����ʦ������ֹͣ���ⳡ�򶷡�\n", me);
        write("Ok.\n");
        return 1;
}

int help(object me)
{
   write(@HELP
ָ���ʽ: halt

����ֹͣ���������йص�ս����
HELP
   );
   return 1;
}
