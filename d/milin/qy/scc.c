// ���ֱ��� by Calvin

inherit ROOM;
#include <ansi.h>


void create ()
{
  set ("short","����");
  set ("long", @LONG

���������ֵ�һ��Ҫ��,��������Щ�����˳�û,�����ȴȫȻ��������Ӱ�ˡ�

LONG);

  set("exits", ([
        "south" : __DIR__"men",
        "north" : __DIR__"1",
      ]));
  set("outdoors", __DIR__);

  setup();
}


void init()
{       
        object me=this_player();
        if( query("done") ) return;
        if( interactive(me)) {
                remove_call_out("greeting");
                call_out("greeting",2, me);
        }
}
	
int greeting(object me)
{
	object *list, ob;
	int i;
	if( !me || environment(me) != this_object() ) return 1;
        tell_room(this_object(), "��Ȼһ��ڷ��Х����������\n");

	list=all_inventory(this_object());
	i=sizeof(list);
	while (i--)
	{
		ob=list[i];
                ob->move("/d/milin/qy/sc");
                message_vision("��̼�ڷ�ͣס�ˣ�$NҲ���Ժ���������һ���ط�������\n", ob);
	}
	this_object()->set("done");
	call_out("reg", 300);
	return 1;
}
int reg()
{
	this_object()->delete("done");
	return 1;
}

