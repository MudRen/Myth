// Jiushen by greenwc
//jiushen by koker2001.03.08
#include <ansi.h>
inherit SSERVER;
inherit F_CLEAN_UP;
int cast(object me, object target)
{
        object *ob;
       int i, skill, damage, spells;
            int success_adj, damage_adj;

              if( !me->is_fighting() )
                return notify_fail("ֻ����ս�����ٻ�����\n");

        if((int)me->query_skill("taoism", 1) < 100 )
                return notify_fail("����ɷ���������򲻹�����ô���ٻ�����\n");

        if((int)me->query("mana") < 200+(int)me->query("mana_factor") )
                return notify_fail("��ķ������������ƾ����Ӧ������\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("���������ǲ��壬��MM������ʶ������˵�Ǿ����ˣ�\n");
        me->add("mana", -200-(int)me->query("mana_factor"));
        me->receive_damage("sen", 100);
           
           if( random(me->query("max_mana")) < 100 ) {
                message_vision(HIR "\n$N��Ȼһ�ſڣ��������һ�ھ���\n
ֻ�������л���һ�����Σ�̽��̽ͷ�����������ɢ��ȥ��n\n"NOR, me);

                return 1;
        }

message_vision(HIR "\n$N��Ȼһ�ſڣ��������һ�ھ���\n
ֻ�������л���һ�����Σ�ƾ�մ����һ�����ף������ڳ���ÿһ���ˣ�\n\n"NOR, me);
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                if( skill/2 + random(skill/2) < (int)ob[i]->query("cps") * 2 ) continue;

                if( damage > 0 ) {
                        ob[i]->receive_damage("kee", damage);
                        if( (int)ob[i]->query("mana") < skill * 2 )
                                ob[i]->receive_wound("kee", damage/2);
                        tell_object(ob[i], "����㱻�������ţ�\n");
                }
                COMBAT_D->report_status(ob[i]);         
                if( userp(ob[i]) ) ob[i]->fight_ob(me);
                else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);

        }

        me->receive_wound("sen", 10);

        me->start_busy(2+random(2));
        return 1;
}

