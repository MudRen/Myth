// Room: some place in ��ţ����
// baixi.c

inherit ROOM;

void create()
{
        set ("short", "��ʯϪ");
        set ("long", @LONG

������ˮ��ɽ����ȥ��Ϫˮ�峹���ס�ˮ�ײ����˴�С��һ����
������Ķ���ʯ��Ϫ�е�С��������ȥ��Ϫ�ߵĲݴ��в�ʱ����
������
LONG);
        set("exits", ([ /* sizeof() == 4 */
                "northwest" : __DIR__"baixi2",
                "southeast": __DIR__"uphill3",
        ]));

        set("no_clean_up", 0);
        set("outdoors", 1);
        setup();
        replace_program(ROOM);
}

