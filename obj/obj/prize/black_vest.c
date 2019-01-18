// black_vest.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��˿����", ({ "black vest", "vest" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"�����˿���Ŀ�����������ز���ô���ۣ����ұ�һ����·�\n"
			"����Щ������ϸһ�����������Ϸǽ�ǲ���ȴ��֪��ʲô����\n"
			"֯�ɵġ�\n");
		set("unit", "��");
		set("value", 14000);
		set("material", "blacksilk");
		set("armor_prop/armor", 30);
		set("armor_prop/armor_vs_force", 70);
		set("armor_prop/attack", -5);
	}
	setup();
}

int query_autoload() { return 1; }
