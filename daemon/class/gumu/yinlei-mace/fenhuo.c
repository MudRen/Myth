//���׷ٻ�
//by junhyun@SK
//Ҫ�� ʹ���� ��Ѫ ���� С��50%

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
           return notify_fail("�����˭ʹ�á����׷ٻ𡿣�\n");
        
      if((int)me->query_skill("yinlei-mace", 1) <120)
            return notify_fail("������ױ޷���򻹲�����\n");
      if (me->query_skill_mapped("force")!="jiuyin-force")
                return notify_fail("���׷ٻ�Ҫ�þ����澭�����ӡ�\n");
     if (me->query_skill("jiuyin-force",1)<120) 
         return notify_fail("��ľ����澭�������졣\n");
      if (!target->is_fighting(me))
             return notify_fail("������ս��ô��\n");
      if (!target->is_killing(me->query("id")))
             return notify_fail("����Ҫ����£�\n");
       eff_qi=me->query("eff_kee");
       max_qi=me->query("max_kee");
       qi_pcg=eff_qi*100/max_qi;
       if (qi_pcg>=50) 
           return notify_fail("ʱ��δ����������䡣\n");
       if (me->query("force")<200)
           return notify_fail("���������̣�������������㡣\n");

//        me->set("kee", 1);  //û�б�Ҫ�ˣ�eff���������ˡ�
        me->set("eff_kee",eff_qi*random(10)/100);
      if ( me->query("eff_kee") <1 ) me->set("eff_kee",1); 
//        me->set("sen",1);
        me->set("eff_sen",me->query("eff_sen")*random(10)/100);
      if ( me->query("eff_sen") <1 ) me->set("eff_sen",1); 
        me->set("force",1);
        me->set("mana",1);/* �������е���ֵ����Ϊ0�������Ī����������˵ġ�cigar */

        msg = HIR"\nֻ��һ�����ȣ�$N��������һָ�������������ף����������׵�֮��
���Լ�һ�������߶����׵�ʹ��һ�з��컯�صġ�������

                     ������
                     ���쩧
                     ������
                       ��
                     ������
                     ���ש�
                     ������
                       ��
                     ������
                     ���٩�
                     ������
                       ��
                     ������
                     ����
                     ������
"
                 +"�׵绯��һ���һ𣬰�����$n��\n" NOR;
        ap = me->query_skill("yinlei-mace", 1);
        ap = ap * ap * ap /10;
        ap = ap + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = dp * dp * dp /10;   
        dp = dp + target->query("combat_exp");
        dp = dp*qi_pcg/50;
        if( random(ap + dp) <  dp ) {
              msg += HIB "$nһ�����Ʋ����æ�͵�һ��������ǧ��һ��֮�ʶ������һ����ȴҲ�Ǳ��������ŵû����ɢ��һʱ�䶯�����á�\n"NOR;
              message_vision(msg, me, target);
         } else {
//                  target->set("kee",-1)
                  target->receive_damage("kee",target->query("kee")*2,me,"pfm");
                  msg += HIR "$n����$N�����һ�У�Ϊ���������壬��Ȼ���ڵ��أ������мܡ�\n
˵ʱ�٣���ʱ�죬����׹�����$n���ϵ��ش�����\n"NOR;
                   message_vision(msg, me, target);
                   COMBAT_D->report_status(target); 
           }
          me->start_busy(2+random(3));
          target->start_busy(random(3));
          return 1;
}

