//Created by waiwai@2002/12/05
//343�������ɫ��ϣ����NAME2_D

#include <ansi.h>

inherit ITEM;

void create()
{
	mapping name;

	name=NAME2_D->random_name("yuhua");
	set_name(name["name"], name["id"]);

	set_weight(500);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	set("long", "һ��ɫ�ʰ�쵵�Сʯ�ӣ�ÿһ�����ƺ��ڽ�����һ�����¡�\n");
	set("unit", "��");
	set("value", 2000);
//	set("no_sell", 1);
	}
}
