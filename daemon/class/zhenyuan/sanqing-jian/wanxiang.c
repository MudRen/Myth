//Created by Wuyou@Sanjie

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage, ap, dp, size, num, extra, i;
        object weapon;
        weapon = me->query_temp("weapon");
        extra=(int)me->query_skill("sanqing-jian", 1);
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(WHT"��Ҫ��˭ʩչ"RED"����������"WHT"��\n"NOR);
        if( !me->is_fighting(target) )
                return notify_fail(RED"����������"WHT"ֻ����ս��ʹ�á�\n"NOR);
        if (!PFM_D->valid_family(me, "��ׯ��"))
                return notify_fail(RED"����������"WHT"����ׯ�۾�����\n");                        
        if (me->query_skill_mapped("force")!="zhenyuan-force")
                return notify_fail(WHT"ֻ������Ԫ�񹦲�������"RED"����������"WHT"��\n"NOR);
        if (me->query_skill("sanqing-jian",1)<100)
                return notify_fail(WHT"������彣���������죬���ü���Ŭ����\n"NOR);     
        if (me->query_skill("zhenyuan-force",1)<100)
                return notify_fail(WHT"�����Ԫ�񹦲������죬���ü���Ŭ����\n"NOR);
        if (me->query_skill("taiyi",1)<100)
                return notify_fail(WHT"���̫���ɷ��������죬���ü���Ŭ����\n"NOR);                                          
        if (me->query_skill("baguazhen",1)<100)
                return notify_fail(WHT"��İ����󷨲������죬���ü���Ŭ����\n"NOR);                     
        if((int)me->query("force") < 300 )
                return notify_fail(WHT"����������㡣\n"NOR);
        if( me->query("max_force") < 1000 )
                return notify_fail(WHT"���������Ϊ��ǳ����������"RED"����������"WHT"��\n"NOR);  
        if( me->query("max_mana") < 1000 )
                return notify_fail(WHT"��ķ�����Ϊ��ǳ����������"RED"����������"WHT"��\n"NOR);                                        
        if( (int)me->query("kee") < 200 || (int)me->query("sen") < 200  )
                return notify_fail(WHT"������̫�����ˣ��޷�ʩչ"RED"����������"WHT"��\n"NOR);
        if( time()-(int)me->query_temp("wanxiang_end") < 4 ) 
                return notify_fail(WHT"��������Ϣ��δƽ�������ô˾���������Ԫ����\n"NOR); 
                                
        msg = HIY "\n$N��"HIR"̫���ɷ�"HIY"���������ޣ������ʱ�������ơ�$N��˫��Խ��Խ������ǵص�����$n��\n"
             +"$n��$N��˫����ȥ��ֻ�����������ܲ�����ת���ƣ�����"HIW"���������"HIY"һ�㡣\n" NOR,
      
        me->add("sen", -50);
        me->add("kee", -50);
        me->add("force", -50);
        ap =(int)me->query_skill("sanqing-jian", 1)+(int)me->query_skill("taiyi", 1);
        damage=ap*ap/300;
        ap = ap * ap * ap /10;
        ap = ap + (int)me->query("combat_exp");
        dp =  (int)target->query_skill("parry")
             +(int)target->query_skill("spells");
        dp = dp * dp * dp /10;   
        dp = dp + (int)target->query("combat_exp");
        if( random(7000*ap/dp) <  20 ) 
        {
                msg += HIW "$n����"HIY"��ׯ��"HIR"̫���ɷ�"HIW"�е�"HIC"������Ǭ����"HIW"��ͬ���죬��æ���λ�λ��ƮȻ���ˡ�"
                    +"$N��˫����գ���̾��Ϊ��ǳ��\n"NOR;
                message_combatd(msg, me, target, "");
        } 
        else if( random(7000*ap/dp) <  40 ) 
        {
                msg += HIY "$n����������������ǰӭ���������$N��˫��ɨ��ͷ������ʱͷʹ���ѣ���ð���ǡ�\n"NOR;
                message_combatd(msg, me, target, "");
                target->receive_damage("kee",damage/2,me,"pfm");
                target->receive_wound("kee",damage/2,me,"pfm");
                COMBAT_D->report_status(target); 
                if(!target->is_busy()) 
                        target->start_busy(random(2));
        } 
        else 
        {
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage,me,"pfm");
                msg += HIW "$n��ã������"HIR"��õ������ǳ�"HIW"����$N��˫���ָ����ţ����������ܶ���������һƬ���֮�С�\n"NOR;
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target); 
                target->start_busy(3+random(3));

        }

        if (me->query_skill("sanqing-jian",1)>119)
        {
                
                me->add_temp("apply/attack", extra);
                me->add_temp("apply/damage", extra);            
/*              
                mapping dao= ([
                "damage": 200,
                "dodge" : -10,
                "parry" : -10,
                "damage_type" : "����",
                "action" :  MAG"$N���һ����ʹ��һ��"HIM"�������ã��"MAG"��˫�ֽ���$w
���ű��˵�ɱ��������$n��$l",
                ]);
                
                me->set("actions",dao); 
*/              
                msg = WHT "          ����������Ϊ��������\n"NOR;        
                msg += WHT "$N�趯����"+weapon->name()+
     WHT"���Խ�������ʹ��"HIR"��赶��"WHT"�����е������Ѷ��ֿ����ۻ����ң�Ŀ�ɿڴ���\n"NOR;
                message_combatd(msg, me, target, "");
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));      
/*              
                me->reset_action();
                
                mapping chui= ([
                "damage": 200,
                "dodge" : -10,
                "parry" : -10,
                "damage_type" : "����",
                "action" :  HIC"$Nʹ����һ��"HIG"���嶡��ɽ��"HIC"�����е�$w�������ᣬ�����転����$n$l������ȥ",
                ]);
                
                me->set("actions",chui);        
*/              
                msg = HIY "          ����������Ϊ��������\n"NOR;        
                msg += HIY "$N�趯����"+weapon->name()+
     HIY"���Խ�������ʹ��"HIR"��ɽ����"HIY"�����е������Ѷ��ֿ����ۻ����ң�Ŀ�ɿڴ���\n"NOR;
                message_combatd(msg, me, target, "");
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));      
/*
                me->reset_action();
                
                mapping zhang= ([
                "damage": 200,
                "dodge" : -10,
                "parry" : -10,
                "damage_type" : "����",
                "action" :  HIW"$Nʹ��һ��"HIY"��Ⱥħ���ס�"HIW"�����е�$w������ɳ��ʯ����ȷ�ѹ��$n��$l",
                ]);
                
                me->set("actions",zhang);       
*/              
                msg = HIG "          ����������Ϊ�ȡ�����\n"NOR;        
                msg += HIG "$N�趯����"+weapon->name()+
     HIG"���Խ����ȣ�ʹ��"HIW"��ħ�ȷ�"HIG"�����е������Ѷ��ֿ����ۻ����ң�Ŀ�ɿڴ���\n"NOR;
                message_combatd(msg, me, target, "");
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));      
//              me->reset_action();             
                
                
                me->add_temp("apply/attack", -extra);
                me->add_temp("apply/damage", -extra); 
        }
        
        if (me->query_skill("sanqing-jian",1)>149)
        {
                msg = HIR "$N�����������"HIY"����ֻأ�������ת�����й�λ�������һ��"HIR"��\n"NOR;
                msg += HIR "$N˫��֮��ͻȻ���������"HIY"��м"HIR"����ֱ����$n��\n"NOR;
                
                me->add("force",150);
                if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5 ) 
                {       
                        msg += HIR "��Щ"HIY"��м"HIR"��$n�������У�$n�������Ŀȫ�ǡ�\n"NOR;
                        message_combatd(msg, me, target, "");
                        size=(int)(me->query_skill("sanqing-jian")/5);
                        damage=random(size)+size;
                        damage=damage+me->query_str()+random(me->query_temp("apply/damage"));
                        num=size/5+random(size/5);
                        for(i=0;i<=num;i++)
                        {
                                target->receive_damage("kee",damage,me,"pfm");
                                target->receive_wound("kee",damage,me,"pfm");
                        }
                        COMBAT_D->report_status(target);                
                }
                else
                {
                        msg += HIY "$n���ĺ��˶�������������������У�����ֹ��м�����롣\n"NOR;
                        message_combatd(msg, me, target, "");
                }
        }
                
        me->set_temp("wanxiang_end",time());
        return 1;
}


