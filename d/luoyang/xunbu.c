inherit ROOM;

void create()
{
        set("short", "Ѳ����");
        set("long", @LONG
�����ǹٸ�����ͨ����ĵط������ǳ���ʲô����������ħͷ��ɱ
�˷�����Ҫ������䲼���������������Ĳ�ͷ�ǲſ���չ��׷���ж���
Ѳ������������������һ����ľ���������칫��ƽʱ����ͨ�����ǲ�
��������ġ�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "north" : __DIR__"laofang",
                "south" : __DIR__"wroad3",
        ]));
        set("objects", ([
                "/d/city/npc/xunluobing" : 2,
        ]));

        setup();
        replace_program(ROOM);
}

