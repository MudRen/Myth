//tianpei ����
//by calvin and leox ��ͬ����
//��Ȩ����,δ����ɲ��÷�¼

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set ("long", @LONG
���ﲻ��һ���ܴ��ɽ��,�����ڻ���������,����ľ��������ɾ�һ��.
LONG);

        set("exits", 
        ([ //sizeof() == 4
           "out" :"/d/tianpeng/sandong",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/calvin/tianpeng/zhu" :  1,
        ]));

//      set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
