//m_weapon .....tianjianshi.c

inherit ROOM;

void create()
{
        set("short", "ɳĮ����");
        set("long",
             "������ɳĮ�в����һ�����ޣ����ϲ�Զ��Լ���Կ���һ���ںڵ�ɽ������紫��һЩ\n"
             "���������Ĵ�����������Ҳ��֪��˭�ڴ���ʲô��\n"

        );
        set("exits", ([
                "northup" : "/d/westway/fenghuo",
                "south" : __DIR__"xuanbing",
        ]));
        setup();
        replace_program(ROOM);
}

