//tianpei ����
//by calvin and leox ��ͬ����
//��Ȩ����,δ����ɲ��÷�¼

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set ("long", @LONG
��������Ԫ˧�������Ż�ʳ��,��һ���žͱ��������ζѬ���ˡ� 
LONG);

        set("exits", 
        ([ //sizeof() == 4
           "east" :"/d/leox/tianpeng/zoulang3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
