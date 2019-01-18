// phone.c 
// it will send you to someone place
// usage: dial <someone>

#include <ansi.h>

inherit ITEM;

int do_dial(string);
void init();

void create()
{
	set_name(HIG "�ռ䴫����" NOR, ({ "space phone", "phone", "space"}) );
	set_weight(50);
	set_max_encumbrance(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "̨");
                set("long", @LONG
���Ǹ���������ô����Ķ�������֪��ʲô����ȴ���Ž����Ĺ���
������ȥ�˼ҵĺ��룬���ͻ�����͵��Ƕ��� dial <someone>
LONG
                );

set("is_monitored",1);
		set("value", 1000);
		set("material", "steel");
		set("no_get",0);
	}
	setup();
}

void init()
{
        if(wizardp(this_player())) {
	  add_action("do_dial", "dial");
	}
}


int do_dial(string arg)
{

	object me;

	me=this_player();

	if (!arg)
	{
		return notify_fail("��Ҫȥ���\n");	
	}
	if ( file_size("/u/"+arg+"/workroom.c")<0)
	{
	   message_vision("�ռ䴫������$N˵����û����ҡ�\n",me);
         return notify_fail(""); 
	}

      message_vision("�ռ䴫������$N˵������ͨ����\n", me);
	
      me->move("/u/"+arg+"/workroom.c");
      
      message_vision("�ռ䴫������$N˵�����㵽�ˡ�\n", me);
	return 1;
}
