// to.c
// mudring ����������

// inherit F_CLEAN_UP;
// Don't want this command be cleaned up while typing long string.

#include "valid_system.h"
int main(object me, string arg)
{
    string *allowed = ({
      "describe",
    });

    if (me != this_player()) return 0;
    if (!valid_system(me)) return 0;
    if (!arg) return notify_fail("��������ȷ��\n");
    if (member_array(arg, allowed) == -1 &&
        !wizardp(me))
            return notify_fail("������ʹ�����������\n");
    me->edit( (: call_other, this_object(), ({ "do_to", me, arg }) :) );
    return 1;
}

void do_to(object me, string arg, string str)
{
	seteuid(getuid());
	if(arg) me->force_me(arg + " " + str);
	else me->force_me(str);
}

int help(object me)
{
write(@HELP
ָ���ʽ : to <ָ��>

����һ������������ϵ�����, <ָ��>ͨ�������ѶϢ��ָ����
say��tell��describe��chat�������ȡ�
���磺 
>to say
�����뿪�� '.'��ȡ�������� '~q'��ʹ���ڽ��б༭���� '~e'��
����������������������������������������������������������

          �ԡԡԡԡԡԡԷ����ԡԡԡԡԡԡ�
            �����Ǿ� С��ͯ kuer             
            �����Ǿ� ������� miner          
            �����Ǿ� ��ʯ san                
            ľ���Ǿ� ɽˮ wen                
            ˮ���Ǿ� С¥ pxl                
            �����Ǿ� �׸���� hengha         
            �����Ǿ� СӢ nonn               
          �ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�
.

�����ӫĻ�ϵĽ������ :

��˵����
          �ԡԡԡԡԡԡԷ����ԡԡԡԡԡԡ�
            �����Ǿ� С��ͯ kuer             
            �����Ǿ� ������� miner          
            �����Ǿ� ��ʯ san                
            ľ���Ǿ� ɽˮ wen                
            ˮ���Ǿ� С¥ pxl                
            �����Ǿ� �׸���� hengha         
            �����Ǿ� СӢ nonn               
          �ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�

HELP
    );
    return 1;
}

