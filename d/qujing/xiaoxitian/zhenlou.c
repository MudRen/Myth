// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "��¥");
  set ("long", @LONG

��¥����˼�����ľ���ӣ������Ϸ���һЩ������ӣ�������
����һЩի�����ű��м��Ż�Ƥ���Σ���������С�輸����¥
���ϱ�����ͨ����۱��

LONG);

  set("exits", ([
        "south"   : __DIR__"daxiong",
      ]));
  set("objects", ([
        __DIR__"npc/tong"   : 3,
        __DIR__"obj/zhaiguo"   : 2,
      ]));

  setup();
}



