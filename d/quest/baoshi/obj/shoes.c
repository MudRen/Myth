// shoes.c

#include <armor.h>
#include <ansi.h>

inherit BOOTS;


void create()
{
	set_name(YEL "̤��ѥ" NOR, ({ "shoes" }) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "�Ϲ�ʮ�����֮��̤��ѥ��  \n");
		set("material", "cloth");
                set("no_put",1);
                set("no_sell",1);
                set("no_give",1);
                set("no_zm",1);
		set("unit", "˫");
                set("armor_prop/armor", 30 );
                set("armor_prop/dodge", 20 );
	}
	setup();
}


