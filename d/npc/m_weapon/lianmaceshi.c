//ROOM lianjianshi.c
inherit ROOM;

void create()
{
        set("short", "��ﵳ�");
        set("long",
                "�����������Ŷ�����ﵳ������ܻ���û�����̣�������Լ���ܿ����߰�\n"
                "��Ѫ����ż���ܿ����ļ������ƺ�Ҳ����ﵵı�����һ�����������ŵġ�¶\n"
                "�����һ���޴��¯�ӣ�ð����������ף����ҵ���������һ����ѣ��ԭ\n"
                "�������������ڼ���������������\n"      
        );
        set("exits", ([
                "down" : "/d/jjf/front_yard",
        ]));

        set("objects",([__DIR__"npc/shimace" :1,]));

        setup();
        replace_program(ROOM);
}

