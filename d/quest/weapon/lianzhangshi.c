//ROOM lianjianshi.c
inherit ROOM;

void create()
{
        set("short", "�ȳ�");
        set("long",
                "�����������Ŷ������ȵĵط������ܵ�Ҳ����ʮ�ֻ������෴����˵��\n"
                "���־��¡�¶�����һ���޴��¯�ӣ�ð����������ף��ƺ�ʲô���ܱ���\n"
                "�ڻ��Ƶġ�\n"  
        );
        set("exits", ([
                "west" : "/d/nanhai/tingjing",
        ]));

        set("objects",([__DIR__"npc/shizhang" :1,]));

        setup();
        replace_program(ROOM);
}

