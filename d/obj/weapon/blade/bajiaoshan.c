// bajiaoshan.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("�Ž���", ({ "baojiao shan","shan" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 200);
		set("material", "wood");
		set("long", "һ�ѰŽ����ɵ����ӡ�\n");
		set("wield_msg", "$N�ó�һ�ѰŽ������˼��ȡ�\n");
		set("unwield_msg", "$N���˼��ȣ���$n������䡣\n");
	}
	init_blade(10);
	setup();
}
