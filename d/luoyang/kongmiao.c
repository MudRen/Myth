inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǿ���������п׷����������ʵ۶������������˼������
���Լ��Ľ�ɽ��𢣬�����ʵ���ȻҲ�����⡣���ۺ��˵��ˣ����Ϲ��Ͼ�
��������ݡ�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"wroad2",
        ]));
        set("objects", ([
                "/d/luoyang/npc/shusheng1" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

