//Last modified by waiwai@2001/03/23

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "��ɫ��ʯ" NOR, ({ "silver stone", "stone" }) );
	set_weight( 10000 );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ɫ����ʯ�����溬��һЩϡ�е����ʡ�\n");
		set("value", 100);
		set("can_auction", 1);
    };
}

