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
                "northwest" : __DIR__"xitou",
                "east" : __DIR__"suishi9",
        ]));
        set("objects", ([
                "/d/luoyang/npc/qigai" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

