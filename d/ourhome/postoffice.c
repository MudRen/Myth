// Room: /d/ourhome/mbox.c
// 96/10/03 by none

inherit ROOM;

void create()
{
	set("short", "������ž�");
	set("long", @LONG

    �����Ǻ�����ž֡�(instructions)�

LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "instructions" : "
    ������д����
    �����ʮ����ư��С��ѯ�ʼ��Ż����ŵĳ���

",
]));
	set("exits", ([ /* sizeof() == 1 */
		"kedian" : "/d/ourhome/kedian",
	]));
	set("objects", ([
		__DIR__"npc/28star": 1,
                __DIR__"npc/firefly" : 1,
        ]));

	setup();
}

int valid_leave(object me, string dir)
{
	object mbox;

	if( mbox = me->query_temp("mbox_ob") ) {
		tell_object(me, "�㽫���佻�ظ���ʮ����ư��С�㡣\n");
		destruct(mbox);
	}
	return 1;
}
