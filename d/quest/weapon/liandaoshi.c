//ROOM lianjianshi.c
inherit ROOM;

void create()
{
        set("short", "������");
        set("long",
                "�����������Ŷ������������Ĵ������˽�������ζ�����ȵ����˳����\n"
                "���ɴ��˸�����һ��Ƥ����ڵ�С��������һ��ʯͷ����Ϣ������һ��\n"
                "�޴�Ĵ�ͷ����ͣ�����ذڶ��š�������С���Ҫ˯���ˡ�\n"
        );
        set("exits", ([
                "down" : "/d/qujing/wudidong/dong",
        ]));

        set("objects",([__DIR__"npc/shidao" :1,]));

        setup();
        replace_program(ROOM);
}

