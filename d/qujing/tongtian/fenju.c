//Cracked by Roath
// Room: /d/qujing/tongtian/fenju.c

inherit ROOM;

void create()
{
	set("short", "��Զ�ھ�");
	set("long", @LONG

��Զ�ھֵĴ�ʼ������Ӣ������Զ������Ӣ�������Ѹߣ����Ѳ�����
�����Ƿ��ˡ������ھֵĶ�������������Զ�Ĵ�������������Ժ
�������᷿����ǽ����һЩ������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"chen2",
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  "/d/city/npc/biaotou" : 1,
]));

	setup();
	replace_program(ROOM);
}
