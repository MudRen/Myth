inherit ROOM;

void create()
{
        set("short", "���׵�");
        set("long", @LONG
��ҿ��׵�ͽֶ���������궼��ͬһ���ϰ忪�ģ�֮���԰����Ƿ�
����ֻ��Ϊ�˷���˿͹����Լ���Ҫ�Ķ����������ı��Ϲ����˸�ʽ����
�Ŀ��ף����Ƶģ����Ƶģ�ͭ�Ƶģ����Ƶģ�Ƥ�Ƶģ�Ʒ����ȫ��Ӧ�о�
�С�
LONG);
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"eroad1",
        ]));
        set("objects", ([
                "obj/boss/luoyang_zhu" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

