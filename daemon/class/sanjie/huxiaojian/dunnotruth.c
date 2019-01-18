#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon;
        int myskill,times, damage;
        string number;
        myskill = (int)me->query_skill("huxiaojian", 1);  
        weapon = me->query_temp("weapon");
     
        if( !target ) target = offensive_target(me);
        
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С����ɵ� �ǳ�������\n");

        if(!me->is_fighting())
                return notify_fail("�����ɵ� �ǳ�����ֻ����ս����ʹ�ã�\n");
                
    if (!PFM_D->valid_family(me, "����ɽ"))
                return notify_fail("�����Ķ�͵ѧ�����书��Ҳ���á����ɵ� �ǳ�����?\n");
                     
        if(!objectp(weapon = me->query_temp("weapon"))
           ||(string)weapon->query("skill_type")!="sword")
                return notify_fail("û����ô���ӡ����ɵ� �ǳ�������������\n");

        if( time()-(int)me->query_temp("dunno_end") < 4 )
                return notify_fail("�����ö�Ͳ����ˣ�\n");

        if((int)me->query("max_force") < 300 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 300 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < (int)(me->query("max_sen")/2) )
                return notify_fail("��ľ����㣬û����ʩչ�����ɵ� �ǳ�������\n");

        if(myskill < 60)
                return notify_fail("��Ļ�Х�������𻹲�����\n");
        else 
            if(myskill <60){
                times = 1;        
                number = "һ";}
            else
                if (myskill <80){
                    times = 2;
                    number = "��";}
                else
                    if(myskill <120 ){
                           times = 3;
                           number = "��";}
                else
                    if(myskill <160 ){
                           times = 4;
                           number = "��";}
                else
                    if(myskill <200 ){
                           times = 5;
                           number = "��";}
                     else{ 
                           times = 6;
                           number = "��";}

        me->delete("env/brief_message");
        target->delete("env/brief_message");
        damage = random((int)me->query_skill("sword")/3);

       message_vision(HIM"\n$NͻȻ����һ�䣬���е�"+ weapon->query("name")+ HIB"��Ӱ���٣������籡�������Ľ������������$n������"+number+"����\n"NOR,me,target, "");

        for(int i=1;i<=times;i++)
        COMBAT_D->do_attack(me, target, weapon);
        COMBAT_D->report_status(target, 0);
        me->receive_damage("sen", 20,target);
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

        target->receive_damege("sen", damage,me,"pfm");
        target->receive_wound("sen", random(damage),me,"pfm");
        target->receive_damege("kee", damage+1,me,"pfm");
        target->receive_wound("kee", random(damage),me,"pfm");
message_vision(HIR"\n���$n��$N�ġ����ɵ� �ǳ������������ģ���ǰһ�ڣ��������ɳ�������\n\n $n���Ͻ�����Ѫӿ��......\n" NOR,me,target,"");
                COMBAT_D->report_status(target, 0);
        }
        me->start_busy(1+random(2));
/*
if (target->query("eff_kee")<0 || !living(target))
{msg=target->name()+"��"+me->name()+"��"HIC"����ɽ"HIM"����"+HIW"[�����ɵ� �ǳ�����"HIM+"ɱ���ˣ�";
message("channel:rumor",HIM"����Ѩ���硿ĳ�ˣ�"+msg+"\n"NOR,users());
}
*/
        me->set_temp("sky_end",time());
        return 1;
}

