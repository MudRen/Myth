
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name( HBWHT "���е�" NOR , ({ "niren sword", "sword" }));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",  HIG "����һ�����е����˽��ƺ����Ÿ����ܡ�\n" NOR );
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(200);
	setup();
}
