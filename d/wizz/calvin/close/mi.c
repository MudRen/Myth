//tianpei ����
//by calvin and leox ��ͬ����
//��Ȩ����,δ����ɲ��÷�¼

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����԰");
        set ("long", @LONG
����һ��ʹ�����жݼ׵������Թ���԰,��������Թ����Ǻܴ�,
һ���Ѳ��������ĸ�·���֡�
LONG);

        set("exits", 
        ([ //sizeof() == 4
           "east" :"/d/tianpeng/mi",
           "west" :"/d/tianpeng/mi1",
           "northwest" :"/d/leox/tianpeng/zoulang4",
           "southwest" :"/d/tianpeng/mi",
           "southeast" :"/d/tianpeng/mi",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
