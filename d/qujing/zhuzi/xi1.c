// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "Ϧ����");
  set ("long", @LONG

Ϧ�����ǳ����ţ����Ž��ܣ�¥��Ʈ��һ�ӻ������顰���Ϲ�����
�����֣�һЩУξ���ſ�Ѳ�顣���߷�����������ʳ��Ϧ�ֽ֣�Ʈ
�����󷹲��㡣

LONG);

  set("exits", ([ 
    "east" : __DIR__"xi2",
  ]));
  set("objects", ([
    __DIR__"npc/xiaowei" : 2,
  ]));
  set("objects", ([
    __DIR__"npc/people" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}

int valid_leave(object who, string dir)
{
  if (! interactive(who) &&
      dir == "west")
    return 0;
  return ::valid_leave(who, dir);
}
