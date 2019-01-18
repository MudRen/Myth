//BY Cigar 2002.01 huabian.c <����>

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

void huabian_ok(object);

int perform(object me, object target)
{
        int damage;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("���»���С�������Թ��\n");
        if (!PFM_D->valid_family(me, "�¹�"))
                return notify_fail("[����]���¹�����֮�ܣ�\n");
        if(!me->is_fighting())
                return notify_fail("�����䡹ֻ����ս����ʹ�ã�\n");
        if((int)me->query("max_force") < 650 )
                return notify_fail("�������������\n");
        if((int)me->query("force") < 650 )
                return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 250 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query_skill("jueqingbian", 1) < 200)
                return notify_fail("��ľ���޷�����������ʹ����һ�л������ѣ�\n");
        if(me->query_temp("no_huabian"))
                return notify_fail("���»���С����䣡\n");
        me->delete("env/brief_message");
        target->delete("env/brief_message");
message_vision(HIW"\n$N���ű�غ������ŵĻ��䣬�鵽һ����Ȼ������˳��������"+HIR""BLINK"�ֻ֡���֡�"NOR""+HIW"���Ĳ���......\n"NOR,me,target);
message_vision(HIG"\n            ���˼仨������ȥ���ģ���ҩ���꣬��Ȼ��̬���㡱��\n"NOR,me,target);
message_vision(HIG"\n            ��������£���ռ�������������㣬�û�ǧ����֦����\n"NOR,me,target);
message_vision(HIG"\n            ���˲��淼�����ﵱ���������ᢣ��������ƻ��á���\n"NOR,me,target);
message_vision(HIG"\n            ���������꣬���潻�࣬�����������վƷ�ͤ�λꡱ��\n"NOR,me,target);
message_vision(HIC"\n������Ⱦ¶�����䵱�꣬���޴���ޣ�ҹ�˯���㣬���鷼�����£��ʣ�"+HIR"��������Ϊ���"+HIC"��\n"NOR,me,target);
        
        damage=(int)me->query_skill("parry")+random((int)me->query_skill("whip"));
        if (random((int)target->query("combat_exp"))<(int)me->query("combat_exp"))
        {
                message_vision(HIW"\n$n��ǰ��ػ������涷�ޣ�������˳������������Ե��������飬�ٸ��������ᡣ\n"NOR,me,target);
                target->receive_damage("kee",damage,me,"pfm");
                target->receive_wound("kee",damage/2,me,"pfm");
                target->receive_damage("sen",damage,me,"pfm");
                target->receive_wound("sen",damage/2,me,"pfm");
                target->start_busy(2+random(2));
                COMBAT_D->report_status(target);
        }
        else 
        {
                message_vision(HIY"\n$n��ƽ���ͣ���ϥ�����������ͳ��������ƣ����Ŵ���˾���������������\n"NOR,me,target);
        }
        me->receive_damage("sen", 50);
        me->add("force", -100);
        me->set_temp("no_huabian",1);
        call_out("huabian_ok",4,me);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        return 1;
}

void huabian_ok(object me)
{
        if (!me) return;
        me->delete_temp("no_huabian");
}

