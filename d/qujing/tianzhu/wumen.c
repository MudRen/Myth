// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

һ����������������ʯǽ������Χ��������Կ�����ΰ�Ĺ�
��¥�󡣹���Ϊһ�޴������Ƕͭľ�ţ��ߴ����¥��������
�̽���֣����š�

LONG);

  set("exits", ([
        "north"   : __DIR__"zhaoyang",
        "south"   : __DIR__"jiedao45",
      ]));
  set("objects", ([
        __DIR__"npc/bing"   : 2,
        __DIR__"npc/siwei"   : 2,
      ]));
  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object who, string dir)
{
  object king = present("guo wang",this_object());

  if (king)
    return ::valid_leave (who, dir);
  if (! interactive (who) &&
      who->query("people") == "people" &&
      dir == "north")
    return 0;
  if (interactive (who)  &&
      dir == "north" &&
      ! who->query_temp("obstacle/tianzhu_thrown"))
    return notify_fail ("�ʹ�������ǹһ�ᣬ���ϵغ���һ�������У�\n");
  return ::valid_leave (who, dir);
}

