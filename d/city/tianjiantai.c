inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short","���̨");
        set ("long", @LONG

������ǳ����������̨����͢ÿ��ļ�����ʽ����������С�����
�㳡�ϻ��Ű���ͼ�Σ���Χ������һЩʩ��ʱ�õ����ߣ����̨����
����������Ԭ����ܿ������￴��������Ӱ��
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "east" : __DIR__"xuanwu-n1",
        ]));

        set("objects", 
([ //sizeof() == 1
    "/d/quest/yuan/yuantiangang" : 1,
        ]));


        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

