# include <skill.h>
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(WHT"��ʯ"NOR, ({"jing shi", "shi"}));
	set_weight(500);
	if( clonep() )
    		set_default_object(__FILE__);
  	else {
		set("no_sell",1);
		set("value",100);
		set("unit","��");
		set("long","һ����ͨ�ľ�ʯ�������Ǵ�˵���߲�ˮ���绯��Ĳ��\n");
	}
	setup();
}
