//tianpei ����
//by calvin and leox ��ͬ����
//��Ȩ����,δ����ɲ��÷�¼

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "С·");
        set ("long", @LONG
����һ��ͨ����ۡ��԰��С·,·�����߲�ľ����,��������.
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
           "east" :"/d/tianpeng/xiaolu",
           "west" :"/d/tianpeng/huayuan",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
