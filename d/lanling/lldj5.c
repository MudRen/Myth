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
                "north" : "/u/calvin/����/����/������6",
                "south" : "/u/calvin/����/����/������8",
                "east" : "/u/calvin/����/����/�Ȱ���",
                "west" : "/u/calvin/����/����/ҩ��",

        ]));

        set("objects", 
        ([ //sizeof() == 1
   "/d/qujing/zhuzi/npc/people" : 2,
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
