// Room: /u/hkgroup/bridge
inherit ROOM;

void create ()
{
  set ("short", "�߷�բ");
  set ("long", @LONG

�������ű�ͨ���֮բ����Ȫ�����ߡ�

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"main",
  "north" : __DIR__"yard3",
  "down" : __DIR__"cool",
]));
  set("outdoors", "/u/hkgroup");

  setup();
}
