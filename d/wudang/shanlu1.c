//Room: shanlu1.c ɽ·
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","ɽ·");
      set("long",@LONG
�����ڵ�ɽ��·���ϣ�·�����Ҹ���һ����������������������ɽ��ɽ
��������ȥ����������ľ�е�����������Ļ�С�
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northeast": __DIR__"haohanpo",
          "southup"  : __DIR__"taizipo",
          "east"     : __DIR__"mozhenjing",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
