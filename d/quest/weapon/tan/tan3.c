//tan3.c

inherit ROOM;

void create()
{
        set("short", "�������� ");
        set("long",
                "�����ǿ��������ף����ܺں����ģ�ͷ����ֻ�ܿ���һ�����⣬��ߵ�ˮ��\n"
                "�ƺ������ļ��ˡ������ƺ���һ�����⣬Ҳ��֪��Щʲô����ΧһƬ���ţ�\n"
                "�ƺ������Ų��ɱ����\n"

        );
        set("exits", ([
                "up" : __DIR__"tan2",
                "east" : __DIR__"tan4", 
                "west" : __DIR__"tan6", 
                "south" : __DIR__"tan6",
                "north" : __DIR__"tan6",
        ]));
        setup();
        replace_program(ROOM);
}

