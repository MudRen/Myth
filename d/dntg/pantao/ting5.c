// created by snowcat.c 5/23/1997
// room: /d/pantao/ting5.c

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
        "north"     : __DIR__"ting4",
        "south"     : __DIR__"ting6",
        "northeast" : __DIR__"pan2a",
        "southeast" : __DIR__"pan3a",
      ]));

  set("objects", ([
         __DIR__"npc/xiannu5"  : 1,
     ]));

  setup();
}

