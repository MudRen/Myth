#include <ansi.h>
#include <combat.h>
inherit SSERVER;

void fb_ok(object);

int perform(object me, object target)
{
        int damage;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С���������\n");
                if(me->query("family/family_name") != "��ԯ��Ĺ")
                return notify_fail("�ǹ�Ĺ���Ӳ���ʹ�á���������\n");
        if(!me->is_fighting())
                return notify_fail("��������ֻ����ս����ʹ�ã�\n");
        if((int)me->query("max_force") < 300 )
                return notify_fail("�������������\n");
          if((int)me->query("force") < 300 )
                return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 100 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query_skill("zizhi-blade", 1) < 100)
                return notify_fail("���������������������ʹ����һ�л������ѣ�\n");
         if(me->query_temp("no_fb"))
                        return notify_fail("�˼����ڷ���������Ϊ�ã�\n");
        me->delete("env/brief_message");
        target->delete("env/brief_message");
message_vision(HIW"\n$N����ͷ��������ȫ��������һ������\n\n"NOR,me,target);
message_vision(MAG"\n�������һ����ɫ���滮��,����һֻ������ʵĻ���\n"NOR,me,target);
message_vision(MAG"\n����������ֱ�˹�������������������\n"NOR,me,target);
              damage=(int)me->query_skill("blade")+random((int)me->query_skill("blade"));
              if (random((int)target->query("combat_exp"))<(int)me->query("combat_exp"))
{
              message_vision(HIW"\n$n$n������ɫ�����Χ��......\n"NOR,me,target);
             target->receive_damage("sen",damage,me,"cast");
              target->receive_wound("sen",damage/2,me,"cast");
             COMBAT_D->report_status(target);
}
else {
             message_vision(HIG"\n$n��æ��Ծ���Ž����㿪����Ĺ�����\n"NOR,me,target);
             }
        me->receive_damage("sen", 50);
        me->add("force", -100);
        me->set_temp("no_fb",1);
                call_out("fb_ok",1+random(2),me);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
}
}
return 1;
}

void fb_ok(object me)
{
if (!me) return;
      me->delete_temp("no_fb");
}

