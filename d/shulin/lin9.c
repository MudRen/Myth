//Cracked by Roath
//shulin lin9

inherit ROOM;

void create ()
{
        set ("short", "����");
        set ("long", @LONG

����ɭ�ֵ�����,��˵������п��µ�����,�⵽����һƬ�׹�
����ƫƫ�������䲻��һ˿����,���ص��ǽ����˲�����η
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));
        set("exits", 
        ([ //sizeof() == 4
                "west" : "/d/shulin/lin8",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                "/d/shulin/npc/shuyao":1,
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
