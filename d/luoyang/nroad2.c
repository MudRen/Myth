inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
������·�������������һ����·���ֵ������ɾ�������������·
�汻��ˮ��ù����羵����·������߷��ߴ����ΰ���������Ǿ޸�լԺ��
˫�˺ϱ�������ʮ��һ�꣬������������ߡ��������������ڣ���������
һ�����̡�
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"yamendoor",
                "north" : __DIR__"nroad3",
                "south" : __DIR__"nroad1",
                "west" : __DIR__"liangpu",
        ]));

        setup();
        replace_program(ROOM);
}

