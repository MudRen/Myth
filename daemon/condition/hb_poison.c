// hb_poison.c ��������

#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
         if(!living(me)) {
                 message("vision", HIB+me->name() + "����ֽŶ��ѷ�ֱ��\n"NOR, environment(me), me);
         }
         else {
                 tell_object(me, HIB "��Ȼһ��̹ǵ��溮Ϯ�������еĺ��������ˣ�\n"NOR);
                 message("vision",HIB + me->name() + "�����������ȫ������һ�ţ��ֽŽ�Ӳ��\n"NOR,environment(me), me);
         }
         me->receive_damage("kee", 35);
         me->receive_wound("sen", 30);
         me->receive_wound("kee", 30);         
         me->set_temp("death_msg","�к����������ˡ�\n");
         me->apply_condition("hb_poison", duration - 1);
         if( duration < 1 ) return 0;
         return CND_CONTINUE;
}

string query_type(object me)
{
         return "poison";
}
