// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/bei4.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

������������ĺܽ���·�����������������������ȥ���ǳ�
���֡�������һ��ջ����ʱ����������ǣ���ȥ��ϢЪ�š����Ͼ�
�������Ĵ��š�

LONG);

  set("exits", ([
        "north"      : __DIR__"bei3",
        "east"       : __DIR__"mazhan",
        "south"      : __DIR__"gongmen",
      ]));
  set("objects", ([
        __DIR__"npc/people" : 2,
  ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

