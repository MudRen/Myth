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
"/obj/boss/lanling_yaodian" : 1,
        ]));

//      set("outdoors", "changan");
        set("no_clean_up", 0);
      set("no_fight",1);           
         set("no_magic",1); 
        setup();
        replace_program(ROOM);
}
