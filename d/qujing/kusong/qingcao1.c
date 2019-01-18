//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

��������Խ��Խ�ܣ���ǰ���޵�·��ѭ������ż��Ұ�����
С���ܹ�������ϤϤ���µ�������
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"qingcao1",
  "south" : __DIR__"qingcao1", 
  "west" : __DIR__"qingcao1",
  "east" : __DIR__"qingcao1",
]));

  set("outdoors", 1);
  set("no_guo", 1);

  setup();
}

void init()
{
	add_action("do_search", "search");
}

int do_search()
{
	object where, me;
	where=this_object();
	me=this_player();

	if(me->is_busy())
		return notify_fail("����æ���أ�\n");

	if( !where->query("guo_called") ){
		set("guo_called", 1);
		call_out("guo_grow", 900);
	}

	message_vision("$N�������ѰѰ���١�����\n", me);
	call_out("do_find", 3, me);
	me->start_busy(3);
	return 1;
}
int guo_grow()
{
	delete("no_guo");
	return 1;
}
	
int do_find(object me)
{
	object where, guo;
	where=this_object();

	if( where->query("no_guo")){
		tell_object(me, "��ʲôҲû���֡�\n");
                return 1;
        }

	if( (int)me->query_kar() > random(1000) ){
		guo=new("/d/qujing/kusong/obj/heshouwu");
		guo->move(where);
		set("no_guo", 1);
		tell_object(me, "��ͻȻ������һ������ڡ�\n");
		return 1;
	}

	tell_object(me, "��ʲôҲû���֡�\n");
	return 1;
}
