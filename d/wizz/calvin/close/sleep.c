//tianpei ����
//by calvin and leox ��ͬ����
//��Ȩ����,δ����ɲ��÷�¼

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set ("long", @LONG
����һ��ܴ������,����ɾ�����,���䲼�ֺ���
�ڷ��������Ϣ�������кö������ϥ����,���ó���
���ڲ��Ͻ����Լ���
LONG);
        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4]
        "east" :"/d/tianpeng/mingyue",
]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("sleep_room",1);
        set("if_bed",1);                             
//      set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
