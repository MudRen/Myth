
// leihuo.c �׻��ɱ
// by stey
 
#include <ansi.h>
 
inherit SSERVER;
 
int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp;
        int force_wound, kee_wound ;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("zileidao",1);

        if( !(me->is_fighting() ))
                return notify_fail("���׻��ɱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

   if(me->query("class") != "sanjie" )
                return notify_fail("������ױ���������ֻ������ɽ���˲ſ����ã�\n");
 
  if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
   return notify_fail(RED"��ʲô��Ц��ûװ������ôʹ���׻��ɱ����\n"NOR);

        if( skill < 60)
                return notify_fail("��ġ����׵������ȼ�����, ����ʹ�����׻��ɱ����\n");

        if( me->query("force") < 150 )
                return notify_fail("��������������޷��˹���\n");
 
        msg = HIC "$N�������ƣ�ʹ��һ�С��׻��ɱ������$n���ؿڻ�ȥ��\n"NOR;

        message_vision(msg, me, target);

        ap = me->query("combat_exp") + skill * 800;
        dp = target->query("combat_exp") ;

        if( dp < 1 )
                dp = 1;
        if( random(ap+dp) > (dp*3/7) )
        {
                if(userp(me))
                        me->add("force",-100);

                msg = HIG "$nֻ������ǰһ�ڣ����ۡ���һ�����һ����Ѫ��\n"NOR;

                force_wound = 200 + random(skill)*3;
                if(force_wound > target->query("force"))
                        force_wound = target->query("force");


                    kee_wound = force_wound /2;
                              
                if(kee_wound > target->query("eff_kee"))
                        kee_wound = target->query("eff_kee");
        if (kee_wound < 0) kee_wound=100;

                target->receive_damage("kee", kee_wound,me,"pfm");
                target->receive_wound("kee", kee_wound/3,me,"pfm");
//                target->start_busy(2+random(2));
                me->start_busy(random(3));
                target->start_busy(4);
             

       }
        else
        {
                msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
                if(userp(me))
                        me->add("force",-100);
                me->start_busy(2);
        }
        message_vision(msg, me, target);

        return 1;
}
