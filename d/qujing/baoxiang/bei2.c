// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/bei2.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����������������������������Է򵣲񣬳��ڼҵļң���
�Ļ���ֻ����ң���������������ӹ���ʮ��ˬ�졣���ǳ��ţ�
�������������ڡ�

LONG);

  set("exits", ([
        "north"      : __DIR__"bei1",
        "south"      : __DIR__"bei3",
      ]));
  set("objects", ([
        __DIR__"npc/people" : 2,
  ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

