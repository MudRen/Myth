// demon_staff.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name( RED "* �� Ѫ �� ħ �� *" NOR, ({ "demon staff", "staff" }) );
	set_weight(400000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�Ѱ���ɫ�����ɶ೤�ľ��ơ�\n");
		set("material", "crimson gold");
	}
	init_staff(100);

	setup();
}
