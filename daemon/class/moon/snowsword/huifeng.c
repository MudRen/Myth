//���
//requirement: snowsword >120, being killed by target, 
//max_qixue under 50%

#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int damage, ap, dp,qixue,eff_qi,max_qi,qi_pcg;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭��\n");
        
        if((int)me->query_skill("snowsword", 1) <120)
                return notify_fail("��Ļط�ѩ�轣����򻹲�����\n");
        if (me->query_skill_mapped("force")!="moonforce")
                return notify_fail("�ط罣�������Բ���ķ�����ʹ�á�\n");
        if (me->query_skill("moonforce",1)<120) 
                return notify_fail("���Բ���ķ��������졣\n");
        if (!target->is_fighting(me))
                return notify_fail("����û���ڴ�ܣ�\n");
        if (!target->is_killing(me->query("id")))
                return notify_fail("�ö˶˵ı��䣬�α������ಫ��\n");
        eff_qi=me->query("eff_kee");
        max_qi=me->query("max_kee");
        qi_pcg=eff_qi*100/max_qi;
        if (qi_pcg>=50) 
                return notify_fail("��δ��ɽ��ˮ���ĵز�����Ҫ���ҳ��֡�\n");
        if (me->query("force")<200)
                return notify_fail("���������̣�������������㡣\n");

        me->set("kee", 0);
        me->set("eff_kee",eff_qi*random(10)/100);
        me->set("sen",0);
        me->set("eff_sen",me->query("eff_sen")*random(10)/100);
        me->set("force",0);
        me->set("mana",0);

        msg = HIW"\n$N�ۼ����У�����һҧ��ͻȻ�߸���������ȫ�������˽���һ��"
                 +"����һ���׹⣬���������$n��\n" NOR;
        ap = me->query_skill("snowsword", 1);
        ap = ap * ap * ap /10;
        ap = ap + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = dp * dp * dp /10;   
        dp = dp + target->query("combat_exp");
        dp = dp*qi_pcg/50;  //more badly you're hurt, more chance you will succeed
        if( random(ap + dp) <  dp ) {
                msg += HIW "$nһ�����Ʋ����æ�͵�һ��������ǧ��һ��֮�ʶ������һ����ȴҲ�Ǳ��������ŵû����ɢ��һʱ�䶯�����á�\n"NOR;
                message_vision(msg, me, target);
         } 
         else {
//                  target->set("kee",-1)
                target->receive_damage("kee",target->query("kee")*2,me);
                msg += HIW "$n����$N��˾�����Ϊ���������壬��Ȼ���ڵ��أ������мܡ�\n
˵ʱ�٣���ʱ�죬����׹�����$n���ϵ��ش�����\n"NOR;
                message_vision(msg, me, target);
                COMBAT_D->report_status(target); 
         }
         me->start_busy(2+random(3));
         target->start_busy(random(3));
         return 1;
}


