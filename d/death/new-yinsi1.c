// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "��˾");
  set ("long", @LONG

��˾�ں���ɭɭ������С�������ķ������ҷֱ�������ש�߷���ż
����Щ��˾�˳��롣��ɫһƬ�������������Ѫɫ��
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"new-sifang1",
  "east": __DIR__"new-sifang2",
  "north": __DIR__"new-walk3",
]));
  set("hell", 1);

  setup();
}


