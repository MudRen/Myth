//Created by waiwai@2001/04/25

#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
	set_name(WHT"��"NOR, ({ "gui hua","hua" }) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", WHT"һ���������֮����ǳ��ɫ�Ļ��䣡\n" NOR);
		set("base_unit", "��");
              set("unit", "Щ");
		set("value", 1);
		set("no_sell",1);
		set("no_put",1);
	}
	set_amount(1);
	setup();
}
