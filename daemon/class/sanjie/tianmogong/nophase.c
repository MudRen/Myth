// nophase.c ��ɫ����
// writted by mind 2001/2

inherit SSERVER;
#include <ansi.h>

int cast(object me)
{
        int howlong;
        int spell;
        spell=me->query_skill("spells")/2 + me->query_skill("tianmogong");
 //       if(!me->query("m_success/��ɫ��"))
 //               return notify_fail("�㻹ûѧ����ɫ���ࡣ������\n");
        if( (string)me->query("family/family_name")!="����ɽ")
                return notify_fail("�������ɽ����Ե��ϰ��ɫ���ࡣ\n");
        if(spell < 100)
                return notify_fail("�㷨����Ϊ̫ǳ��\n");

        if( (int)me->query("mana") < 2*(int)me->query_skill("spells"))
                return notify_fail("��ķ��������ˣ�\n");

        if( (int)me->query("sen") < 50 )
                return notify_fail("��ľ����޷����У�\n");

        message_vision("$N���˿����ܵĻ�����Ĭ����ӱ�ɫ����õ���ɫ���෨����\n", me);

        if( random(me->query("max_mana")) < 100 ) {
                me->add("mana",-(int)me->query_skill("spells"));
                me->receive_damage("sen",10);
                message("vision", "����ʲôҲû�з�����\n", environment(me));
                return 5+random(5);
        }

        me->add("mana", -2*(int)me->query_skill("spells"));
        me->receive_damage("sen", 20);

        howlong = 10 + random((me->query_skill("spells") -100));
   if( howlong <1 && howlong >120) howlong=121;
        if (!me->query("env/invisibility"))
                call_out("free", howlong, me, howlong);
        me->set_temp("nophasetime", howlong+(int)me->query_temp("nophasetime"));

        me->set("env/invisibility", 1);
        me->set_temp("no_heal_up/nophase",1);
        
        message_vision(HIB"\nƾ����ʧ��$N���ټ����ޡ�\n\n"NOR, me);
        
        return 5+random(5);
}

void free(object user, int howlong)
{
        if(!user) return;
        if (!user->query("env/invisibility")) return;
        if (user->query_temp("nophasetime") - howlong) {
                user->set_temp("nophasetime", 
                        user->query_temp("nophasetime") - howlong);
                call_out("free", user->query_temp("nophasetime"), 
                        user, user->query_temp("nophasetime"));
                return;
                }
        user->delete_temp("nophasetime");
        user->set("env/invisibility", 0);      
        user->save();
        message_vision(HIB"\nƾ���ֶ���$N���Ρ�\n\n"NOR, user);
        user->delete_temp("no_heal_up/nophase");
        return;
}



