
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;

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
                set("unique", 1);
                set("treasure", 1);
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
                set("no_drop", "�������������뿪�㡣\n");
                set("no_give", "�����������ܸ��ˡ�\n");
                set("no_get", "����������������\n");
                set("no_put", "�������������ҷš�\n");
	}
	init_sword(250);
	setup();
}
