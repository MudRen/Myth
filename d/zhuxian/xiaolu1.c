inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
������һ����С·�ϣ�ǰ������ԼԼ���Կ�����ɱ�ĳ��档
LONG);
        set("exits", ([
                "north" : __DIR__"entrance",
                "southeast" : __DIR__"xiaolu2",
        ]));
        setup();
}
