//tianpei ����
//by calvin and leox ��ͬ����
//��Ȩ����,δ����ɲ��÷�¼

#include <ansi.h>
inherit ROOM;

int do_dive();

void create()
{
        set("short", "����԰");
        set ("long", @LONG
����һ��ʹ�����жݼ׵������Թ���԰,��������Թ����Ǻܴ�,
һ���Ѳ��������ĸ�·���֡�
LONG);

        set("exits", 
        ([ //sizeof() == 4
           "east" :"/d/tianpeng/mi6",
           "west" :"/d/tianpeng/mi6",
           "north" :"/d/tianpeng/mi5",
           "south" :"/d/tianpeng/mi6",
           "northeast" :"/d/tianpeng/mi5",
           "down" :"/d/tianpeng/mi7",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
