//ROOM lianjianshi.c
inherit ROOM;

void create()
{
        set("short", "�泡");
        set("long",
                "�����������Ŷ������ĵط������ܵ�Ҳ����ʮ�ֻ������෴����˵��\n"
                "���־��¡�¶�����һ���޴��¯�ӣ�ð����������ף��ƺ�ʲô���ܱ���\n"
                "�ڻ��Ƶġ�\n"  
        );
        set("exits", ([
                "out" : "/d/sea/under4",
        ]));

        set("objects",([__DIR__"npc/shicha" :1,]));

        setup();
        replace_program(ROOM);
}

