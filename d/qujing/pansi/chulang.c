// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

������һ��Ȼʯ�ð�Ų��̣�����һ�ڴ�ͭ������ʲô�⡣
�Ա��Ƿ���������ʯ��������ʯ��ʯ�̡������ʯͷ��������
ٲȻһ��ʯ�ʡ�

LONG);

  set("exits", ([
        "east"    : __DIR__"shiyuan",
      ]));
  set("objects", ([
        __DIR__"obj/doufu"    : 1,
        __DIR__"obj/mianjin"    : 1,
      ]));
  setup();
}

