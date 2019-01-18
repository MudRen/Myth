#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob, where;
        int i, skill, damage, force;

        where=environment(me);
        if( where->query("no_fight") )
                return notify_fail("��ȫ���ڲ����Һ��ҽУ�\n");

        if( !me->is_fighting() )
                return notify_fail("�̺�����ֻ����ս����ʹ�á�\n");

        if( (int)me->query("force") < 200 )
                return notify_fail("�������������\n");
        if( (int)me->query("kee") < 100)
                return notify_fail("������������ˡ�\n");

        skill = me->query_skill("force");
        force = me->query("max_force");
        me->add("force", -150);
        me->receive_damage("kee", 50);

        me->start_busy(5);
        message_vision(HIR "\n$N�˺��������������һ��������Ȼ��������ɽ����Х���������\n\n"
NOR, me);
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                if(!me->visible(ob[i])) continue;
                if( skill/2 + random(skill/2) < (int)ob[i]->query("cps") * 2 ) continue;

                damage = skill + force/10 - ((int)ob[i]->query("max_force") / 10);
                if( damage > 0 ) {
                        ob[i]->receive_damage("sen", damage, me, "exert");
                        if( (int)ob[i]->query("force") < skill * 2 )
                                ob[i]->receive_wound("sen", damage/2, me, "exert");
                        tell_object(ob[i], "�������ǰһ�������ð������ʹ������Ҫ�ѿ�һ����\n");
                }
                COMBAT_D->report_sen_status(ob[i]);             
                if( userp(ob[i]) ) ob[i]->fight_ob(me);
                else if( !ob[i]->is_killing(me) ) me->kill_ob(ob[i]);

        }

        return 1;
}

