inherit ROOM;

void create()
{
        set("short", "�η�");
        set("long", @LONG
�������η������涼��������Χס��������һ��С�������ţ������
����һ�ȴ�������͸����΢���Ĺ��ߴӴ������˽����������η�����һ��
��������������һЩ���񼫵ķ��ˡ�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"xunbu",
        ]));

        setup();
        replace_program(ROOM);
}

