//Cracked by Roath
//shulin ����

inherit ROOM;

void create ()
{
        set ("short", "����");
        set ("long", @LONG

������ɭ�ֵ��,������Щ�˳�û,һ�ۿ������ߵ�������ɭ�ɾ�
���ڸ����ѵ�����Щ�˳�û,������Щ��������,˭Ҳ��֪�����Ƕ�
����Щʲô����.������Ǻܺ�,�����������һ���ĺ�... ...
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : "/d/shulin/lin8",
                "south" : "/d/changan/eside5",
                "enter" : "/d/calvin/milin/anshi",
                "west" : "/d/calvin/milin/milin1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                      "/d/shulin/npc/shizhe":1, 
                      "/d/obj/flower/hua":2  
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
