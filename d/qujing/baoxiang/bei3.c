// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/bei3.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����˺ܶ࣬·���߲�ʱ������������������������һ��С��
�����ſڷ���ʽ�����ص�̺��ľ��֮���ֹ���Ʒ��·�����ۣ���
��ͨ���������š�

LONG);

  set("exits", ([
        "north"      : __DIR__"bei2",
        "east"       : __DIR__"zuofang",
        "south"      : __DIR__"bei4",
      ]));
  set("objects", ([
        __DIR__"npc/people" : 2,
  ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

