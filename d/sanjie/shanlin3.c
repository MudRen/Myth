// sanjie shanlin3.c

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
                "east" : __FILE__,
                "west" : __DIR__"shanlin2",
                "south" : __FILE__,
                "north" : __FILE__,
                "southeast" : __DIR__"shanlin4",
                "northeast" : __FILE__,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
