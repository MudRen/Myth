//modify by wuyou@sk_sjsh 
//2003-7-28

#include <ansi.h>

inherit SSERVER;

string get_name(string str)
{
        str="��ǹ";
        return str;
}

string get_help(string str)                
{
        str="ָ������������\n"
        +"����������ǹ��100��"
        +"����������perform������һ�㡣";
        return str;
}

int perform(object me, object target)
{
        object weapon;
        int i,j,damage;
        weapon = me->query_temp("weapon");
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С���ǹ����\n");
                
        if (!PFM_D->valid_family(me, "���ƶ�"))
                return notify_fail("����ǹ��ֻ�л��ƶ����˲ſ����ã�\n");

        if(!me->is_fighting())
                return notify_fail("����ǹ��ֻ����ս����ʹ�ã�\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 200 )
                return notify_fail("����������㣡\n");
               
        if((int)me->query("sen") < 200 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
              
        if (me->query_skill_mapped("force")!="huomoforce")
                return notify_fail("��ǹ������ϻ�ħ�ķ�����ʹ�á�\n");
          


        i=(int)me->query_skill("huoyun-qiang",1)+(int)me->query_kar();

        if( i < 100)
                return notify_fail("��Ļ���ǹ���𻹲�����ʹ����һ�л������ѣ�\n");

        message_vision(HIR"\nֻ��$N��"+weapon->query("name")+HIR"�����˿���Ѫ,���һ��:��ǹ��\n"NOR, me, target);
        message_vision(HIR"$NͻȻ�����о�ǹб���Ͼ���Ȼ���ڰ���л���һ
��Բ�����漴��ֱб�±���$n����һ˲�䣬$nֻ���ú�����ֹͣ�ˣ�\n"NOR, me, target);

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 ) 
        {
                me->start_busy(random(2));                               
                target->start_busy(1);          
               
                damage = (int)me->query_skill("huoyun-qiang", 1)+(int)me->query_skill("spear", 1 )/2;
                damage = damage/2 + random(damage);

                target->receive_damage("kee", damage, me, "pfm");
                target->receive_wound("kee", damage/2, me, "pfm");
                message_vision(RED"ֻ��$n��$Nһǹ���У���ǰ�ѿ�һ��������˿ڣ�Ѫ��������������\n"NOR, me, target);
        } 
        else 
        {
                message_vision(HIC"����$n��æ����㿪��$N����û�еóѡ�\n" NOR, me, target);
                me->start_busy(1+random(2)) ;                                                 
        }

        me->delete("env/brief_message");
        target->delete("env/brief_message");

        me->set_temp("HYQ_perform", 8);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("HYQ_perform");

        me->receive_damage("sen", random(100));
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        return 1;
}

