#include <ansi.h>

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIC"����С��"NOR, ({ "kid-cloth","cloth" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
		set("value", 40);
		set("armor_prop/armor", 2);
              set("armor/max_armor", 2);//By waiwai@2001/07/29 added.
		set("female_only", 1);
	}
	setup();
}
