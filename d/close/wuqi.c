//tianpei ����
//by calvin and leox ��ͬ����
//��Ȩ����,δ����ɲ��÷�¼

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set ("long", @LONG
����������Ԫ˧��������,����ڷŵı�����������,���ι�״�� 
LONG);

        set("exits", 
        ([ //sizeof() == 4
           "west" :"/d/leox/tianpeng/zoulang3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/leox/npc/jiajiang" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
