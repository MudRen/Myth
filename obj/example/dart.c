// dart.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("����", ({ "dart" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"������һ��ʮ�ֳ����İ�����\n");
		set("unit", "Щ");
		set("base_unit", "֦");
		set("base_weight", 40);
		set("base_value", 5);
	}
	set_amount(1);
	init_throwing(20);
	setup();
}
