// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "�Ѹ���");
  set ("long", @LONG

�Ѹ�������һ�ҿ͵꣬��ǰ����һ���ƣ����š��ԼҹѸ��ꡱ
������֡�������һ����Ⱦ����һЩ���̿�ǽ���ţ����봲֮
���Բ���������

LONG);

  set("exits", ([
        "east"    : __DIR__"jiedao8",
        "west"    : __DIR__"tianjing",
      ]));
  set("objects", ([
        __DIR__"npc/guafu"    : 1,
      ]));
  set("sleep_room",1);
  set("if_bed",1);
  setup();
}

