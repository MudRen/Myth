inherit ROOM;

void create()
{
        set("short", "С��ͬ");
        set("long", @LONG
���������������ϰ��յľ�ס������ͬ�ںܰ�����û��ʲô������һ
Щ������������������Խ����ͬ���ߣ�һЩȫ���Ű�ɫ���µ��˾�Խ
���ˣ�ֻ����Щ�˹����������㱣����ٿ��ɣ����˲²�͸�Ǹ�ʲô
�ġ�
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"hutong",
                "north" : __DIR__"hutong3",
                "west" : __DIR__"wanju",
        ]));

        setup();
        replace_program(ROOM);
}

