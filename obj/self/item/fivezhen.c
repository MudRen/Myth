// Creat by waiwai@2000/11/28
//������װ�����ϵͳ��

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM"����֮��"NOR, ({"five-needle"}));
	set_weight(100);
	if( clonep() )
    		set_default_object(__FILE__);
  	else {
		set("no_sell",1);
		set("value",100000);
		set("no_drop",1);
		set("no_steal",1);
		set("no_give",1);
		set("no_sell",1);
		set("can_auction", 1);
		set("unit","��");
		set("long","һ��ϸ�������룬��ʰ��,������ţ���ľˮ����������ӬͷС�֡�\n");
	}
	setup();
}
