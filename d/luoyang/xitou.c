inherit ROOM;

void create()
{
        set("short", "���Ǹ�");
        set("long", @LONG
�����������ڳ���ǽ�š��������壬����û���˻�����������ǰ
���˸ߴ�ĳ�ǽ�����صĳ������Ӳݾ�ʲôҲû���ˡ����ǣ���Ȼ���۾�
һ������������Ӱ�������ǰһ�������������Ƿ�����ʲô�����أ�
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "southeast" : __DIR__"nantou2",
                "north" : __DIR__"suishi10",
        ]));
        set("objects", ([
                "/d/city/npc/liumang" : 1,

        ]));
        setup();
        replace_program(ROOM);
}

