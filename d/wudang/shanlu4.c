//Room: shanlu4.c ɽ·
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
          "northdown": __DIR__"shijie1",
          "southup"  : __DIR__"taiziyan",
      ]));
      set("objects", ([
           __DIR__"npc/wuya": 1,
      ]));

      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
