//tianpei ����
//by calvin and leox ��ͬ����
//��Ȩ����,δ����ɲ��÷�¼

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ն��");
        set ("long", @LONG
����һ�����Ǻܴ��ɽ��,���������ƺ����ǿ���,�������Ŷ�...
����ǰ�Ϸ��м���ʯ�̵Ĵ���:

                 *********************
                 ****��***ն***��*****
                 *********************
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
           "enter" :"/d/tianpeng/sandong1",
           "southeast" :"/d/tianpeng/hualu3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
