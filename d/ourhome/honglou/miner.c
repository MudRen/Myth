// Room: /d/ourhome/honglou/miner
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

    �����ڲ�ס����ɽ�����������ϵ���ˮ���ơ�

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"yard2",
]));
  set("no_fight", 1);
  set("light_up", 1);
  set("no_magic", 1);

  setup();
}
