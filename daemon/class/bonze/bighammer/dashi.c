#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int extra, mydh, hisdh,damage;
        object weapon;
        if(me->is_busy())
                return notify_fail("������û�գ���\n");
        extra = me->query_skill("bighammer",1) ;
        if ( extra < 100) return notify_fail("���[���ƴ�]���������죡\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۴��ƽ�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (!((string)me->query("bonze/class") =="bonze" )) 
                return notify_fail("[���ƽ���]ֻ�г����˲���ʹ�á�\n");
        if((int)me->query("force") < 500 ) return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 200 ) return notify_fail("���޷����о�����\n");
        
        me->add("force", -200);
        me->receive_damage("sen", 100);
        me->receive_damage("kee", 100+random(200));
        weapon = target->query_temp("weapon");
        mydh = (int)me->query("daoxing")*(int)me->query("max_mana");
        hisdh= random((int)target->query("daoxing")*((int)target->query("max_mana")+1));
        if(hisdh < mydh*4/5 )   
        {
                message_vision(HIR "\n$N�����������з�ţ�$nֻ����һ�־޴��ѹ�����������\n" NOR,me,target);
                if (hisdh<mydh/4)
                {
                        message_vision(HIR "\n$n������ѹ��������Ҫ����һ�㣬��ʹ�ޱȣ��������һ����Ѫ��\n " NOR,me,target);
                        damage=random((int)me->query("max_mana"));
                        target->receive_damage("kee",damage,me,"pfm");
                        target->receive_wound("kee",damage/5,me,"pfm");
                        COMBAT_D->report_status(target);
                }
                else if (hisdh<mydh/2)
                {
                        message_vision(HIR "\n$n���������򿹣����������һ����Ѫ��\n " NOR,me,target);
                        damage=random((int)me->query("max_mana")/2);
                        target->receive_damage("kee",damage,me,"pfm");
                        target->receive_wound("kee",damage/5,me,"pfm");
                        COMBAT_D->report_status(target);
                }
                if (weapon)
                {
                        message_vision(HIR "\n$n�ۼ�������ȥ���������б���" NOR, me,target);
                        weapon->unequip();
                        if( weapon->unequip()) weapon->move(environment(target));
                }
                message_vision(
HIR "\n$n��$N�ķ𷨸л������ڵ��Ѿ��������Լ�����ս��֮�У�\n\n" NOR, me,target);
                damage=3+extra/20;
                if (damage>15) damage=15;
                target->start_busy(damage);
        }
        else {
                message_vision(
HIB "\n$n�����������ƻ�����ɾ��磡\n" NOR, me, target);
        }


        me->start_busy(2);

        me->improve_skill("bighammer", 1, 1);
        return 1;
}

