//����

inherit ROOM;
#include <ansi.h>
void create ()
{
        set ("short","����ҩ��" );
        set ("long", @LONG

����һ�Һܲ������ҩ��,������ϰ��Ǹ�����
��˵���й�ҽ�κ����˵�����,������Ҳֻ�Ǵ�˵
����Ĳ��øɾ�����,ǽ�ϻ��п���ң�������д
��"���ֻش�"�ĸ����� ... ...
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
    "east" : "/d/calvin/lanling/jie7",
        ]));

        set("objects", 
        ([ //sizeof() == 1
         "/d/obj/����/ҩ���ϰ�" : 1,
        ]));

//      set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
