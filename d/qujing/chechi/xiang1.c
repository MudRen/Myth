// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/xiang1.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���������ȣ��������⻨�����������Ϲ��д���ͭ�壬��綣
������������һ����ɫ��̺�����ȵ����Ϸ�������������
ͨ���᷿��

LONG);

  set("exits", ([
        "southwest"    : __DIR__"sanqing",
        "east"         : __DIR__"xiang2",
      ]));
  set("objects", ([
         __DIR__"npc/daoshi"    : 1,
      ]));
  setup();
}

