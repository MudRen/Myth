// nichang.c ��ˮ����

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��ˮ����", ({ "nichang", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����������������˵ı�ɫ��ȹ��������ز�֪��ʲô�������ɡ�\n");
		set("unit", "��");
		set("value", 8000);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 5);
		set("female_only", 1);
	}
	setup();
}




