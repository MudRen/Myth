// roar.c

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
        object *ob;
        int i, skill, damage;
        if ( (string)me->query("class") != "yaomo")
                return notify_fail("�㲻����ħ֮��,�޷�ʹ������!!\n");
        if(!me->is_fighting())
                return notify_fail("���һ��Ρ�ֻ����ս���в���ʹ��!\n");

        if( (int)me->query("max_force") < 1200)
                return notify_fail("�������̫��,������������һ��Ρ�.\n");
                
        if( (int)me->query("force") < 500 )
                return notify_fail("�������������\n");

        skill = me->query_skill("force");

        me->add("force", -150);
        me->receive_damage("kee", 10);

        me->start_busy(2+random(2));
        message_vision(
  HIR "$N���������һ����,ͻȻ�³�һ����ʰ�쵵��һ���!!\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) 
        {
                if( !living(ob[i]) || ob[i]==me ) continue;
                if( interactive(ob[i]) ) continue;
                if( skill/2 + random(skill/2) < (int)ob[i]->query("cps") * 2 ) continue;
                
                damage = skill*2 - ((int)ob[i]->query("max_force") / 10);
                if( damage > 0 ) 
                {
                        ob[i]->receive_damage("sen", damage, me, "exert");
                        tell_object(ob[i], HIR"��ֻ��һ��������ת,���û���˹�ȥ.\n"NOR);
                        ob[i]->set_temp("last_damage_from",me);
                }
                
                if( userp(ob[i]) ) ob[i]->fight_ob(me);
//                else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
                else if( !ob[i]->is_killing(me) ) me->kill_ob(ob[i]);
        }

        return 1;
}


