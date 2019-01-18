#include <ansi.h>

inherit SSERVER;
void remove_effect(object target,object me);

int cast(object me, object target)
{
        string msg;
        int success, ap, dp, ap2, ap3, ap4, dp2, dp3, dp4,howlong,npc_chance;
        int xk;
        object weapon=me->query_temp("weapon");
        object qingwang;


        if (!weapon || weapon->query("skill_type")!="whip")
                return notify_fail("û�б��ӣ�����ʲô֯��������\n");
        if (me->query_skill_mapped("whip")!="jueqingbian")
                return notify_fail("��û���þ���ޣ�ʹ����������\n");

        if((int)me->query_skill("spells") < 150 || 
           (int)me->query_skill("moonshentong",1) < 100 ||
           (int)me->query_skill("jueqingbian",1)<100 ||
           (int)me->query_skill("whip")<150)
                return notify_fail("�㻹����������������\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("�����˭ʹ��������\n");  

        if(me->query_temp("qingwang"))
                return notify_fail("���Ѿ�����һ�����ˣ�\n");  

        if((int)me->query("mana") < 200 )
                return notify_fail("��ķ���������\n");

        if((int)me->query("sen") < 10 )
                return notify_fail("���޷����о�����\n");

        me->add("mana", -200);
        me->receive_damage("sen", 10);

        message_vision(HIB"$N�߶�������������"+weapon->name()+"���һ�ţ�����һ�Ŵ�������$n��ͷ������\n"NOR,me,target);

        success = 1;
        ap = me->query_skill("spells");
//        ap = ap * ap * ap /12 ;
        ap = ap * ap * ap /8 ;
        ap += (int)me->query("daoxing");
        dp = target->query("daoxing");

        ap2 = (int)me->query_skill("jueqingbian",1);
        dp2 = (int)target->query_skill("dodge",1);
        ap3 = (int)me->query("mana");
        dp3 = (int)target->query("mana");
        ap = ap + 2000*ap2+200*ap3;
        dp = dp+2000*dp2+200*dp3;

        xk=SPELL_D->check_xiangke(me, target);

        if( random(ap+dp)<dp) success = 0;

        if(success == 1 )
        {
                message_vision(HIB"$N������һƬ���ң���ʹ����ͻȻ���������������˶�������������ͷ��ס��\n"NOR,target);
                howlong = random(me->query_skill("jueqingbian",1)+me->query_skill("moonshentong",1))/10+5;
                if(howlong>60) howlong=60;

                seteuid(getuid());
                qingwang=new("/d/obj/fabao/qingwang");
                qingwang->set("target",target);
                qingwang->set("owner",me);
                qingwang->set("weapon",weapon);
                me->set_temp("qingwang",qingwang);
                qingwang->set("time_expired",time()+howlong);
                if (!qingwang->move(environment(target))) 
                {
                        message_vision(HIY"$N���Ϸ���һ�������⣬���������ķ��顣\n"NOR,target);
                        destruct(qingwang);
                }
                if ((!userp(target)) && npc_chance=target->query("chat_chance_combat")) 
                {
                        target->set_temp("chat_chance_combat",npc_chance);
                        target->delete("chat_chance_combat");
                        call_out("remove_effect",howlong,target,me);
                }
        } 
        else 
        {
                message_vision(HIG"$N�������ѣ���Ϊ����������������һԾ�������������Ϯ����\n"NOR,target);
                me->start_busy(random(2));
                if( living(target) ) target->kill_ob(me);
        } 

        return 3+random(5);
}
        
void remove_effect(object target,object me) 
{
        if (me->query_temp("qingwang")) destruct(me->query_temp("qingwang"));
        if (!target) return;
        target->set("chat_chance_combat",target->query_temp("chat_chance_combat"));
}

