// Created by waiwai@2001/03/03
// Last modified by waiwai@2001/03/25

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY"�ٶ���"NOR,({"pidu-dan","dan"}));
	set("long","��������һ�������ѵõı���,����������"HIR"�������壩"NOR"�ٶ���\n");
	set("value",30000);
	set("unit","��");
}

void init()
{
	if(this_player()==environment()) 
	add_action("do_cure","cure");
}

int do_cure()
{
	object me;me = this_player();
	message_vision("$Nһ�ڽ��ٶ������븹��!\n",me);
	me->clear_condition();
	message_vision("$Nֻ������һ������ֱ͸ȫ����,���о綾��Ȼ���ٷ�����!\n",me);
	destruct(this_object());
	return 1;
}
