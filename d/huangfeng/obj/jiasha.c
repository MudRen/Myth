// d/qujing/huangfeng/obj/jiasha.c
//��ħ����      // created by angell 1/1/2001

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
inherit F_UNIQUE;

void init()
{
  cloth::init();
  unique::init();
}

void create()
{
	set_name(HIY"��ħ����"NOR, ({ "xiangmo jiasha", "jiasha" }) );
	set("long", "����������������֮��ħ���ģ����Ͽ���ǿ��ħ������\n");
	set_weight(2800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 60);
		set("armor_prop/spells", 40);
		set("armor_prop/dodge", 30);
		set("replace_file", "/d/obj/cloth/hufa-jiasha");
                set("value", 50000);
	}
	setup();
}

