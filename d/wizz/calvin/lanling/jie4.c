//shulin ����

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

���Ƿ羰���˵�����ų�,һƬ���ٵľ�����ֳ�
�����Ȱ������������ֿ����,����ʯ�Ҿ͵Ľֵ�
���߶���һ������������ĸ�ʽ����,�����ǵĻ�
Ц���п��Կ���,�������ҵ���Ƿ��� ... ...


LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "north" : "/d/calvin/lanling/jie3",    
       "south" : "/d/calvin/lanling/jie5",    
       "east": "d/calvin/kezhan",
       "west" : "/d/calvin/lanling/objroom",    
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
