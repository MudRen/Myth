// maren.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
//        set("channel_id", "Ƶ������");
        if( duration < 1 ) {
        write(HIR"�۲����ѹ�������Ƶ������,ϣ�����ܸĹ����¡�\n"NOR);
                    me->delete("channel/chblk_on");
                       write(HIW"�������񻰡�Ƶ�����飺 "HIR+me->query("name")+"("+me->query("id")+")"+HIW" �Ĺ۲����������ָ�ʹ��Ƶ����Ȩ����\n"NOR,users());
                    // CHANNEL_D->do_channel( me, "sys",HIY+me->query("name")+"("+me->query("id")+")"+HIR" �ѱ���������Ƶ����\n"NOR);
        return 0;
        }
        me->apply_condition("maren", duration - 1);
        
        return 1;
}

string query_type(object me)
{
        return "sleep";
}


