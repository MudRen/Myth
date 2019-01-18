#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

���Ͼ���Ѿ�棬޵��ǣ�ơ����������е�·�ĺۼ�������ȴ����
���Ǽ��룬�����߳���ض��Σ����ɹ�ȥ����Χ����ϡ�٣���ɽ
��������Գ�䲻����
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/hunter" : 2,
]));

  set("outdoors", 1);

  set("exits", ([ /* sizeof() == 2 */
    "eastdown" : __DIR__"jingji5",
]));

  setup();
}

void init()
{
  add_action("do_clean", "bo");
  add_action("do_clean", "clean");
  add_action("do_clean", "push");
  add_action("do_clean", "pushaside");
}
int do_clean(string arg)
{	int i;
	object ob=this_object();
	object me=this_player();
	object obj;
        if(!arg || arg != "jingji" )
                return notify_fail("��Ҫ��ʲô��\n");
	
        if(query("clean"))
                return notify_fail("��Χ�Ѿ�û�о����ˡ�\n");

	if((int)me->query("kee") <50)
                return notify_fail("��̫���ˣ�ЪЪ�ɣ�\n");

	if(!(obj = me->query_temp("weapon")) ){
		message_vision("$N������ȥ���Ǿ�����ȴ����������Ѫ��\n", me);
		return 1;
	} else {
		message_vision("$N��������$n��С�ĵ�ȥ�����ǶѶѾ�����\n", me, obj);
		me->receive_damage("kee", 50);
		i=(int)me->query_str();
		ob->set("coe",(int)ob->query("coe") + i );
		
		if( i < 30 ){	
			tell_room(environment(me), "���ֻ������֦С�̡�\n"); 
		}
		else if (i < 50 ) { 
			tell_room(environment(me), "�������һƬ������\n");
		}
		else if (i < 100 ) {
			tell_room(environment(me), "ֻ���������ƵĲ�ס���ˡ�\n");
                }
		else tell_room(environment(me), "ֻ�������糱ˮ���˺�\n");
	}
	
	if( (int)ob->query("coe") > 1000 ) {
		tell_room(environment(me), "�������Ƶ����ԣ�����һ����·��\n\n");
		me->set_temp("obstacle/jingji/clean_6", 1);
		call_out("done", 1);
	}
	return 1;
}
int done()
{
	set("long", @LONG

���Ͼ���Ѿ�棬޵��ǣ�ơ�������һ����·�ĺۼ������ҵľ���
�����ѱ��Ƶ�һ�ԣ�С���й�ȴ���ް�����Χ����ϡ�٣���ɽ��
������Գ�䲻����
LONG);
	set("clean", 1);
	set("coe", 0);
	set("exits/northwest", __DIR__"jingji7");
	return 1;
}
