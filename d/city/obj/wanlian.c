//Last Create  By PKYOU@DHXY 2002/05/04
#include <armor.h>

inherit NECK;

void create()
{
	set_name("������Ȧ", ({ "xiang quan", "quan" }));
	set("weight", 800);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 5000);
		set("material", "gold");
		set("armor_prop/armor", 3);
	}
	setup();
}	
