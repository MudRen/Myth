// created by snowcat.c 5/23/1997
// room: /d/pantao/ting6.c

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
        "north"     : __DIR__"ting5",
        "south"     : __DIR__"ting7",
        "east" : __DIR__"pan3a",
      ]));

  set("objects", ([
         __DIR__"npc/xiannu6"  : 1,
     ]));

  setup();
}

