//Room: songlin1.c ����
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","����");
      set("long",@LONG
������������������գ�������ֻ�о�������ǰ�󵽴�
������Ӱ��������һ�����������ã�������ӫӫ���׹⡣�㾪
��֮�䣬һ�Ų��ڸ����������ϣ�
LONG);
      set("objects", ([
           __DIR__"npc/yetu": 2,
      ]));
      set("outdoors", "wudang");
      set("exits",([ /* sizeof() == 1 */
          "northeast"  : "/d/kaifeng/chen2",
          "south"  : __DIR__"songlin2",
      ]));
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
