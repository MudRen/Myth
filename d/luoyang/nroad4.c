inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
������·�������������һ����·���ֵ������ɾ�������������·
�汻��ˮ��ù����羵����·������߷��ߴ����ΰ���������Ǿ޸�լԺ��
˫�˺ϱ�������ʮ��һ�꣬������������ߡ�������һ��Ƥ���꣬������
һ����ʯС���ֱͨ��һ���½���н�� ��
LONG);
        set("outdoors", "luoyang");
        set("exits", ([
                "east" : __DIR__"xiaoxiang",
                "north" : __DIR__"beidoor",
                "south" : __DIR__"nroad3",
                "west" : __DIR__"pimao",
        ]));
        set("objects", ([
                "/d/luoyang/npc/xianren" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

