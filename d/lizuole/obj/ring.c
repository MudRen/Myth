// ring.c �����ָ

#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
	set_name(HIC "�����ָ" NOR, ({ "diamand ring", "diamand", "ring" }));
       	set("long", "���������͸�ѩ���Ķ����ָ���������������裬�淢������ˡ�\n");
	set("weight", 20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("value", 10000);
		set("material", "��ʯ");
		set("armor_prop/unarmed", 2);
                set("armor_prop/armor", 1);
                set("armor_prop/spells", 2);
		set("armor_prop/armor", 2);
		set("armor_prop/personality", 3);
		set("female_only", 1);
		//set("no_get", "�ٺ٣����ΰ�! \n");
		set("no_sell", "���������������\n");
		set("wear_msg", "$N����ذ�һ��$n������������ָ�ϡ�\n");
		set("unwield_msg", "$N����ذ�$n����������ָ�ϳ���������\n");

	}
	setup();
}	
