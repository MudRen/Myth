//Room: taizipo.c ̫����
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","̫����");
      set("long",@LONG
�˴��ش�����֮����������Ҫ���ഫ���ֹ�̫��(��������)��ɽ�޵�
ʱ�����ڴ���ס���飬������̫���£�����һ���ˮܽ�أ�ӿ���̲�����
������������Զ�����·ת���������𣬾�������֮�С�
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"shanlu1",
          "southwest"  : __DIR__"shibapan",
      ]));
      set("outdoors", "wudang");
      set("objects", ([
                __DIR__"npc/wulei": 1,
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
