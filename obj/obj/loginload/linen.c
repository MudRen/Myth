// linen.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�ֲ���", ({ "linen","cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
		set("armor_prop/armor", 1);

	}
	setup();
}
