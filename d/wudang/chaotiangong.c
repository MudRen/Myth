//Room: chaotiangong.c ���칬
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","���칬");
      set("long",@LONG
�����ѽ��䵱������ֻ��ʯ��ֱ�ʣ�Σ�Ÿ��������Ը���������������
����
LONG);
      set("exits",([ /* sizeof() == 1 */
          "north"    : __DIR__"wulaofeng",
          "south"    : __DIR__"toutiangate",
      ]));
      set("objects", ([
		__DIR__"npc/wulei": 1,
      ]));
      set("outdoors", "wudang");
      setup();
      replace_program(ROOM);
}

