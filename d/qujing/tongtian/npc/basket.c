//Cracked by Roath
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("����",({"devine basket"}));
	set("long", "һֻ���ɵ����������������֯�ɵģ�\n");
	set("material","magic");
	set_weight(100);
	set_max_encumbrance(400000);
	if(clonep())
		set_default_object(__FILE__);
	else{
	set("unit", "ֻ");
	set("no_get", 1);
	set("no_drop",1);
	set("no_sell",1);
	set("no_give",1);
	set("amount", 1);
}
	setup();
}
int is_container() {return 1;}
