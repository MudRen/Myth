//m_weapon .....tianjianshi.c
//xuanbing.c

inherit ROOM;

void create()
{
        set("short", "�����Ŷ�");
        set("long",
             "�����������Ŷ����ڣ����洫������Ĵ��������ƺ��ڶ�����ʲô������\n"
             "��͸��һ����ɱ����Ϣ��\n"

        );
        set("exits", ([
                "north" : __DIR__"m_room1",
                "enter" : __DIR__"xuanbing1",
        ]));
        setup();
        replace_program(ROOM);
}

