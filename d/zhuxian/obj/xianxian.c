#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;
void create()
{
        set_name( HIG "���ɽ�" NOR, ({ "xianxian jian", "jian", "sword" }) );
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
                set("is_monitored", 1);
                set("no_put", 1);
                set("sheenness", 50);
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        }

        init_sword(150);
        setup();

}

/*
{
        int pro;
        int dam;
        int damm;
        pro = (int) victim->query_temp("apply/armor_vs_spells");
        dam = (int) me->query("force");

        damm = (int) me->query("force_factor");
        if(dam > pro)
        {
        victim->receive_damage("kee",damm);
        return HIR "���ɽ�һ����\n" NOR;
        }
}
*/

