// ironarmor.c
#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
        set_name(YEL"�ƽ�ս��"NOR, ({"gold armor", "jia", "armor"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	        set("long", "�Ϲ�ʮ�����֮���ƽ�ס�\n");
                set("value", 0);
                set("no_put",1);
                set("no_zm",1);
                set("no_give",1);
                set("material", "gold");
                set("armor_prop/armor", 80);
                set("armor_prop/dodge", 20);
             }
        setup();
}

