// Room: /u/hkgroup/yard3
inherit ROOM;

void create ()
{
  set ("short", "����Ժ");
  set ("long", @LONG

����������ͥ���վ���������濾ꡣ�������̾����ҹδ�ߡ�
��������ƾ������䣬��ʯ�����̡����������������Ӧ������

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"bridge",
  "backyard" : __DIR__"bull",
]));
  set("outdoors", "/u/hkgroup");

  setup();
}
