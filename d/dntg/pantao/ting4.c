// created by snowcat.c 5/23/1997
// room: /d/pantao/ting4.c

inherit ROOM;

void create ()
{
  set ("short", "��ϼͤ");
  set ("long", @LONG

ֻ����ϼ��ҫ������ƮƮ��ͤ���ɻ�ʢ���������ơ����з���
һ������������������֥���ݡ�ϼͤ���ĸ��������߸���
����Χ��������ơ�

LONG);

  set("exits", ([
        "north"     : __DIR__"ting3",
        "south"     : __DIR__"ting5",
        "east"      : __DIR__"pan2a",
      ]));

  set("objects", ([
         __DIR__"npc/xiannu4"  : 1,
     ]));

  setup();
}

