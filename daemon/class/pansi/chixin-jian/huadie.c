//����
//requirement: lunhui-zhang >120, being killed by target, 
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
           return notify_fail("��Ҫ��˭������\n");
        
      if((int)me->query_skill("chixin-jian", 1) <120)
            return notify_fail("��ĳ����鳤����򻹲�����\n");
	  if((int)me->query_skill("pansi-dafa", 1) <120)
            return notify_fail("�����˿����Ϊ̫�ͣ�\n");
      if (me->query_skill_mapped("spells")!="pansi-dafa")
                return notify_fail("�㲻����˿����ô����?\n");
     if (me->query_skill("jiuyin-xinjing",1)<120) 
         return notify_fail("��ľ����ľ��������졣\n");
     if (!target->is_fighting(me))
             return notify_fail("����û���ڴ�ܣ�\n");
      if (!target->is_killing(me->query("id")))
             return notify_fail("�ö˶˵ı��䣬�α������ಫ��\n");
       eff_qi=me->query("eff_kee");
       max_qi=me->query("max_kee");
       qi_pcg=eff_qi*100/max_qi;
       if (qi_pcg>=50) 
           return notify_fail("�������������������\n");
       if (me->query("force")<200)
           return notify_fail("���������̣�������������㡣\n");

        me->set("kee", 0);
        me->set("eff_kee",eff_qi*random(10)/100);
        me->set("sen",0);
        me->set("eff_sen",me->query("eff_sen")*random(10)/100);
        me->set("force",0);
        me->set("mana",0);

  message_vision(HIY"\n$N˫�ֺ�ʮ��������ʣ�\n" NOR,me,target);
message_vision(HIC"\n��һ�ж����ᣬ�޳��ѵþá�\n"NOR,me,target);
message_vision(HIC"\n  ������η�壬��Σ�ڳ�¶��\n"NOR,me,target);
message_vision(HIC"\n  �ɰ������ǣ��ɰ���������\n"NOR,me,target);
message_vision(HIC"\n  �����ڰ��ߣ��������޲�����\n"NOR,me,target);
message_vision(HIB"\n $N̾��:��Ү?��Ү?��������......
��Ȼ��ʽһ������һƬ����,�Ʋʵ����ɰ�����$n\n\n"NOR,me,target);
                 
        ap = me->query_skill("chixin-jian", 1);
        ap = ap * ap * ap /10;
        ap = ap + (int)me->query("daoxing");
        dp = target->query_skill("spells");
        dp = dp * dp * dp /20;   
        dp = dp + target->query("daoxing");
        dp = dp*qi_pcg/50;  
        if( random(ap + dp) <  dp ) {
                            message_vision(HIW"$nһ�����Ʋ��һ����Ծ,����Ȧ�⡣\n"NOR, me, target);
         } else {
//                  target->set("kee",-1)
                  target->receive_damage("kee",target->query("kee")*2,me,"pfm");

                   message_vision(HIM "$n��������,�����е�����ֻ�ʵ����������\n"NOR, me, target);
                   COMBAT_D->report_status(target); 
           }
          me->start_busy(1+random(2));
          target->start_busy(2+random(3));
          return 1;
}

