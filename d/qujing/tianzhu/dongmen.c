// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

һ�������Ļ��Ǻӳ�������ǰ�������ɶ���������һ�޴�
������ľ�š���ͷ��һ�ߴ�ĳ�¥����ɽʯ���ɣ�¥��������
���ڡ���¥�����������֣����ù���

LONG);

  set("exits", ([
        "east"   : __DIR__"dalu2",
        "west"   : __DIR__"jiedao57",
        "north"   : __DIR__"jiedao48",
        "south"   : __DIR__"jiedao68",
      ]));
  set("objects", ([
        __DIR__"npc/bing"   : 2,
      ]));
  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive (who) &&
      who->query("people") == "people" &&
      dir == "east")
    return 0;
  return ::valid_leave (who, dir);
}

