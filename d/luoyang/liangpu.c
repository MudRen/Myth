inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��������������Ǹ���Ψһ��һ�����̣�������µ����ֵ���һ�߱�
�ǹٸ����ɴ˿ɼ��ٸ��������ϡ����ؾ����������涼Ҫ������������
��������¡����Դ������
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"nroad2",
        ]));
        set("objects", ([
                __DIR__"npc/liangcao" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

