inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
�������ǵ�һ������ʯ������С��ǳ�Ƨ�������¹��꣬·�濴��
�������ɾ��ġ�
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"suishi4",
                "north" : __DIR__"xiaoxiang4",
        ]));

        setup();
        replace_program(ROOM);
}

