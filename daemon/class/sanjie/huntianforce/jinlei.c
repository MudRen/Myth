#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob, where;
        int i, skill, damage, forcee;
        int kee_wound;

        where=environment(me);
        if( me == target )
                return notify_fail("����ѽ����ɱ���ã���\n");
        if( where->query("no_fight") )
                return notify_fail("��ȫ���ڲ�����������������\n");
        if( userp(target) ) 
                return notify_fail("������������Ӵ��\n");
        if( !me->is_fighting() )
                return notify_fail("С����ֻ����ս����ʹ�á�\n");
        
        if( (int)me->query("force") < 1000 )
                return notify_fail("�������������\n");
        if( (int)me->query("kee") < 200)
                return notify_fail("������������ˡ�\n");
        if( (int)me->query("pfmjinlei") < 0 )
                return notify_fail("��Ľ��������ˡ�\n");
        if( (int)me->query_skill("force", 1) < 150 )
                return notify_fail("����ڹ���Ϊ��������ʹ����һ�л������ѣ�\n");
                
                
        skill = me->query("force");
        forcee = target->query("force")/5-50;
        me->add("force", -400);
        me->receive_damage("kee", 150);

        me->start_busy(2);
        message_vision(HIR "\n$N������ǰһָ��������������������������\n
        ��ʱָ������һ�����ɫ��С��\n
        $N���һ����ȥ��С������$n��ȥ��\n\n"NOR, me,target);
        if(random(20)>2)
        {
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));


        kee_wound = me->query("eff_kee")/(6+random(8));
        me->receive_damage("kee", 50);
        target->set("kee", -1); 
        target->add("eff_kee", -(kee_wound));
        target->add("force",-(forcee));
        me->add("force", -100);
        me->add("pfmjinlei",-1);
        message_vision(HIY"$n��ʱ��ը�š��������أ�ȫ��������ۣ��赹�ڵأ�\n"NOR,me, target);
        target->start_busy(1);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
         }
         }
         else   message_vision(HIY"����$p�����$P�Ľ�����̾��һ�������գ�\n" NOR, me, target);
                       
        return 1;
}


