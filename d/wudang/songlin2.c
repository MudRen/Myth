//Room: songlin2.c ����
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","����");
      set("long",@LONG
������������������գ�������ֻ�о�������ǰ�󵽴�
������Ӱ��������һ�����������ã�������ӫӫ���׹⡣�㾪
��֮�䣬һ�Ų��ڸ����������ϣ�
LONG);
      set("outdoors", "wudang");
      set("exits",([ /* sizeof() == 1 */
          "north"      : __DIR__"songlin1",
          "southeast"  : __DIR__"songlin3",
      ]));
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
