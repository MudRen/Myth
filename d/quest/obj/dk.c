// pao.c
#include <ansi.h>
inherit EQUIP;

void create()
{
     set_name(HIY"����С�̿�"NOR, ({"dk", "pao", "cloth"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_type", "cloth");
                set("armor_prop/armor", 100);
                set("armor_prop/dodge", 50);
                set("armor_prop/spells", 100);
             }
}
