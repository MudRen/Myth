inherit ROOM;
#include <room.h>
int test_player (object who);

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����ǻ��������������ʻ������Ǳ��ж��졣
LONG);
 
  set("exits", ([
        "north"  : __DIR__"ermen",
        "south"  : __DIR__"dating",
      ]));
  create_door("north", "ʯ��", "south", DOOR_CLOSED);
  setup();
  "obj/board/shibei_b"->foo();
}
int valid_leave(object me, string dir)
{
	object ob0;
	object yao = new("/d/qujing/guanyin/npc/guai");
        if ( dir == "south" ){
	if (!test_player(me)){
		ob0 = present("yao guai",environment(me));
		if (!ob0)
			yao->move(environment(me));
	        return notify_fail("���ź�������С���ȵ���ʲô�ˣ�����Ϲ������������\n");
        }
	}
        return ::valid_leave(me, dir);
}

int test_player (object who)
{
  string *names;
  string name;
  names = who->query_temp("apply/name");
  if (! names)
    return 0;
  if (sizeof(names) < 1)
    return 0;
  name = names[0];
  if (name == "������")
    return 1;
  if (name == "����")
    return 1;
  return 0;
}
