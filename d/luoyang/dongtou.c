inherit ROOM;

void create()
{
        set("short", "���Ǹ�");
        set("long", @LONG
�����������ڳǶ�ǽ�š��������壬����û���˻�����������ǰ
���˸ߴ�ĳ�ǽ�����صĳ������Ӳݾ�ʲôҲû���ˡ����ǣ�ͻȻ�㿴��
�������ź���ӵ�����������ǽ�Ŵ���ͷ�Ӷ�������˽����ǵ����ڸ�
ʲô��
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "southwest" : __DIR__"nantou",
                "north" : __DIR__"suishi3",
        ]));
        set("objects", ([
                "/d/city/npc/liumang" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

