//zhaoyaojian.c
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name( RED "���轣" NOR, ({ "luoxiang jian", "jian","sword" }) );
    set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_paimai", 1);
                set("value",200);
//              set("no_drop", "1");
                set("weapon_prop/intelligence", 15);
                set("material", "iron");
                set("long", "һ��ľ��������ɢ���ŵ��������㣬��������Ϊ֮һ��\n");
                set("wield_msg","$n����һ����⣬����$N�����У�\n");
                set("unwield_msg", "$N��$nС�ĵķ������У����������\n");
                                set("no_sell",1);
                                set("no_get","�����ɼ�����Ŷ!\n");
                }
        init_sword(1);
        setup();
}

