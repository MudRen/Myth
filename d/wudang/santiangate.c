//Room: santiangate.c ������
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","������");
      set("long",@LONG
�����ǵ�ɽʯ�׵ľ�ͷ�������š����������߾����䵱�����ˡ�
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"ertiangate",
          "southup"  : __DIR__"jinding",
      ]));
      set("outdoors", "wudang");
      set("objects", ([
		__DIR__"npc/wulei": 1,
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
