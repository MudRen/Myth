// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "ľ��ͤ");
  set ("long", @LONG

ľ��ͤ�˽����磬���ݻ��ơ��紵ͭ�嶡�����ࡣͤ����һС
Ϫ�����������������š�ͤ�ӵĶ�����é���ݣ����Ͽɼ�һʯ
ͷ�Ŷ���

LONG);

  set("exits", ([
        "east"    : __DIR__"maowu",
        "south"   : __DIR__"shitou",
      ]));
  set("objects", ([
        __DIR__"npc/girl2"    : 1,
        __DIR__"npc/girl3"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

