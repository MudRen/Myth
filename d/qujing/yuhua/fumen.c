// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���Ÿߴ���ΰ�������˸��һ���ǽ�����ˮ����һ�������ﳯ
�����������������������������￴��¥�󹬵�����������
�����ơ�

LONG);

  set("exits", ([
        "north"   : __DIR__"xiaojie7",
        "south"   : __DIR__"dayuan",
        "west"   : __DIR__"jitan",
      ]));
  set("objects", ([
        __DIR__"npc/bing"  : 2,
      ]));
  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive(who) &&
      dir == "south")
    return 0;

  return ::valid_leave(who,dir);
}

