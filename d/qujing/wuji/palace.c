// Room: /u/mimi/zhuziguo/palace.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

�������ڼ������ټ����ӣ����ֹ��Ҵ��µĵط����ı��������ʣ�
������񡣽��³���������Ϣ�������Ⱥ������ּ�⡣

LONG);

  set("exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"huilang.c",
    "south" : __DIR__"zym.c",
  ]));
  set("objects", ([
      __DIR__"npc/taijian" : 2,
      __DIR__"npc/chen" : 3,
      __DIR__"npc/kingfake" : 1,
  ]));

  setup();
}
