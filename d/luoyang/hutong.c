inherit ROOM;

void create()
{
        set("short", "��ͬ��");
        set("long", @LONG
�����߾������������ϰ��յľ�ס����ֻ����ͬ����������ЩС���棬
�����С�С�ӻ��̵ȡ�һЩ������������������
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"eroad5",
                "north" : __DIR__"hutong2",
        ]));

        setup();
        replace_program(ROOM);
}

