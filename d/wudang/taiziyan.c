//Room: taiziyan.c ̫����
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","̫����");
      set("long",@LONG
������Ⱥɽ�����е�̫���ң�������һ������ʯ��һ��̫��ͤ��
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"shanlu4",
          "southdown": __DIR__"langmeiyuan",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
