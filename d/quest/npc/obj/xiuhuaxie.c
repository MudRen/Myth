// shoes.c

#include <armor.h>
#include <ansi.h>

inherit BOOTS;


void create()
{
	set_name(HIM "�廨Ь" NOR, ({ "shoes" }) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "�Ϲ�ʮ�����֮���廨Ь��  \n");
		set("material", "cloth");
                set("no_put",1);
                set("no_zm",1);
                set("no_give",1);
                set("no_sell",1);
		set("unit", "˫");
                set("armor_prop/armor", 20 );
                set("armor_prop/dodge", 50 );
	}
	setup();
}


