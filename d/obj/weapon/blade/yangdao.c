// blade.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
set_name(HIG"�쵶"NOR, ({"yang dao", "yangdao",  "dao", "blade", }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("is_monitored", 1);
		set("no_sell", 1);
set("replace_file", "/d/obj/weapon/blade/jindao");
set("material", "steel");
set("long", "����һ��������ϸ�ĵ���������д������С׭[�ߵ�]��\n");
	}
init_blade(75);
	setup();
}
