#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon;
        int myskill,times, damage;
        string number;
        myskill = (int)me->query_skill("xuantian-sword", 1);  
        weapon = me->query_temp("weapon");
     
        if( !target ) target = offensive_target(me);
        
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С����޵�������\n");

        if(!me->is_fighting())
                return notify_fail("�����޵�����ֻ����ս����ʹ�ã�\n");
                
        if(me->query("family/family_name") != "�䵱ɽ������" )
                return notify_fail("�����Ķ�͵ѧ�����书��Ҳ���á����޵�����?\n");
                     
        if(!objectp(weapon = me->query_temp("weapon"))
           ||(string)weapon->query("skill_type")!="sword")
                return notify_fail("û����ô���ӡ����޵�������������\n");

        if( time()-(int)me->query_temp("sky_end") < 4 )
                return notify_fail("�����ö�Ͳ����ˣ�\n");

        if((int)me->query("max_force") < 300 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 300 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < (int)(me->query("max_sen")/2) )
                return notify_fail("��ľ����㣬û����ʩչ�����޵�������\n");

        if(myskill < 60)
                return notify_fail("������콣�����𻹲�����\n");
        else 
            if(myskill <60){
                times = 1;        
                number = "һ";}
            else
                if (myskill <80){
                    times = 2;
                    number = "��";}
                else
                    if(myskill <100 ){
                           times = 3;
                           number = "��";}
                else
                    if(myskill <120 ){
                           times = 4;
                           number = "��";}
                else
                    if(myskill <140 ){
                           times = 5;
                           number = "��";}
                     else{ 
                           times = 6;
                           number = "��";}

        me->delete("env/brief_message");
        target->delete("env/brief_message");
        damage = random((int)me->query_skill("sword")/3);

message_vision(HIM"\n$NǱ�˹���������"+ weapon->query("name")+ HIM"����һת���������$n������"+number+"��������֯��һ�����޵�����\n"NOR,me,target);

        for(int i=1;i<=times;i++)
        COMBAT_D->do_attack(me, target, weapon);
        COMBAT_D->report_status(target, 0);
        me->receive_damage("sen", 20);
        me->add("force", -(times*30+10));

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        if(me->is_fighting() && target->is_fighting() &&
        environment(me) == environment(target) && times>5)
        {

                target->receive_damage("sen",damage,me,"pfm");
                target->receive_wound("sen", random(damage),me,"pfm");
                target->receive_damage("kee",damage+1,me,"pfm");
                target->receive_wound("kee", random(damage),me,"pfm");
                                        
                message_vision(HIR"\n$n��ȫ��������,һʱ���˶�ܣ�ȫ�����±�$N��"+ weapon->query("name")+ HIR"֯���Ľ����ദ���ˣ�\n\n $n���Ͻ�����Ѫӿ��......\n" NOR,me,target);
                COMBAT_D->report_status(target, 0);
        }
        me->start_busy(1+random(2));
if (target->query("eff_kee")<0 || !living(target))
{msg=target->name()+"��"+me->name()+"��"HIC"�䵱ɽ������"HIM"����"+HIW"[���޵���]"HIM+"ɱ���ˣ�";
message("channel:rumor",HIM"����Ѩ���硿ĳ�ˣ�"+msg+"\n"NOR,users());
}

        me->set_temp("sky_end",time());
        return 1;
}

