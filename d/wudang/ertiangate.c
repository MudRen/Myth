//Room: ertiangate.c ������
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","������");
      set("long",@LONG
�����ǡ������š������ӲӵĽ𶥾�����ǰ�ˡ�
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"toutiangate",
          "southup"  : __DIR__"santiangate",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
