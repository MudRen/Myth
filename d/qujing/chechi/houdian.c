// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/houdian.c

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

������������ƣ���������������������һ̨���Ϸ���ͭ����
�����ɡ��˿�����������ƻ�ͨ����������������������
�ǲؾ�¥��

LONG);

  set("exits", ([
        "south"        : __DIR__"sanqing",
        "northwest"    : __DIR__"cangjing",
      ]));
  set("objects", ([
         __DIR__"npc/daotong"    : 2,
      ]));
  setup();
}

