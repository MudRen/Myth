// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/jieshi9.c

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
        "north"        : __DIR__"jieshi7",
        "east"         : __DIR__"long",
        "south"        : __DIR__"jieshi10",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

