// sanjie shanlin2.c

inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
        
����һƬï�ܵ����֣����Ĵ����м���¥�ߣ�����Ҷ��ï�ܣ�
���ⶼ���ڱ��ˣ��������氵�����ա��������������أ���
�߹����������ߣ�����һ�㶼�����ˡ�
LONG );
        set("exits", ([
                "east" : __DIR__"shanlin3",
                "west" : __DIR__"shanlin1",
                "south" : __FILE__,
                "north" : __FILE__,
                "southeast" : __FILE__,
                "northeast" : __FILE__,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
