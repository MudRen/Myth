inherit ROOM;

void create()
{
        set("short", "�ϳǸ�");
        set("long", @LONG
�����������ڳ���ǽ�š��������壬����û���˻�����������ǰ
���˸ߴ�ĳ�ǽ�����صĳ������Ӳݾ�ʲôҲû���ˡ�
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "west" : __DIR__"suishi4",
                "northeast" : __DIR__"dongtou",
        ]));

        setup();
        replace_program(ROOM);
}

