//Room: songlin3.c ����
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
      set("objects", ([
           __DIR__"npc/monkey": 2,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "west"       : __DIR__"jiejianyan",
          "northwest"  : __DIR__"songlin2",
      ]));
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
