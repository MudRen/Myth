// create by snowcat.c 4/8/1997
// room: /d/westway/shizhen.c

inherit ROOM;
#include <ansi.h>


void create ()
{
  set ("short","ʯջ��");
  set ("long", @LONG

����һ���������ô�ʯ���̳ɵ�ջ����Զ��ջ�����ʯ�£���
�ò����еĵط���ʯ��·��·����˵������Զһ�����������
�������ˣ�������ȥ��Ȫ�ķ���

LONG);

  set("exits", ([
        "east" : __DIR__"jiuquan",
        "west" : __DIR__"jiayu",
      ]));
  set("outdoors", __DIR__);
       set("tsj_exst","west");

  setup();
}


void init()
{       
        object me=this_player();
        if( query("done") ) return;
        if( interactive(me)) {
                remove_call_out("greeting");
                call_out("greeting",25, me);
        }
}
	
int greeting(object me)
{
	object *list, ob;
	int i;
	if( !me || environment(me) != this_object() ) return 1;
	tell_room(this_object(), "���Ȼ���ý��µ�ʯ���ɶ��ˡ�����\n");

	list=all_inventory(this_object());
	i=sizeof(list);
	while (i--)
	{
		ob=list[i];
                if (! objectp(ob)) continue; // mudring...
		ob->move("/d/westway/tielong");
		message_vision("���ˡ���һ����$N�ӻ��ص����������С�����\n", ob);
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

