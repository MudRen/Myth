// created by snowcat.c 5/23/1997
// room: /d/pantao/ting2.c

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
        "north"     : __DIR__"ting1",
        "south"     : __DIR__"ting3",
        "east" : __DIR__"pan1a",
      ]));

  set("objects", ([
         __DIR__"npc/xiannu2"  : 1,
     ]));

  setup();
}

