//tianpei ����
//by calvin and leox ��ͬ����
//��Ȩ����,δ����ɲ��÷�¼

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ۡ��԰");
        set ("long", @LONG
����������Ԫ˧���ĵ�һ��С��԰,�����ļ�����,�������滨���
����װ����쳣����.ƽʱ�����Ԫ˧����ϲ����������������,������
����Ҳϲ����������������������羰.
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
           "east" :"/d/tianpeng/xiaolu1",
           "west" :"/d/tianpeng/hualu",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
