//Cracked by Roath
// Room: /d/qujing/baoxiang/fenju.c

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
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"bei4",
]));
	set("objects", ([ /* sizeof() == 1 */
  "/d/city/npc/biaotou" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
