// Room: some place in ��ţ����
// inside6.c

inherit ROOM;

void create()
{
        set ("short", "�᷿");
        set ("long", @LONG

������һ�䲼�õ��൱���µ��᷿���Ӵ��ӿ��Կ���Ժ�еĺ��ġ�
����ǽ�Ϲ���̫�����ԡ����һ��ľ齣�һ����ʿ���ڴ���������
LONG);
        set("exits", ([ /* sizeof() == 4 */
                "north": __DIR__"houyuan",
        ]));
        set("objects", ([
                __DIR__"npc/yunqing": 1,
                __DIR__"npc/shixong": 1 ]) );
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

