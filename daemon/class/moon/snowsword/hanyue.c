//��������ǧ��ѩ BY Cigar 2002.01

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

void qianxue_ok(object);

int perform(object me, object target)
{
        int damage,damagea;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С���������ǧ��ѩ����\n");
        if (!PFM_D->valid_family(me, "�¹�"))
                return notify_fail("[��������ǧ��ѩ]���¹�����֮�ܣ�\n");
        if(!me->is_fighting())
                return notify_fail("����������ǧ��ѩ��ֻ����ս����ʹ�ã�\n");
        if((int)me->query("max_force") < 300 )
                return notify_fail("�������������\n");
        if((int)me->query("force") < 300 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query_skill("moondance", 1) < 120)
                return notify_fail("������������費����죬ʹ����һ�л������ѣ�\n");                
        if((int)me->query_skill("snowsword", 1) < 120)
                return notify_fail("��ķ��ѩ�轣������������ʹ����һ�л������ѣ�\n");
/*                
        if (me->query_skill_mapped("force")!="moonforce")
                return notify_fail("����������ǧ��ѩ���������Բ���ķ�����ʹ�á�\n");
                
              
        if (me->query_skill_mapped("spells")!="moonshentong")
                return notify_fail("����������ǧ��ѩ����������¹��ɷ�����ʹ�á�\n");
*/
  
        if(me->query_temp("no_qianxue"))
                return notify_fail("�����ڡ���������ǧ��ѩ�����ñϣ��Ȼ�����ðɣ�\n");
        me->delete("env/brief_message");
        target->delete("env/brief_message");

        //damagea=random((int)me->query_skill("dodge")/2);
        damagea=random((int)me->query_skill("dodge"));
        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
        {
                message_vision(HIW"\n$N�������⺮��С�£�ů��δ�ߣ�����ʫ�⣬����"+HIR"����������ǧ��ѩ��"+HIW"��\n"NOR,me,target);
                target->receive_damage("kee",damagea,me,"pfm");
                target->receive_wound("kee",damagea/2,me,"pfm");
                target->receive_damage("sen",damagea/3,me,"pfm");
                target->start_busy(2);
                COMBAT_D->report_status(target);
        }
        else 
        {
                message_vision(HIG"\n$N�������������������࣬$n�������$Nȴ����ζ...\n"NOR,me,target);
        }
        message_vision(HIG"\n$N���þ�˿����ѩ���������⺮÷����ӳ���У�������������\n"NOR,me,target);
        message_vision(HIG"\n��Ϊ����ѩΪ�񣬱��˲���ѩ�֣�������˿���£����ġ�\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(HIG"\n����ͤ���£�������Ӱ�����񣬳ص�Ӱ�����£�������ˮ�����⡣\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(HIG"\n��ǰ�������ˣ����廨Ѭ���Ʋ�������������\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        //damage=random((int)me->query_skill("sword")/2);
        damage=(int)me->query_skill("sword")+random((int)me->query_skill("parry"));
        if(random((int)target->query("combat_exp"))<(int)me->query("combat_exp"))
        {
                message_vision(HIC"\nС�¡����㡢����Χ����$N����Χ������˾���������$n���ߵ�....\n"NOR,me,target);
                target->receive_damage("kee",damage/2,me,"pfm");
                target->receive_wound("kee",damage/2,me,"pfm");
                COMBAT_D->report_status(target);
        }
        else 
        {
                message_vision(HIY"\n$n����һЦ����Ц��������⡣$n�ӻ����ͳ�һ�����ƣ�����С�á�\n"NOR,me,target);
        }
        me->receive_damage("sen", 30);
        me->add("force", -100);
        me->set_temp("no_qianxue",1);
        call_out("qianxue_ok",2+random(2),me);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        return 1;
}

void qianxue_ok(object me)
{
        if (!me) return;
        me->delete_temp("no_qianxue");
}

