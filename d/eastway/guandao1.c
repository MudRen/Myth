// Room: /d/eastway/guandao1.c

inherit ROOM;

void create()
{
  set("short", "�ٵ�");
  set("long", @LONG

����һ�������Ĺٵ����ٵ��������У��������ϡ�����ȥ�ȶ�����
����ݷ��������Ů�����и��Դ��˼��е�̫̫С��Ϊ�ࡣ�ϱ߿�
������Ժ����Լһ����Ӱ�����º�
LONG
  );
  set("exits", ([ /* sizeof() == 3 */
    "northwest" : __DIR__"wangnan5",
    "south" : __DIR__"ciensiw",
  ]));
  set("objects", ([
    __DIR__"npc/luren"     : 2,
  ]));
  set("no_clean_up", 0);
  set("outdoors", __DIR__"");

  setup();
  replace_program(ROOM);
}
