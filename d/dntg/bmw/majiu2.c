//sgzl
#include <room.h>
inherit ROOM;
 
void create()
{
        set("short", "���");
        set("long", @LONG

��������ǧƥս��ÿƥ��������ǧ���ˮ��ɽ��
����ƽ��֮��ԡ�һ������˻����磬���㲻Ϣ��
�����ڶ�С��ԣ���δ���ɣ�ȴҲ�����쳣����
����ʿ��ҹ���ߣ�������ƥ��
LONG );
 
        set("exits", ([
                "south" : __DIR__"majiu1",
        ]));
 
        set("objects", ([
        ]));
 


        setup();
}
