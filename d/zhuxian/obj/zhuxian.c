#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;
void create()
{
        set_name( HIR "���ɽ�" NOR, ({ "zhuxian jian", "jian", "sword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"���ɽ�\n"
);
                set("value", 0);
                set("material", "purplegold");
                set("sheenness", 50);
                set("is_monitored", 1);
                set("no_put", 1);
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        }

        init_sword(150);
        setup();

}

/*
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        pro = (int) victim->query_temp("apply/armor_vs_spells");
        dam = (int) me->query("force");

        if(dam > pro)
        {
        victim->receive_damage("sen",150);
        return HIR "���ɽ���������ĺ�⡣\n" NOR;
        }
}
*/

