// nklace.c ������

#include <armor.h>

inherit NECK;

void create()
{
	set_name("��������", ({ "xiang lian", "necklace" }));

	set("weight", 500);
	set("long", "һ����Ӳӵ��������ǳ����ǵ���Ůϲ�������\n"
		"����ϸ�����ܾ��������ɫ�е㲻�Ծ���\n");
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	
