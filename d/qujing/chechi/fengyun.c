// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/fengyun.c

inherit ROOM;

void create ()
{
  set ("short", "���Ƶ�");
  set ("long", @LONG

������ϼ���ƣ�������������ʮ�㡣����ϻ������ַ�������
�Ļ�����̬���졣������һ�˽�����������ȼ�ž������㣬��
���˱ǡ�

LONG);

  set("exits", ([
        "south"        : __DIR__"jishui",
        "east"         : __DIR__"jinluan",
      ]));

  set("objects",([
         __DIR__"npc/taijian" : 1,
      ]));
  setup();
}

