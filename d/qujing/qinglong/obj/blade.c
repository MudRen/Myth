
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("��", ({"da dao", "dao", "blade"}) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 2500);
		set("material", "iron");
		set("long", "����һ�ѳ��صĴ󵶡�\n");
		set("wield_msg", "$N����һ��$n��ವ�һ�衣\n");
	}
	init_blade(55);
	setup();
}
