// Room: /d/qujing/wudidong/smithy.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG

������Ǵ���Ĵ������ˡ����������洫���������գ����´������
�����������˵��������������ռȺã�����Ͷ࣬�������æ����
����һ�߰����������۶��˵Ĺ��ߣ���һ�߰��������õ�����������
Щ���б���Ķ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road2",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/smith.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
