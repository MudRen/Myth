//tougu.c ��צ͸��
// by junhyun@SK
 
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

        skill = me->query_skill("jiuyin-zhua",1);

        if( !(me->is_fighting() ))
                return notify_fail("����צ͸�ǡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!PFM_D->valid_family(me, "��ԯ��Ĺ"))
return notify_fail("���ǹ�Ĺ������ô��׹�צ��\n");

        if( skill < 80)
                return notify_fail("��ġ������׹�צ���ȼ�����, ����ʹ������צ͸�ǡ���\n");

        if( me->query("force") < 200 )
                return notify_fail("��������������޷��˹���\n");
 
        msg = HIW "
$NͻȻ��ɫ�԰ף��������Գ�һ˿������һ����Х��Խ�����ɣ��Ӹ�����
��ָ���ţ�����$nֱ�˶��������Ǿ����׹�צ��ѧ����"+HIB"����צ͸�ǡ�
\n"NOR;

        message_vision(msg, me, target);

        ap = me->query("combat_exp") + skill * 800;
        dp = target->query("combat_exp") ;

        if( dp < 1 )
                dp = 1;
        if( random(ap+dp) > (dp*5/7) )
        {
                if(userp(me))
                        me->add("force",-100);

                msg = HIW "
$nͻȻ��������һ����һ�ɺ���ֱ�ܵ����ͷһ�����������ѱ�$Nץ�����Ѫ����
��\n"NOR;

                force_wound = 200 + random(skill)*3;
                if(force_wound > target->query("force"))
                        force_wound = target->query("force");


                    kee_wound = force_wound /2;
                              
                if(kee_wound > target->query("eff_kee"))
                        kee_wound = target->query("eff_kee");

         if(kee_wound<0) kee_wound=100;
                target->receive_damage("kee", kee_wound,me,"pfm");
                target->receive_wound("kee", kee_wound/3,me,"pfm");
//                target->start_busy(2+random(2));
                me->start_busy(random(2));
                target->start_busy(random(3));
             

       }
        else
        {
                msg = HIW "$n��æ�з����ڵأ�����һ�����Ǳ��Ķ㿪��$N������צ�磡\n"NOR;
                if(userp(me))
                        me->add("force",-70);
                me->start_busy(2);
        }
        message_vision(msg, me, target);

        return 1;
}


