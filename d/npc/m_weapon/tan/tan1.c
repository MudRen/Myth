//tan1.c

inherit ROOM;

void create()
{
        set("short", "�������� ");
        set("long",
             "�����ǿ�������ˮ�� �����ܵ����Ƚ���������������ͷ����̶ˮ��Ͷ��������\n"
             "�Ե�ʮ���������������һƬҲ��֪��Щʲô���㲻�ɶ��Լ�˵......\n"

        );
        set("exits", ([
                "up" : "/d/kaifeng/xihu1",
                "down" : __DIR__"tan2",
        ]));
        setup();
        replace_program(ROOM);
}

