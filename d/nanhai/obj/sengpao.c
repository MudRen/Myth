//Cracked by Roath
// cloth.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIY"ɮ��"NOR, ({ "seng pao", "pao", "cloth" }) );
	set("long", "����һ��Ѱ����ɮ�ۣ��Ǻ����ǵ���ͨװ����\n");     
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 15);
		set("armor_prop/spells", 10);
		set("armor_prop/dodge", 5);
	}
	setup();
}

