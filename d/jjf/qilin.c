// Room: /d/jjf/qilin.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG

̫���������ڼ�λǰ�ܷ�����������ı���½�Ϊ������������������
�����͡�����Ϊ��Щ������������һ����¥����Ի������󡹡���
¥���ܹҽǣ�������������������������ǰ���ۿ���
LONG
	);
	set("no_fight", 1);
	set("item_desc", ([ /* sizeof() == 1 */
  "up" : "¥���������������Ǵ�����յ�����������뺨��
",
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
           __DIR__"npc/qinbing" : 2,
            "/d/jjf/npc/chengyaojin": 1,
]));
	set("light_up", 1);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"qilin2",
  "east" : "/d/city/xuanwu-n0",
]));

	setup();
	replace_program(ROOM);
}
