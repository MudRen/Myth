//tianpei ����
//by calvin and leox ��ͬ����
//��Ȩ����,δ����ɲ��÷�¼

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ɳ�ӵ�");
        set ("long", @LONG
����"�����޺�ɳ��"������֮��,Ҳ��ͨ����ɳ�ӵ�һ���Ե���
LONG);

        set("exits", 
        ([ //sizeof() == 4
           "up" :"/d/tianpeng/mi6",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("no_clean_up", 0);
        set("water", 1);
        setup();
}
