inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
������һ����С·�ϣ�ǰ������ԼԼ���Կ�����ɱ�ĳ��档
LONG);
        set("exits", ([
                "north" : __DIR__"xiaolu4",
                "southeast" : __DIR__"xiaolu6",
        ]));
        setup();
}
