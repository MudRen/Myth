//by calvin and leox ��ͬ����
//��Ȩ����,δ����ɲ��÷�¼

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��԰·");
        set ("long", @LONG
���Ǹ�ۡ��԰������һ��С·,���������ɾ�,�Ǹ��ѵõĺõط�.
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
           "northwest" :"/d/tianpeng/sandong",
           "south" :"/d/tianpeng/hualu",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
