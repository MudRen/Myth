// Room: /d/jjf/qilin2.c

inherit ROOM;

void create()
{
	set("short", "������¥");
	set("long", @LONG
��¥����һ¥����ֻ�и��Ӻ������ɡ�ǽ�ϻ��ż���ɳ������
һ������������ȡ�أ�һ���ǳ�ҧ�����彫��ϯ��һλ����������
�ڿ������������⣬�������վۼ��ڽֶ���һ����¥ǰָָ��㡣
LONG
	);
	set("light_up", 1);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yuchigong" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"qilin",
]));

	setup();
	replace_program(ROOM);
}
