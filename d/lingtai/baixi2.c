// Room: some place in ��ţ����
// baixi2.c

inherit ROOM;

void create()
{
        set ("short", "��ʯϪ");
        set ("long", @LONG

������ˮ��ɽ����ȥ��Ϫˮ�峹���ס�ˮ�ײ����˴�С��һ����
������Ķ���ʯ��Ϫ�е�С��������ȥ�����е����ߴߴ������
���š�
LONG);
        set("exits", ([ /* sizeof() == 4 */
                "southup" : __DIR__"lantao",
                "southeast": __DIR__"baixi",
        ]));

        set("no_clean_up", 0);
        set("outdoors", 1);
        setup();
        replace_program(ROOM);
}

