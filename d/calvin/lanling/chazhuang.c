// ������ by Calvin

inherit ROOM;

void create ()
{
        set ("short", "·�ڲ�ׯ");
        set ("long", @LONG

����һ����Զ��ԱȽϼ򵥵Ĳ�ׯ,ֻ�м򵥵ļ��ų¾��˵�
���ӵ���,�����ֻ���Ǹ���ƺ��ϰ��ˡ�

LONG);

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"xiaolu2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
"/obj/boss/lanling_lukou" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
