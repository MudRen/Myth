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
                "east" : "/d/calvin/milin/milin2",
                "west" : "/d/calvin/milin/milin4",
                "north" : "/d/calvin/milin/shuiguodian",
       "south" : "/d/calvin/milin/piyin",    
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
