// Created by aeddy@2001/03/03
// Last modified by aeddy@2001/06/20

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW"���"HIB"�ٶ���"NOR,({"pidu-zhu"}));
	set("long","��������һ�������ѵõı���,����������"HIR"�������壩"NOR"����\n");
	set("unit","��");
	set("no_put",1);
	set("no_drop",1);
	set("no_sell",1);
	set("no_give",1);
	set("no_break",1);
	set("no_des",1);
	set("no_putin",1);
	set("no_stock",1);
	set("no_putto",1);
	set("deadfly",1);

}

void init()
{
	if(this_player()==environment()) 
	add_action("do_cure","cure");
}

int do_cure()
{
	object me;
	me=this_player();

	message_vision("$N���ٶ���ŵ��˴����˼���!\n",me);
	me->clear_condition();
	message_vision("$Nֻ������һ������ֱ͸ȫ����!\n",me);
	return 1;
}


