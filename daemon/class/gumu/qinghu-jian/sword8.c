#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int damage, ap, dp;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
 return notify_fail("��Ҫ��˭ʩչ������ʽ����\n");
        if (!PFM_D->valid_family(me, "��ԯ��Ĺ"))
return notify_fail("���ǹ�Ĺ������ô����ħ�罣�ˣ�\n");
   if(environment(me)!=environment(target))
 return notify_fail("������û���˹���Ŀ��!\n");
            if((string)me->query_skill_mapped("force")!="jiuyin-force")
  return notify_fail("��ʩ��Ĺ��ѧ�������Ϊ��������\n");
//        if((int)me->query("force") < 65+(int)me->query("force_factor") )
//                return notify_fail("����������㣡\n");
            if(me->query("max_force") < 1000 || me->query("force")<200)
   return notify_fail("�������㣬�����޷�����ħ�罣�˵�������\n");
        if((int)me->query("kee") < 200 )
   return notify_fail("������̫�����ˣ��޷�ʩչ�����ˡ���\n");
      if((int)me->query_skill("qinghu-jian", 1) <100)
   return notify_fail("�������������ò������죬�޷�ʹ�����С�ħ�罣�ˡ���\n");
         if((int)me->query_skill("jiuyin-force", 1) <100)
 return notify_fail("��Ծ���������ǳ������ʹ����ħ�罣�ˡ���\n");
        me->add("force", -50-(int)me->query("force_factor"));
 msg = HIW
 "\n$N���ν���������ͻȻһ��ŭ�ȣ����еĽ��û���һƬ����
˲�������˽���һ���޴��
"RED"
           ]@         
           ]b      ____        ]@
           ][      @~~~~J[~    ]@
        ___ P____  ]    i[     ]@
       ~~~~]@~~~   J_____U  d  ]@
           ][   /'__ J___   ]i ]@
           ]@'J~ ~~~~]~~d[' jl ]@
           d[       d[  ]@  J[ ]@
         ]%][       d'  ][  i' ]@
      _d~  ]@      a'   d[     ]@
           ][    _r~    ad     ]a
           J[   ~     _a'      J[
          _r                  J~ 
"NOR"\n"HIW"�ָ�����$n��ǰ��\n"NOR;

        ap = me->query_skill("qinghu-jian", 1);
        ap = ( ap * ap * ap / (4 * 400) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
   dp = ( dp * dp * dp / (7 * 400) );
   dp = dp*250 + target->query("combat_exp");
    if( random((ap + dp)/1000) <  dp/1200 ) {
  msg += HIY "$n��æ������������Ǳ��Ķ㿪�������İ˽���\n\n"NOR;
           message_vision(msg, me, target);
   } else {
                damage = (int)me->query_skill("qinghu-jian",1) / 10 +
        (int)me->query("sen") / 200 + random((int)me->query("sen") / 150 ) +
        (int)me->query("kee") / 250 + random((int)me->query("kee") / 150 );
  msg += HIR "\n$n��ʱ�����������İ˽����У�\n\n" NOR;
     damage +=random(10);
PFM_D->test_msg(me, target,
"receive_damage(sen, " + me->query("eff_sen")*damage/100 +")"
+ "receive_damage(kee, " + me->query("eff_kee")*damage/100 +")"
+ "receive_wound(kee, " + me->query("eff_kee")*damage/300 +")");
                        target->receive_damage("sen", me->query("eff_sen")*damage/100,me,"pfm");
                        target->receive_damage("kee", me->query("eff_kee")*damage/100,me,"pfm");
       target->receive_wound("kee", me->query("eff_kee")*damage/300,me,"pfm");
                        me->improve_skill("qinghu-jian", 1, 1);
           message_vision(msg, me, target);
                COMBAT_D->report_status(target);
}
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
}
}
        me->start_busy(1+random(2));
        return 1;
}


