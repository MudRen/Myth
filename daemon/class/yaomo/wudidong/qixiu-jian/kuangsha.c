//�޵׶�-���޽���ѧ����ɱն 
//by junhyun@SK 

#include <ansi.h> 
#include <combat.h> 
inherit SSERVER; 

void kuang_ok(object); 

int perform(object me, object target) 
{ 
        int damage,damagea,extra; 
        
        if( !target ) target = offensive_target(me); 
        
        if( !target 
        ||      !target->is_character() 
        ||      target->is_corpse() 
        ||      target==me) 
                return notify_fail("��Ҫ��˭ʩչ��һ�С���ɱն����\n"); 
                
        if (!PFM_D->valid_family(me, "�ݿ�ɽ�޵׶�"))
                return notify_fail("����ɱն��ֻ���޵׶����˲ſ����ã�\n");
        
        if(!me->is_fighting()) 
                return notify_fail("����ɱն��ֻ����ս����ʹ�ã�\n"); 
        
        if((int)me->query("max_force") < 300 )  
                return notify_fail("�������������\n"); 
                
        if((int)me->query("force") < 300 ) 
                return notify_fail("����������㣡\n"); 

        if((int)me->query("sen") < 100 ) 
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n"); 
        
        if((int)me->query_skill("dodge", 1) < 120) 
                return notify_fail("��Ļ����Ṧ������죬ʹ����һ�л������ѣ�\n");    
        
        if((int)me->query_skill("yinfeng-zhua", 1) < 120) 
                return notify_fail("�������צ������죬ʹ����һ�л������ѣ�\n");             

        if((int)me->query_skill("qixiu-jian", 1) < 120) 
                return notify_fail("������޽�������������ʹ����һ�л������ѣ�\n"); 

        if(me->query_temp("no_kuang")) 
                return notify_fail("���۲��۰�����Ϣһ�°ɣ�\n"); 
                
        if( time()-(int)me->query_temp("qijian_end") < 4 )    
                return notify_fail(CYN"[��ɱն]��[�����߽�]��������ʹ�ã�\n"NOR);  
       
        me->delete("env/brief_message"); 
        target->delete("env/brief_message"); 

        extra=(int)me->query_skill("qixiu-jian");  
        //damagea=random((int)me->query_skill("dodge")); 
        damagea=(int)me->query_skill("dodge"); 
        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp")) 
        { 
                message_vision(HIR"$N����ɱ�����֣�һ����Х�������������ֶ���������Ծ���� 
�������������ߣ�$N˫צ���ɣ���ȫ��û�ڽ���צ��֮�С�\n"NOR,me,target); 
                target->receive_damage("kee", damagea, me, "pfm"); 
                target->receive_wound("kee", damagea/2, me, "pfm"); 
                target->receive_damage("sen", damagea/3, me, "pfm"); 
                target->start_busy(2); 
                COMBAT_D->report_status(target); 
        } 
        else 
        { 
                message_vision(HIR""NOR,me,target); 
        } 
        message_vision(HIW"צ�����ԣ��������죬�����ݿ�ɽ�޵׶����޾�ѧ����ɱն\n"NOR,me,target); 
        message_vision(HIR"��������צ�����������$N�Ĺ�������һ�����εĴ���һ�㡣\n"NOR,me,target); 
        me->add_temp("apply/attack",extra); 
        me->add_temp("apply/damage",extra); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        me->add_temp("apply/attack",-extra); 
        me->add_temp("apply/damage",-extra); 
        damage=(int)me->query_skill("sword")+random((int)me->query_skill("parry")); 
        if(random((int)target->query("combat_exp"))<(int)me->query("combat_exp")) 
        { 
                message_vision(HIR"��ʱ��$n��$N�Ŀ�ɱն���ı������ˣ�����û�з���������....\n"NOR,me,target); 
                target->receive_damage("kee",damage/2,me,"pfm"); 
                target->receive_wound("kee",damage/2,me,"pfm"); 
                COMBAT_D->report_status(target); 
        } 
        else 
        { 
                message_vision(HIW"$n���Ʋ����æ���ȥ�����ŵ���ƽƽ�ķ��˳�ȥ����ǿ�ܹ���һ�С���\n"NOR,me,target); 
        } 
        me->receive_damage("sen", 30); 
        me->add("force", -100); 
        me->set_temp("no_kuang",1); 
        call_out("kuang_ok",2+random(2),me); 
        if( !target->is_fighting(me) ) { 
                if( living(target) ) { 
                        if( userp(target) ) target->fight_ob(me); 
                        else target->kill_ob(me); 
                } 
        } 
        return 1; 
} 
 
void kuang_ok(object me) 
{ 
        if (!me) return; 
        me->delete_temp("no_kuang"); 
} 


