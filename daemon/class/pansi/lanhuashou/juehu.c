// juehu.c �����֡����������֡�perform
//2000,by lestat
#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
        int damage,l_temp;
        string msg;

        int busy_time,busy_time1,pfm_time,pfm_time1;
        busy_time=3;   //perform��æʱ�����
        busy_time1=2;  //�ɹ����ֵ�æʱ�����
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("���˵�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á����������֡���\n");  
                
        if( (int)me->query_skill("lanhua-shou", 1) < 100 )
                return notify_fail("��������ֲ�����죬����ʹ�á����������֡���\n");

        if( (int)me->query_skill("jiuyin-xinjing", 1) < 100 )
                return notify_fail("��ľ����ľ������ߣ������á����������֡��˵С�\n");

        if( (int)me->query("force") < 500 )
                return notify_fail("����������̫��������ʹ�������������֡���ʽ��\n");

        if( (int)me->query_condition("juehu_busy"))
                 return notify_fail("��Ԫ�����ˣ�����û������ʹ�������������֡���ʽ��\n");

                        
        msg = HIB "$NĬ���񹦣���ɫ�׵����ˣ�ͻȻʹ�������ֵ�һ�����С����������֡�����ͼ������$n�������¡�\n\n"NOR;

        pfm_time=(int)busy_time-(me->query("lanhua-shou",1)+me->query("jiuyin-xinjing",1))*(1+busy_time)/200*busy_time;
        pfm_time1=busy_time1+(int)(me->query("lanhua-shou",1)+me->query("jiuyin-xinjing",1))*(1+busy_time)/200*busy_time;
        if (random(me->query_skill("force")) > target->query_skill("force")/2 )
        {
                me->start_busy(pfm_time);
                target->start_busy(random(pfm_time1));
                
                damage = (int)me->query_skill("lanhua-shou", 1);
                
                damage = damage + random(damage)/2;
                
                target->receive_damage("kee", damage);

                target->receive_wound("sen", damage/2,me,"pfm");
                target->receive_damage("kee", damage/2,me,"pfm");
                target->receive_wound("sen", damage/3,me,"pfm");
                me->add("force", -damage/6);
                msg += RED"���$Nһ�����У�$nֻ�е�����һ���ʹ�����ھ�Ԫ������й����ʱ������֫���������Ȳ�ͣ������\n"NOR;
                
        } else 
        {
                me->start_busy(random(pfm_time));
                l_temp=80-(int)me->query_skill("jiuyin-xinjing", 1)/10;
                me->add("force", -l_temp);
                msg += CYN"����$p������$P�ĺݶ���ͼ�����������������㿪��$P������һ����\n"NOR;
        }
        message_vision(msg, me, target);
        if (damage>200 )
         {
          me->add("sen", -damage);
//          target->apply_condition("juehu_hurt",(int)(500*target->query("age")));
          me->apply_condition("juehu_busy",(int)(100*me->query("age")));
          me->add("max_force", - (20 + random(20)));
          if (target->query("gender")== "����")
          {
             message_vision(HIW"$NͻȻ���ĵ����ڵľ�Ԫ����ʧ�ʾ�������һ���ѹ���֪���Լ���һ��ʱ�䲻���л�������!\n"NOR,target);
           } else
           {if (target->query("gender")== "Ů��")
               message_vision(HIW"$N����һ�����У�������������ŭ����$n����һŮ��֮��Ҳ�ô�����������\n"NOR,target,me);
            else
               message_vision(HIW"$N��Ȼ����$n��˽�������о��������ᣬ�ƺ�����Ҫ������!\n"NOR,me,target);
           }
          target->kill_ob(me);
         }
        return 1;
}
