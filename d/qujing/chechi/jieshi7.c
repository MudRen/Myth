// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/jieshi7.c

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
        "west"         : __DIR__"dong",
        "north"        : __DIR__"ruizhao",
        "south"        : __DIR__"jieshi9",
      ]));

  set("objects", ([
        __DIR__"npc/people" : 2,
  ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

