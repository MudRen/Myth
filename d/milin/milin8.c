//shulin ����

inherit ROOM;

void create ()

{
        set ("short", "�����");
        set ("long", @LONG
����һƬ����,һ�ж�����ô��Ʈ��...���...
ֻ��һЩС·,����ż�����õ���Щ�������˴�.
����ǰ���ƺ���һ˿����,���ǿ쵽������.
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "north" : "/d/calvin/milin/milin7",    
       "south" : "/d/calvin/lanling/lanlingbei1",    
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
