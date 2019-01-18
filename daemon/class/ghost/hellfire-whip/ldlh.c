//write by yesi

#include <ansi.h>

inherit SSERVER;
void check_fight(object me);
void remove_effect(object me);


int perform(object me, object target)
{
        object weapon;
        int i,j;
                        
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
        {
                if(me->query_temp("ldlh")) 
                {
                        remove_effect(me);
                        return 1;
                }
                else  return notify_fail("��Ҫ��˭ʩչ�������ֻء���\n");}
        
        if(time()-(int)me->query_temp("ldlh_end") < 10) 
                return notify_fail("����Ƶ�����롸�����ֻء���\n");

        
        if(me->query_temp("ldlh")) 
                return notify_fail("������ʹ�á������ֻء���\n"); 
        
            
        if(!me->is_fighting())
                return notify_fail("�������ֻء�ֻ����ս����ʹ�ã�\n");

        if (!PFM_D->valid_family(me, "���޵ظ�"))
                return notify_fail("[�����ֻ�]�����޵ظ�����֮�ܣ�\n");
        
        if((int)me->query("force") < 1000 )
                return notify_fail("�������������\n");

        if((int)me->query("kee") < 300 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");
        
        if (me->query_skill_mapped("force")!="tonsillit")
                return notify_fail("�������ֻء������������������ʹ�á�\n");
              
        if (me->query_skill_mapped("spells")!="gouhunshu")
                return notify_fail("�������ֻء�������Ϲ���������ʹ�á�\n");
        
        if((int)me->query_skill("hellfire-whip", 1) < 150)
                return notify_fail("����һ�޼��𻹲�����ʹ����һ�л������ѣ�\n");
        
        if((int)me->query_skill("gouhunshu", 1) < 100)
                return notify_fail("��Ĺ��������𻹲����������ˡ������ֻء�����\n");
        
        weapon=me->query_temp("weapon");
        
       
        message_vision(HIW"\n$N���������дʣ����������ܣ����������ܣ������������ҹ����������ٶ��ֻء�\n"NOR,me);
        me->set_temp("lunhui",0);
        me->set_temp("ldlh",1);
        me->set_temp("ldlh_time",60+random((me->query_skill("force")+me->query_skill("whip"))/6));
        
        call_out("check_fight", 1, me);
        return 1;
}


void check_fight(object me)
{
        object weapon;
        if(!me) return;        
        if( !objectp(weapon=me->query_temp("weapon")) ||
                (weapon->query("apply/skill_type") != "whip" &&
                weapon->query("skill_type") != "whip" ) || 
                me->query_skill_mapped("whip") != "hellfire-whip" ||
                me->query_skill_mapped("force") != "tonsillit" ||
                me->query_skill_mapped("spells") != "gouhunshu" ) 
                remove_effect(me);
        else if(me->query_temp("ldlh_time")<1)
                remove_effect(me);              
        else {  
                me->add_temp("ldlh_time",-1);
                call_out("check_fight", 1, me);
             }
}



void remove_effect(object me)
{       if(!me) return;
        remove_call_out("check_fight");
        me->delete_temp("ldlh");
        me->delete_temp("lunhui");
        message_vision(HIW"$N�ӡ������ֻء����˳�����\n"NOR, me);
        me->set_temp("ldlh_end", time() );
}


