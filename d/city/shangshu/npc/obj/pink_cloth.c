//Creat by waiwai@2001/05/12

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�ۺ����", ({ "pink cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����ۺ�ɫ�ĳ�������������ֻ��ȵ������������һ�ɵ��㡣\n");
		set("unit", "��");
		set("value", 600);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor/max_armor", 1);//By waiwai@2001/07/29 added.
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

