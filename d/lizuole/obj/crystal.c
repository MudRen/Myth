// shoe.c

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
	set_name(HIW "ˮ��Ь" NOR, ({ "crystal shoes", "shoes"}) );
       	set("long", "���������͸�ѩ����ˮ��Ь��\n");
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "ˮ��");
		set("unit", "˫");
		set("value", 50000);
		set("armor_prop/armor", 3 );
		set("armor_prop/personality", 3);
		set("female_only", 1);
		set("no_sell", "���������������\n");
	}
	setup();
}
