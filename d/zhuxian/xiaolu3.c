inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
������һ����С·�ϣ�ǰ������ԼԼ���Կ�����ɱ�ĳ��档
LONG);
        set("exits", ([
                "northeast" : __DIR__"xiaolu2",
                "east" : __DIR__"xiaolu4",
        ]));
        setup();
}
