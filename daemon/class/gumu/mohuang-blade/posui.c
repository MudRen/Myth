//posui.c �������
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
 return notify_fail("��Ҫ��˭ʩչ��������ա���\n");
        if (!PFM_D->valid_family(me, "��ԯ��Ĺ"))
return notify_fail("���ǹ�Ĺ������ô����ʥ�齣����\n");
        if ( me->query("gender") =="Ů��" )  
                return notify_fail("Ů�˷��Ӳ������е�������\n"); 
   if(environment(me)!=environment(target))
 return notify_fail("������û���˹���Ŀ��!\n");
            if((string)me->query_skill_mapped("force")!="jiuyin-force")
  return notify_fail("��ʩ��ԯ��ѧ�������Ϊ��������\n");
        if((int)me->query("force") < 65+(int)me->query("force_factor") )
                return notify_fail("����������㣡\n");
            if(me->query("max_force") < 1000 || me->query("force")<500)
   return notify_fail("�������㣬�����޷�������ԯ��ѧ��������\n");
        if((int)me->query("kee") < 200 )
   return notify_fail("������̫�����ˣ��޷�ʩչ��������ա���\n");
      if((int)me->query_skill("mohuang-blade", 1) <200)
   return notify_fail("���ħ�ʵ������ò������죬�޷�ʹ�����С�������ա���\n");
         if((int)me->query_skill("jiuyin-force", 1) <200)
 return notify_fail("��Ծ���������ǳ������ʹ����������ա���\n");

        if( time()-(int)me->query_temp("posui_end") < 4 )  
                return notify_fail("����������������\n"); 

        me->add("force", -50-(int)me->query("force_factor"));
 msg = HIW
 "$N����һ�����б������¶��Ϸ�������������Ļ��������򽫹�ȥ�� 

                ������ ������ ������ ������ 
                ������ ��ת�� ��Ǭ�� ������             
                ������ ������ ������ ������ 


                      �ơ��顤�顤��\n"NOR;

        ap = me->query_skill("mohuang-blade", 1);
        ap = ( ap * ap * ap / (4 * 400) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
   dp = ( dp * dp * dp / (7 * 400) );
   dp = dp*250 + target->query("combat_exp");
    if( random((ap + dp)/1000) <  dp/1000 ) {
  msg += HIY "$n��æ������������ӹ�������ǵص�һ����\n\n"NOR;
           message_vision(msg, me, target);
   } else {
        if(!target->is_busy()) target->start_busy(2);
                damage = (int)me->query_skill("mohuang-blade",1) / 10 +
        (int)me->query("sen") / 300 + random((int)me->query("sen") / 200 ) +
        (int)me->query("kee") / 300 + random((int)me->query("kee") / 200 );
  msg += HIR "\n$n��ʱ����Χ��һƬ�޼ʵ���Ļ�У�\n\n" NOR;
     damage +=random(10);
                        target->receive_damage("sen", me->query("eff_sen")*damage/200,me,"pfm");
                        target->receive_damage("kee", me->query("eff_kee")*damage/200,me,"pfm");
       target->receive_wound("kee", me->query("eff_kee")*damage/300,me,"pfm");
                        me->improve_skill("mohuang-blade", 1, 1);
           message_vision(msg, me, target);
                COMBAT_D->report_status(target);
}

        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
}
}
//        me->start_busy(1+random(3));
        me->set_temp("posui_end",time());
        return 1;
}

