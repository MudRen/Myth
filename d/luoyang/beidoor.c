inherit ROOM;

void create()
{
        set("short", "�ڳǱ���");
        set("long", @LONG
�����ڳǱ��Ÿ����ɣ���Լ�������࣬�����ĳ�����������ȭͷ��
��С���������Ŷ���Լ���ɣ���Լÿ������ʱ���ͻ��ٱ����ء���������
������׽��֮��Ĺٸ�ͨ����һ����ֱ����ʯ�������ϱ��������죬��
ȥ���������ڳ��ˣ���һ�Ÿ߸߿�������ǻ��Ǻӡ�
LONG);
        set("outdoors", "luoyang");
        set("exits", ([
                "north" : __DIR__"nbridge",
                "south" : __DIR__"nroad4",
        ]));
        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 3,
        ]));

        setup();
        replace_program(ROOM);
}

