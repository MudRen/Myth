// Room: /d/qujing/wudidong/road3.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG

���洫��һ����Ķ���������˵��ȸ��С�������ȫ����Ȼ���١���
����ô��С�壬����ѧ�á��㲻���Ա��صĴ�����Ȼ�𾴡���������
�����ž�ס���ϱߡ��㲻����ȥ�ݷðݷã����ʱ��صķ������顣
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"exit",
  "south" : __DIR__"zhanghome",
  "north" : __DIR__"xuetang",
  "east" : __DIR__"road2",
]));
	set("no_clean_up", 0);
	set("outdoors", "1");

	setup();
	replace_program(ROOM);
}
