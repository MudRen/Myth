// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("����", ({"ji dao", "dao", "blade"}) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 300);
		set("material", "iron");
		set("long", "����һ���Զ�һ��ļ�����\n");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
	init_blade(20);
	setup();
}
