// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/xi2.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

������������Ϣ�����ڼҵļң����Ļ���ֻ����ң���������
���Է򣬷�����ʳ������ʮ��ˬ�졣�����ǳ���֮·���򶫿���
�ִﱦ����������ϱ��мҷ��ݣ�Ʈ���������㡣

LONG);

  set("exits", ([
        "west"       : __DIR__"xi1",
        "east"       : __DIR__"xi3",
        "south"      : __DIR__"yangrou",
      ]));

  set("objects", ([
        __DIR__"npc/people" : 2,
  ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

