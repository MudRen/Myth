//��������.c 
//by junhyun@SK
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

void lianhuan_ok(object);

int perform(object me, object target)
{
        int damage,damagea;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С�������������\n");
//                if(me->query("family/family_name") != "��ԯ��Ĺ")
//                return notify_fail("[��������]�ǹ�Ĺ����֮�ܣ�\n");
                if(!me->is_fighting())
                return notify_fail("������������ֻ����ս����ʹ�ã�\n");
                if((int)me->query("max_force") < 300 )
                return notify_fail("�������������\n");
                if((int)me->query("force") < 300 )
                return notify_fail("����������㣡\n");

                if((int)me->query("sen") < 100 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
                if((int)me->query_skill("kongming-steps", 1) < 120)
                return notify_fail("��Ŀ�ڤ����������죬ʹ����һ�л������ѣ�\n");                
                if((int)me->query_skill("zizhi-blade", 1) < 120)
                return notify_fail("���������������������ʹ����һ�л������ѣ�\n");
                if((int)me->query_skill("jiuyin-force", 1) < 50) 
                return notify_fail("�����������澭����������ʹ����һ�л������ѣ�\n");

                if(me->query_temp("no_lianhuan"))
                return notify_fail("�㲻������������\n");
                me->delete("env/brief_message");
                target->delete("env/brief_message");

            damagea=random((int)me->query_skill("dodge"));
if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
{
              message_vision(HIW"\n$N����ͻתʹ�������������ľ�ѧ--������������\n"NOR,me,target); 

              message_vision(HIG"\n��һ��----�����磬$N���е�������һ�󼲷�㹥��$n��\n"NOR,me,target);
              // modify by mudring ....nk bug....hmm..
              target->receive_damage("kee", damagea, me);
              target->receive_wound("kee", damagea/2, me);
              target->receive_damage("sen", damagea/3, me);
              target->start_busy(2);
              COMBAT_D->report_status(target);
}
else {
              message_vision(HIG""NOR,me,target);
             }
                message_vision(HIM"\n�ڶ��С��������磬$N���е����������嵶��һ��ʢ�ŵ�÷����\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                message_vision(HIW"\n�����С���ѩ���磡$N���е�����ͻ��һ�����⣬��ƬƬѩ������\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                message_vision(HIC"\n�����С��������磡$N���е����д������£�֮������������һ�����£���\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
               damage=(int)me->query_skill("blade")+random((int)me->query_skill("parry"));
if(random((int)target->query("combat_exp"))<(int)me->query("combat_exp"))
{

               message_vision(HIG"\n�绨ѩ�¡���������\n"NOR,me,target);

              // modify by mudring fix nkbug.
              target->receive_damage("kee", damage/2, me);
              target->receive_wound("kee", damage/2, me);
              COMBAT_D->report_status(target);
}
else {
              message_vision(HIR"\n$n������ͷ������ʲô�����գ���ǲ�ң����򣡡�\n"NOR,me,target);
             }
              me->receive_damage("sen", 30);
              me->add("force", -100);
              me->set_temp("no_lianhuan",1);
              call_out("lianhuan_ok",2,me);
              if( !target->is_fighting(me) ) {
              if( living(target) ) {
              if( userp(target) ) target->fight_ob(me);
              else target->kill_ob(me);
}
}
return 1;
}

void lianhuan_ok(object me)
{
if (!me) return;
      me->delete_temp("no_lianhuan");
}

