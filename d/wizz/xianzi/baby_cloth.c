// jiasha.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIW"��"HIM"��"HIW"С�Ƕ�"NOR, ({"du dou", "dou", "cloth" }) );
        set("long", HIW"һ���ܱ��µ�С�Ƕ������滹����һ��"HIR"ʢ����ĵ����\n"NOR);
	set_weight(0);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 40);
		set("armor_prop/dodge", 50);
                set("armor_prop/personality", 10);
                set("value", 50000);

	}
	setup();
}

