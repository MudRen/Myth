//Cracked by Roath
//huludi.c
#include <ansi.h>

inherit ROOM;

void create ()
{
	set ("short", "���ϵ�");
	set ("long", @LONG

��ׯ�����µĶ࣬�Է���Ҳ���٣����Թ��ڹ��˸�����һЩũ��
�����߲˹Ϲ������������ϵء���������һ��������ɵ���ʣ�
����Ͽ���һ����ª����ľ�ţ����Ϲ���һ�ѻ�ͭ����
LONG);

	set("exits", 
	([ //sizeof() == 4
		"southeast" : __DIR__"baicaidi",
		"southwest" : __DIR__"huludi",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		"/d/obj/food/watermelon" : 3,
	]));

	//create_door("north", "��ľ��", "south", DOOR_CLOSED);
	set("outdoors", "wuzhuang");

	setup();
}

void init()
{
	add_action("do_open", "open");
}

int do_open(string arg)
{
	object me, key, nroom;

	me = this_player();

	if( !arg || arg != "door" ) 
		return notify_fail("��Ҫ��ʲô��\n");

//    if( !(key = present("huangtong key", me) && key->query("id")=="huangtong key") ) 
  key=present("huangtong key",me);
  if (!key || key->query("id")!="huangtong key")
		return notify_fail("��û�п�����ŵ�Կ�ס�\n");

	//now we are ready to open...
	if( !(nroom = find_object(__DIR__"renshenguo-yuan")) )
		nroom = load_object(__DIR__"renshenguo-yuan");

	nroom->set("exits/south", __FILE__);
  message_vision("$NС������ؽ�Կ�ײ���׿ס�\n",me);
  message_vision(HIW"��ľ��ͻȻ����һ��ǿ�ҵİ׹⣬�յ����������ۡ�\n"NOR,me);
  me->set_temp("used_huangtong_key",1);
  tell_room(environment(me),"�Ȱ׹���ȥ��������һ��������"+me->name()+"�ӿ�������ʧ�ˣ�\n",me);
  me->move(nroom);
  tell_object(me,"�Ȱ׹���ȥ��������һ��������������һ��İ���ĵط���\n");

	destruct(key);
	return 1;
}


