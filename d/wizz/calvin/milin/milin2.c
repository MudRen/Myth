//Cracked by Roath
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
                "east" : "/d/calvin/milin/milin1",
                "west" : "/d/calvin/milin/milin3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
             "/u/cigar/npc/������ʿ.c" : 2
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
