inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
������һ����С·�ϣ�ǰ������ԼԼ���Կ�����ɱ�ĳ��档
LONG);
        set("exits", ([
                "northwest" : __DIR__"xiaolu5",
                "southwest" : __DIR__"xiaolu7",
        ]));
        setup();
}
