// jiasha.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

inherit F_UNIQUE;

void create()
{
	set_name(HIY"��������"NOR, ({ "jinlan jiasha", "jiasha" }) );
	set("long", "����������������֮�������ģ���˵���Ͽ�����ֻء�\n");
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 90);
		set("armor_prop/spells", 50);
		set("armor_prop/dodge", 20);
		set("replace_file", "/d/obj/cloth/hufa-jiasha");
                set("value", 50000);
	}
	setup();
}

