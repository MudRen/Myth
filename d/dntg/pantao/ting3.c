// created by snowcat.c 5/23/1997
// room: /d/pantao/ting3.c

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
        "north"     : __DIR__"ting2",
        "south"     : __DIR__"ting4",
        "northeast" : __DIR__"pan1a",
        "southeast" : __DIR__"pan2a",
      ]));

  set("objects", ([
         __DIR__"npc/xiannu3"  : 1,
     ]));

  setup();
}

