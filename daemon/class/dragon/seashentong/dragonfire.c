#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
        string msg;
        object *inv, ob;
        int damage, equip, ap, dp;
        if( !target ) target = offensive_target(me);
        if( !target
        ||   !target->is_character()
        ||   target->is_corpse()
        ||    target==me)
                return notify_fail("��Ҫ��˭������ŭ��\n");
        inv = all_inventory(target);
        if( sizeof(inv) == 0)
                return notify_fail("�Է����Ϻ���ûʲô����������������!!\n");

        if((int)me->query_skill("seashentong", 1) < 80 )
                return notify_fail("��ı̺���ͨ��򲻹���������ó����\n");
        if((int)me->query("mana") < 40+(int)me->query("mana_factor") )
                return notify_fail("��ķ��������������������û��ʲô�ã�\n");

        if((int)me->query("force") < 200 )
                return notify_fail("��������������޷�����������\n");

        if((int)me->query("sen") < 40 )
                return notify_fail("���������ǲ��壬����Լ������ˣ�\n");

        me->add("mana", -50-(int)me->query("mana_factor"));
        me->add("force", -100);
        me->receive_damage("sen", 50);

        if( random(me->query("mana")) < 150 )
        {
                write("��һ�κ����顣\n");
                return 1;
        }

        msg = RED
"$Nŭ����ӿ��ҡ��һ�䣬���һ��������������ʮ�ɣ�ɷ������!\n\n"
"��ʱ$NͻȻ����һ�ţ�ͻ��һ�������$n��ȥ!\n\n"NOR;

        ap = me->query_skill("spells");
        ap = ( ap * ap * ap / (9 * 400) ) * (int)me->query("sen");
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap) > dp )
        {
                inv = all_inventory(target);
                if( sizeof(inv) == 0)
                        return notify_fail("�Է����Ϻ���ûʲô����������������!!\n");
                message_vision(msg, me, target);
                ob = inv[random(sizeof(inv))];
                message_vision(HIR"\n\nֻ������һ��$N���ϵ�$n"+HIR"�Ѿ����ս��ˡ�\n\n"NOR,target,ob);
                destruct(ob);
                me->improve_skill("seashentong", 1, 1);
        }
        else 
        {
                msg += "���Ǳ�$n�㿪�ˡ�\n";
                message_vision(msg, me, target);}
                if( damage > 0 ) COMBAT_D->report_status(target);
                if( !target->is_fighting(me) )
                {
                        if( living(target) )
                        {
                                if( userp(target) ) target->fight_ob(me);
//                                else target->kill_ob(me);
                                else me->kill_ob(target);
                        }
                        me->kill_ob(target);
                }

        me->start_busy(1+random(2));
        return 3+random(5);
}

