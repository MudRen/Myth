//shulin ����

inherit ROOM;

void create ()
{
        set ("short", "�����");
        set ("long", @LONG
����һƬ����,һ�ж�����ô��Ʈ��...���...
ֻ��һЩС·,����ż�����õ���Щ�������˴�.
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "east" : "/d/calvin/milin/milin3",
                "west" : "/d/calvin/milin/milin5",
       "south" : "/d/calvin/milin/bailong",    
//   "north" : "/d/calvin/milin/maproom",    
        ]));

        set("objects", 
        ([ //sizeof() == 1
             "/u/cigar/npc/������ʿ.c" : 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
