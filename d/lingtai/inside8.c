// Room: some place in ��ţ����
// inside8.c

inherit ROOM;

void create()
{
        set ("short", "������");
        set ("long", @LONG

���о����ĵģ���λ�������ڴ�������������һ��Сͭ��¯����
���յ����Ϻ����㣬�����������̡��ϱ������䳡��
LONG);
        set("exits", ([ /* sizeof() == 4 */
                "south": __DIR__"inside2",
        ]));
        set("objects", ([
                __DIR__"npc/laodao": 1,

        ]) );
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

