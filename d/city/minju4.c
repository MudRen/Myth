//changan city

inherit ROOM;

void create ()
{
        set ("short", "���");
        set ("long", @LONG

�⻧�˼��ڳ�������Ҳ��Ƚϸ�ԣ���ˡ������˳��꾭�����⣬����
�ڼ����ּ�����ͬ�����Ǵ�����˼�һ�������﹩���Ϻ������͹�
��ү������
LONG); 

        //set("item_desc", ([" *** " : " *** ", ])); 

        set("exits", 
        ([ //sizeof() == 4
		"north" : __DIR__"beiyin5",
        ]));

        set("objects", 
        ([ //sizeof() == 1
		__DIR__"npc/woman" : 1,
		__DIR__"npc/boy" : 1,
		"/d/obj/weapon/blade/caidao" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}



