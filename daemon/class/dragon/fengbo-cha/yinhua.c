//BY Cigar 2002.01 yinhua.c [����һЦ]
#include <ansi.h>

#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "fork")
                return notify_fail(MAG"��ʲô��Ц��ûװ������ʹ����������Ц����\n"NOR);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("����������һЦ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( (int)me->query_skill("dragonforce", 1) < 100 )
                return notify_fail("��������ڹ�������죬����ʹ�á�\n");
        if ((int)me->query_skill("fengbo-cha",1) < 100 )
                return notify_fail(WHT"��ķ粨�治����죬��ʹ��������������һЦ����\n"NOR);
        if ((int)me->query("max_force")<1000)
                return notify_fail(RED"���������Ϊ���㣬�޷����㡸��������һЦ����������\n"NOR);
        if( time()-(int)me->query_temp("yinhua_end") < 3 )  
                return notify_fail(WHT"������һЦ�����������̫��,�޷�����ʹ�ã�\n"NOR); 
        if(time()-me->query_temp("lxtx_end")<3)
                return notify_fail(WHT"������һЦ��"NOR"��"HIY"����"NOR"�޷�����ʹ�ã�\n"NOR);                 
        if ((int)me->query("force")<500)        
                return notify_fail(HIC"����������������û�ܽ�����������һЦ��ʹ�꣡\n"NOR);
        
        msg = HIY "$N����ˮ���������⣬����Ĵ���ǧ���ٲݣ�������ϧ"+BLINK""HIR"������һЦ��\n"NOR;
        msg += HIG"�񼡴��䣬���⵭��ױ��һֻ�������ˣ����������С�⡣\n"NOR;
        msg += HIG"���贺�磬�����̸лᣬһ�α������ͣ�����͵������ȥ��\n"NOR;
        msg += HIG"��⻨Ӱ����֦��������Ǳ��²��ƣ��˼���м����硣\n"NOR;
        msg += HIC"��ҹ���裬Ũ˯���оƣ���֬˭���ȵ������������ת�����ʾ����ˣ�֪��֪��\n"NOR;
        if (random(me->query_skill("force"))>target->query_skill("force")/2|| 
           random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                //me->start_busy(2);
                target->start_busy(1+random(3));
                damage = (int)me->query_skill("fork", 1);
                damage = damage + random(damage);
                target->receive_damage("kee", damage, me, "pfm");
                target->receive_wound("kee", damage, me, "pfm");
                target->receive_damage("sen", damage, me, "pfm");
                target->receive_wound("sen", damage/3, me, "pfm");
                msg += HIM"$n�Ŀ���������������������֮׹�䣬����֮������$n�Ĵ���һ�Σ��پ��������顣\n"NOR;
                msg += HIM"$N��"+HIR"������һЦ��"+HIM"���Ѿ�ɢ��$n����������......\n"NOR;
                target->apply_condition("flower",5+random(5) + target->query_condition("flower"));
                me->add("force", -200);
        } 
        else
        {
                //me->start_busy(2);
                msg += HIW"����$n��ϲ���񣬲�����Ծ��վ��$Nһ�ԣ��ֳ���������С�ã����ʹ���˾���\n"NOR;
                msg += HIW"$N����ֱ�������ޱȣ������Ͳ���˾����˾��Ƿ���֮����Ҳ���������ˡ�\n"NOR;
                me->add("force", -150);
        }
        message_vision(msg, me, target);
        if(!target->is_fighting(me)) target->fight_ob(me);
        me->set_temp("yinhua_end",time());
        return 1;
}


