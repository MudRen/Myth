//ROOM lianjianshi.c
inherit ROOM;

void create()
{
        set("short", "��ǹ��");
        set("long",
                "�����������Ŷ�����ǹ�ĵط������ܵ�Ҳ����ʮ�ֻ������෴����˵��\n"
                "���־��¡�¶�����һ���޴��¯�ӣ�ð����������ף��ƺ�ʲô���ܱ���\n"
                "�ڻ��Ƶġ�\n"  
        );
        set("exits", ([
                "east" : "/d/qujing/kusong/kusongjian",
        ]));

        set("objects",([__DIR__"npc/shiqiang" :1,]));

        setup();
        replace_program(ROOM);
}

