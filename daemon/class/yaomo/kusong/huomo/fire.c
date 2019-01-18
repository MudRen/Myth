#include <ansi.h>

inherit F_CLEAN_UP;

string get_name(string str)
{
        str="�������";
        return str;
}

string get_help(string str)                
{
        str="ָ���������������\n"
        +"����������𹥻���Χ���е��ˣ�";
        return str;
}

int exert(object me, object target)
{
        object *ob;
        int i, skill, damage, force;

        if( !me->is_fighting() )
                return notify_fail("�������ֻ����ս����ʹ�á�\n");

        if( (int)me->query("force") < 200 )
                return notify_fail("�������������\n");
                
        if( (int)me->query("kee") < 100)
                return notify_fail("������������ˡ�\n");

        skill = me->query_skill("force");
        force = me->query("max_force");
        me->add("force", -150);
        me->receive_damage("kee", 50);
        me->receive_wound("kee", 30);

        me->start_busy(4);
        message_vision(HIR "\n$N�˺�������ȭͷ�ڱ������������£���ʱ��Ѫֱð\n
��Ȼ��$N���г����Ȼ����������������е��ˣ�\n\n"NOR, me);
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) 
        {
                if( !living(ob[i]) || ob[i]==me ) continue;
                if( skill/2 + random(skill/2) < (int)ob[i]->query("cps") * 2 ) continue;

                damage = skill + force/10 - ((int)ob[i]->query("max_force") / 10);
                if( damage > 0 ) 
                {
                        ob[i]->receive_damage("kee", damage, me, "exert");
                        if( (int)ob[i]->query("force") < skill * 2 )
                                ob[i]->receive_wound("kee", damage/2, me, "exert");
                        tell_object(ob[i], "����㱻�յý�ͷ�ön");
                }
                COMBAT_D->report_status(ob[i]);         
                if( userp(ob[i]) ) ob[i]->fight_ob(me);
//                else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
                else if( !ob[i]->is_killing(me) ) me->kill_ob(ob[i]);

        }

        return 1;
}

