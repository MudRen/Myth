// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/xi4.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���������������ˣ�·���������������ȥ���ǳ����֡���
����һ������Ÿ�ʽ���������������Ϸ������ԶԶ�ؿ���������
Ⱥ��Ⱥ�

LONG);

  set("exits", ([
        "west"       : __DIR__"xi3",
        "north"      : __DIR__"xiqi",
        "northeast"  : __DIR__"gongmen",
      ]));
  set("objects", ([
        __DIR__"npc/people" : 2,
  ]));

  set("outdoors","/d/qujing/baoxiang");

  setup();
}

