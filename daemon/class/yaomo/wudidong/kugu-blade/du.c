// by iceland 
// changed by emnil     2/7/2000 
// changed by wuyou@sk_sjsh  Feb/25/2003 
// �齣���pfm�޸Ĺ����� 

#include <ansi.h> 
#include <combat.h> 
inherit F_SSERVER; 
 
#include <combat_msg.h> 
#include "du.h"; 

int perform(object me, object target) 
{ 
        string msg; 
        int times,p,damage,x,h,t,lx,i; 
        object weapon; 

        weapon = me->query_temp("weapon"); 
        x = me->query_skill("kugu-blade", 1)/4; 
        h = me->query_skill("blade", 1)/4; 

        if( !target ) target = offensive_target(me); 

        if( !target 
        ||!target->is_character() 
        ||target->is_corpse() 
        ||target==me) 
                return notify_fail("����Ī�趾��ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 

        if (!weapon)  return notify_fail("�������ʹ�ÿݹǵ���ʱ����ʩչ����Ī�趾����\n"); 

        t = weapon->query_amount(); 

        if (!PFM_D->valid_family(me, "�ݿ�ɽ�޵׶�"))
                return notify_fail("ֻ���޵׶����˲ſ����ã�\n");
                
        if (me->query_skill_mapped("blade") != "kugu-blade") 
                return notify_fail("����뼤���ݹǵ�������ʩչ����Ī�趾����\n"); 

        if(me->query_skill("kugu-blade", 1) < 410 ) 
                return notify_fail("��Ŀݹǵ�����������죬ʹ��������Ī�趾��������\n"); 

        if(me->query_skill("huntian-qigong", 1) < 400 ) 
                return notify_fail("��Ļ���������δ�ﵽ���磬�޷�ʹ������Ī�趾��������\n"); 

        if((int)me->query_skill("force") < 400 ) 
                return notify_fail("����ڹ��ȼ�������ʹ��������Ī�趾��������\n"); 

        if((int)me->query_str() < 40) 
                return notify_fail("�������������ǿ����ʹ��������Ī�趾��������\n");                      
                
        if((int)me->query("max_force") < 3000 ) 
                return notify_fail("��������Ϊ��ǳ��ʹ��������Ī�趾����\n");       
        
        if( (int)me->query("force") < 500 ) 
                return notify_fail("����������̫����ʹ��������Ī�趾����\n"); 
        
        msg = HIY"\n$NͻȻ���쳤���������������������������$nͷʹ���ͣ����з��겻�ѡ�$N˫Ŀ����զ�֣���΢���ٺ١�һЦ��������"+weapon->query("name")+HIY"��ת������ʹ����"+MAG"��Ī�趾"+HIY"��������\n"NOR; 
    

        t=5; 

        msg+= HIR"ֻ��"+weapon->query("name")+HIR"����˿˿�����������ȳ�����Ϊһ����ʰ�쵵Ķ���Я���������ɳ����ɽ�����㹥��$n��\n\n"NOR; 

        lx = me->query_skill("huntian-qigong",1)/5; 
        if(lx>50) lx = 50; 
        if(me->query_temp("apply/damage") >= 500 ) lx = lx/2; 

        msg += "\n"; 
        message_vision(msg, me, target); 

        me->add_temp("apply/strength", x); 
        me->add_temp("apply/blade", h);  
        me->add_temp("apply/attack",x*5 ); 
        me->add_temp("apply/damage", x*5);  

        if(wizardp(me) && me->query("env/test"))  
                tell_object(me,sprintf("lx:%d , str:%d , att:%d , damage:%d\n",lx,x,h,me->query_temp("apply/damage"))); 
        i = 0; 
        for (times=0;times<t;times++) 
        { 
                switch(times) 
                { 
                        case 0: 
                                msg=msga[random(sizeof(msga))]; 
                                if (random(me->query_skill("blade")) > target->query_skill("parry") /2 ) 
                                { 
                                        damage = (int)me->query_skill("kugu-blade",1) + (int)me->query_skill("huntian-qigong",1);  
                                        damage = damage + random(damage)*(100+lx)/100; 
                                        target->receive_damage("kee", damage, me, "pfm"); 
                                        target->receive_wound("kee", damage/2, me, "pfm"); 
                                        me->add("force", -80); 
                                        p = (int)target->query("kee")*100/(int)target->query("max_kee"); 
                                        msg += damage_msg(damage, "����"); 
                                        msg += "( $n"+eff_status_msg(p)+" )\n"; 
                                        if(wizardp(me) && me->query("env/test")) tell_object(me,sprintf("damage:%d   ",damage)); 
                                        i++; 
                                } 
                                else 
                                { 
                                        me->add("force", -30); 
                                        msg += msgd[random(sizeof(msgd))]; 
                                } 

                                message_vision(msg, me, target); 
                                break; 
                        case 1: 
                                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1); 
                                message_vision("\n",me); 
                                break; 
                        case 2: 
                                msg=msga[random(sizeof(msga))]; 
                                if (random(me->query("combat_exp")) > target->query("combat_exp") /2 ) { 
                                        damage = (int)me->query_skill("kugu-blade",1) + (int)me->query_skill("huntian-qigong",1); 
                                        damage = damage + random(damage)*(100+lx)/100; 
                                        target->receive_damage("kee", damage, me, "pfm"); 
                                        target->receive_wound("kee", damage/2, me, "pfm"); 
                                        me->add("force", -80); 
                                        p = (int)target->query("kee")*100/(int)target->query("max_kee"); 
                                        msg += damage_msg(damage, "����"); 
                                        msg += "( $n"+eff_status_msg(p)+" )\n"; 
                                        if(wizardp(me) && me->query("env/test")) tell_object(me,sprintf("damage:%d   ",damage)); 
                                        i++; 
                                } 
                                else 
                                { 
                                        me->add("force", -30); 
                                        msg += msgd[random(sizeof(msgd))]; 
                                } 

                                message_vision(msg, me, target); 
                                break; 
                        case 3: 
                                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1); 
                                message_vision("\n",me); 
                                me->add("force", -50); 
                                break; 
                        case 4: 
                                msg=msga[random(sizeof(msga))]; 
                                if ( random(me->query_con()+me->query_str())*2 > target->query_dex() ) { 
                                        if(!target->is_busy()) target->start_busy(2); 
                                        damage = (int)me->query_skill("kugu-blade",1) + (int)me->query_skill("huntian-qigong",1); 
                                        damage = damage/2 + random(damage)*(150+lx)/150; 
                                        target->receive_damage("kee", damage, me, "pfm"); 
                                        target->receive_wound("kee", damage/3, me, "pfm"); 
                                        me->add("force", -100); 
                                        p = (int)target->query("kee")*100/(int)target->query("max_kee"); 
                                        msg += damage_msg(damage, "����"); 
                                        msg += "( $n"+eff_status_msg(p)+" )\n"; 
                                        if(wizardp(me) && me->query("env/test")) tell_object(me,sprintf("damage:%d   ",damage)); 
                                } 
                                else 
                                { 
                                        me->add("force", -50); 
                                        msg += msgd[random(sizeof(msgd))]; 
                                } 
                                message_vision(msg, me, target); 
                                break; 
                } 
        } 

        if(me->query("force")<0) me->set("force",0); 

        msg=HIY"\n$N�����Ѿ������ò��յ����ˣ�������������������һ�㣬�ж���������ࡣ\n"NOR; 
        message_vision(msg, me, target);        
        
        me->add_temp("apply/strength", -x); 
        me->add_temp("apply/blade", -h);
        me->add_temp("apply/attack", -x*5 );
        me->add_temp("apply/damage", -x*5);
        me->start_busy(random(3)+1);
        return 1;  
}

