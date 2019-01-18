#include <ansi.h>

inherit SSERVER;


int perform(object me, object target)
{
        object weapon, ob;
        string msg;
        int myexp,yourexp,busy;    
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ�� ���� ��?\n");
         
        if (!PFM_D->valid_family(me, "��ɽ����"))
                return notify_fail("�㲻����ɽ֮��,��������!\n"); 
        if( !me->is_fighting() )
                return notify_fail("�� ���� ��ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("�������������ܻ�����ϼ���գ�\n");

        if( environment(me)->query("no_fight") )
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

        if( (int)me->query_skill("yujianshu", 1) < 120)
                return notify_fail("����������ȼ�����������ô��ʹ���� ���� ����\n");

        if (me->query("force") < 300)
                return notify_fail("���������̣�����ʹ���� ���� ����\n");

        me->clean_up_enemy();
        ob = me->select_opponent();
        myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
        busy = (int)me->query_skill("parry",1)/60;
        message_vision(HIY"\n$N�Ų��ڳ�ϼ�ƻ�֮�У�����������ɽ���Ų���ӯ������������ʹ��"+HIR"�����䡹"+HIY"һ����\n"NOR,me,target);        
        msg = HIC"\n�գ����ʽ���С����ɽ�����з紵��ֻΪ���ѣ��ļ���������\n" NOR;
        if(random(myexp)>yourexp/8)
        {
                message_vision(msg + "\n", me, target);
                
                msg = HIC "��ͤ�»��ݣ���ǧ���������ã���¶֪���٣����㺬̬���ˣ�ĺ����������......��\n" NOR;
                message_vision(msg, me, target);
                target->start_busy(random(busy));
                message_vision(HIG"$n����Ӱ����ϡ��������ɽ��פ�㣬̾����ϧ�գ�ϧ��...��"NOR, me, ob);
                COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

                message_vision(HIG"$n����Ҷ�仨�У�ٰ�㲣��⣺�����գ�����...��"NOR, me, ob);
                COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

                message_vision(HIW"$n�䵱�꣬�Ū�����֣����ԣ�����ϼ�����䣬��������ͤ�λ꣬�����ȥ����...��"NOR, me, ob);
                COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        }
        else 
        {
                message_vision(msg +"\n", me, target);
                msg = HIM "���ճ�ϼ��������֮�У�$n�����Լ��ڳ�ϼ֮���ز����顣\n" NOR;
                message_vision(msg, me, target);
                me->start_busy(2); 
        }        
        me->add("force", -150);

        me->start_busy(1+random(2));
        return 1;  

}

