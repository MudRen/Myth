// Room: /city/kedian3.c

inherit ROOM;

void create ()
{
  set ("short", "·�ľ�ͷ");
  set ("long", @LONG
�������Կ������Ѿ�����·�ľ�ͷ������ֻ��һ��Сͤ��
ͤ�����Ҵ��飺���ۼ�ͤ����
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kedian3",
  "south" : __DIR__"xiaoting",
]));

              set("no_magic", 1); 
        set("no_fight",1);
  setup();
}






