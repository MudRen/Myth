// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/jieshi6.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

ӵ���ĳ��ٹ����У�����שʯ�̳ɡ��������У��־�����������
Ŀ��Ͼ���������в����������شҴ��߹���ż����ЩС����;��
�߽б�����ʲô��

LONG);

  set("exits", ([
        "west"         : __DIR__"shutang",
        "east"         : __DIR__"xi",
        "north"        : __DIR__"taiping",
        "south"        : __DIR__"jieshi8",
      ]));

  set("objects", ([
        __DIR__"npc/people" : 2,
  ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

