
#include <weapon.h>

inherit AXE;

void create()
{
	set_name("�ḫ", ({"yue fu", "fu", "axe"}) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 2500);
		set("material", "iron");
		set("long", "����һ�ѳ��ص��ḫ��\n");
		set("wield_msg", "$N����һ��$n��ವ�һ�衣\n");
	}
	init_axe(55);
	setup();
}
