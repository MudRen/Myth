// pao.c
#include <ansi.h>
inherit EQUIP;

void create()
{
        set_name(HIR"�����"NOR, ({"red cloth", "cloth", "pao"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 50);
		    set("long", "һ����ɫ���ס�\n");
                set("material", "cloth");
                set("armor_type", "cloth");
                set("armor_prop/armor", 2);
             }
}
