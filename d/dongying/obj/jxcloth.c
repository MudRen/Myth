// cloth.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIC"��ʿ��"NOR, ({ "cloth" }) );
        set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
		set("value", 0);
                set("armor_prop/armor", 1);

	}
	setup();
}
