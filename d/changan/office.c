// Room: /u/wuliao/housingoffice
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG
��ˮ�ӱߵľ��������࣬����ر��ڴ���������������ʱ��
һ����֪������ͷ����
LONG);


	set("no_fight", 1);
	set("no_magic", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/adm/npc/officer" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 1 */
// 20    "east" : "/adm/npc/phome",
  "east" : __DIR__"ph",
]));

  setup();
}
