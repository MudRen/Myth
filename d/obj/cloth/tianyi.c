// jiasha.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
inherit F_UNIQUE;

void init()
{
  cloth::init();
  unique::init();
}

void create()
{
	set_name(HIY"�������"NOR, ({"tian yi", "color cloth", "tianyi" }) );
	set("long", "������ĸ�ٳ�,֯Ů���߲���ϼ�ر�֯�͵����£������������\n");
	set_weight(0);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 40);
		set("armor_prop/dodge", 50);
		set("replace_file", "/d/obj/cloth/xianyi");
                set("armor_prop/personality", 10);
                set("value", 50000);
                set("female_only", 1);

	}
	setup();
}

