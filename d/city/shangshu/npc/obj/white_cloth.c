//Creat by waiwai@2001/05/12

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�°�ɫ��ȹ", ({ "white cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "��򵥵���һ���°�ɫ��ȹ�����沢û��ʲôװ�Σ����ܸ���һ���������ӵĸо���\n");
		set("unit", "��");
		set("value", 600);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor/max_armor", 1);//By waiwai@2001/07/29 added.
		set("armor_prop/personality", 4);
		set("female_only", 1);
	}
	setup();
}

