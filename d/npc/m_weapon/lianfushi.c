//ROOM lianjianshi.c
inherit ROOM;

void create()
{
        set("short", "������");
        set("long",
                "�����������Ŷ��츫�ĵط�����Χ����Ķѷ����츫�õ�ԭ�ϣ�һ������\n"
                "С����������һ��ұ��ָ�ϣ�������ϸ���ж��š����������˹�������æ����\n"
                "���е��飬����һ��������㺩����һЦ���������ֺ��ˡ�\n"
        );
        set("exits", ([
                "up" : "/d/jjf/front_yard",
        ]));

        set("objects",([__DIR__"npc/shifu" : 1,]));

        setup();
        replace_program(ROOM);
}

