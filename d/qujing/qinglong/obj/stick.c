
#include <weapon.h>

inherit STICK;

void create()
{
	set_name("���", ({"da gun", "gun", "stick"}) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 2500);
		set("material", "iron");
		set("long", "����һ�����صĴ����\n");
		set("wield_msg", "$N����һ��$n��ವ�һ�衣\n");
	}
	init_stick(55);
	setup();
}
