//qianghun.c
//����ǹ��
//Created by wuyou@sk_sjsh
//2003-8-12

#include <ansi.h>

inherit SSERVER;

void npc_attack( object invoker, object target, string npc, object where );

string npc_dir = "/obj/npc/shanshen";

int perform(object me, object target)
{
        string msg;
        object weapon, where; 
        int damage, ap, dp, i;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(CYN"��Ҫ��˭ʩչ������ǹ�꡹��\n"NOR);

        if(!me->is_fighting()) 
                return notify_fail(CYN"������ǹ�꡹ֻ����ս����ʹ�ã�\n"NOR); 
        
        if( !PFM_D->valid_family(me, "���ƶ�"))
                return notify_fail(CYN"������ǹ�꡹�ǻ��ƶ�����֮���գ�\n"NOR);
            
        if( (string)me->query_skill_mapped("force")!="huomoforce")
                return notify_fail(CYN"��������û�ħ�ķ������ٻ�������ǹ�꡹��\n"NOR);

        if( (int)me->query("force") < 250+(int)me->query("force_factor") )
                return notify_fail(CYN"����������㣬�ٻ�����������ǹ�꡹��\n"NOR);

        if( me->query("max_force") < 3000 )
                return notify_fail("���������Ϊ��ǳ���������á�����ǹ�꡹��\n"NOR);
                
        if( (int)me->query("mana") < 250 )
                return notify_fail(CYN"��ķ������㣬�ٻ�����������ǹ�꡹��\n"NOR);

        if( me->query("max_mana") < 3000 )
                return notify_fail("��ķ�����Ϊ��ǳ���������á�����ǹ�꡹��\n"NOR);                   

        if( (int)me->query("kee") < 200 || (int)me->query("sen") < 200  )
                return notify_fail(CYN"������̫�����ˣ��޷�ʩչ������ǹ�꡹��\n"NOR);

        if( time()-(int)me->query_temp("qianghun_end") < 4 ) 
                return notify_fail(CYN"��������Ϣ��δƽ�������ô˾���������Ԫ����\n"NOR); 
        if( time()-(int)me->query_temp("buhui_end") < 2)    
                return notify_fail(CYN"�����ڡ��롸����ǹ�꡹�޷�����ʹ�ã�\n"NOR);                          
        if( (int)me->query_skill("wuyue-spear", 1) <400 )
                return notify_fail(CYN"���������ǹ�������죬�޷�ʹ�����С�����ǹ�꡹��\n"NOR);
                
        if( (int)me->query_skill("spear", 1) <400 )
                return notify_fail(CYN"��Ļ���ǹ���������죬�޷�ʹ�����С�����ǹ�꡹��\n"NOR);           

        if( (int)me->query_skill("huomoforce", 1) <400 )
                return notify_fail(CYN"��Ի�ħ�ķ�������ǳ������ʹ��������ǹ�꡹��\n"NOR);
                
        msg = HIY "\n$N�־�"+ weapon->query("name")+ HIY"ֱָ���죬���쳤Х��"HIW"������ɽ�����ҳ�ħ����\n"NOR;            
        msg += HIY "\nХ���հգ�����һ������ֱ��ǹ�⣬�û���һ��Ѥ�õĹ�â��\n\n" NOR;
        msg += HIR "          ������                          ������\n"NOR;
        msg += HIR "          ��"HIW"�v"HIR"�� ������������������������ ��"HIW"��"HIR"��\n"NOR;
        msg += HIR "          ��"HIW"�M"HIR"�� ��"HIW"��"HIR"����"HIW"�["HIR"����"HIW"��"HIR"����"HIW"��"HIR"�� ��"HIW"��"HIR"��\n"NOR;
        msg += HIR "          ��"HIW"��"HIR"�� ������������������������ ��"HIW"�o"HIR"��\n"NOR;   
        msg += HIR "          ��"HIW"�["HIR"��                          ��"HIW"��"HIR"��\n"NOR;
        msg += HIR "          ������                          ������ \n"NOR;
        
        ap = me->query_skill("wuyue-spear", 1);
        ap = ( ap * ap * ap / (4 * 400) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = ( dp * dp * dp / (4 * 300) );
        dp = dp*250 + target->query("combat_exp");      
        
        if( random((ap + dp)/200) >  dp/1000 )
        {
                msg += HIY "\n����һ�������⽫$n���֣�$n�������ܶ�����\n"NOR;
                msg += HIY "$N���е�"+ weapon->query("name")+ HIY"����һ�����磬����$n�����壡\n"NOR;
                
                damage = (int)me->query_skill("spear",1) / 2 + (int)me->query_skill("wuyue-spear",1) / 2
                + random((int)me->query_skill("huomoforce",1) / 2) + random((int)me->query_skill("pingtian-dafa",1) / 2)
                + (int)me->query("str") + me->query("force_factor");
                
                if(!target->is_busy())
                        target->start_busy(2);
                        
                target->receive_damage("kee", damage, me, "pfm");
                target->receive_wound("kee", damage, me, "pfm");   
                target->receive_damage("sen", damage/2, me, "pfm");
                target->receive_wound("kee", damage/2, me, "pfm"); 
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);                                
                
                me->add("force", -100-(int)me->query("force_factor"));
                me->receive_damage("kee", 100);                
        }
        else 
        {
                if (random(2)==1)
                {
                        msg += HIY "\n˲�䣬����ɽ��������$n����ǰ����$n����������\n"NOR;
                        message_vision(msg, me, target); 
                        where=environment(target);
                        for(i=1;i<=5;i++)
                        {
                                call_out("npc_attack", 1, me, target, npc_dir+i, where);
                        }
                        me->add("mana", -200);
                        me->receive_damage("sen", 100);  
                }
                else
                {
                        msg += HIY "\n$n��δ�����ٻ���"HIR"������ǹ�꡹"HIY",����$N����������$N���ò���ǹ��ӭ��\n"NOR;
                        message_vision(msg, me, target); 
                        me->receive_damage("kee", 20);  
                        me->receive_damage("sen", 20); 
                        me->add("force", -20);
                }
        }
        
        me->set_temp("qianghun_end",time());
        return 1;
       
}
                        
void npc_attack(object invoker, object target, string npc, object where)
{
        object attacker;
        int rd;
        string tid;

        if(!invoker || !target) return;

        if( environment(invoker) != environment(target) ) return;
        if( environment(target) != where) return;

        seteuid(getuid());
        attacker = new(npc);
        attacker->move(environment(invoker));

        COMBAT_D->do_attack(attacker, target, attacker->query_temp("weapon"));
        
        // give the killing credit to the invoker.
        // so this would be counted as PK if the invoker is user.

        if(target->query_temp("last_damage_from")==attacker)
                target->set_temp("last_damage_from", invoker);
        
        if(target->query_temp("last_fainted_from")==attacker)
                target->set_temp("last_fainted_from", invoker->query("id"));
        
        destruct(attacker);
}
                             
