#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
	set_name( "������", ({ "piaget", "watch" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "��ʿ���� �� ���������ʽ���������ڣ���ȴ�߹���塣\n");
		set("value", 600);
		set("material", "wrists");
		set("armor_prop/armor", 5);
	}
	setup();
}


