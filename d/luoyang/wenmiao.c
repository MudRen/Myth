inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����������������п׷����������ʵ۶������������˼������
���Լ��Ľ�ɽ��𢣬�����ʵ���ȻҲ�����⡣���ۺ��˵��ˣ����Ϲ��Ͼ�
��������ݡ�
LONG );
        set("exits", ([
                "west" : __DIR__"nroad3",
        ]));

        set("objects", ([
                "/d/luoyang/npc/shusheng1" : 1,
        ]));

        setup();
        replace_program(ROOM);
}

