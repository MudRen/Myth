// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "�Է�");
  set ("long", @LONG

�Է��ĵ�������Ұ�ݸɻ����ϱߵ�ʯ��ǰ��һ��ľ���������
��һյ����ƣ����ߵ�ʯ������һʯ�衣�Է���������һ����
ͨ���ڵ

LONG);

  set("exits", ([
        "west"   : __DIR__"neidian",
      ]));
  set("objects", ([
        __DIR__"npc/yao2"   : 2,
        __DIR__"npc/laonai"   : 1,
        __DIR__"obj/food"   : 4,
      ]));

  setup();
}


