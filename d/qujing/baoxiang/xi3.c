// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/xi3.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����ɴ�ɽ��������ʯ�������ɣ�����ȥ����·�����˲��٣�
���װ�����ء����Ϸ�����ȥ���Լ������ߴ�Ĺ������
�����������ڵء�

LONG);

  set("exits", ([
        "west"       : __DIR__"xi2",
        "east"       : __DIR__"xi4",
      ]));
  set("objects", ([
        __DIR__"npc/people" : 2,
  ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

