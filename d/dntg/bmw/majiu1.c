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
                "north" : __DIR__"majiu2",
                "south" : __DIR__"zhengting",
        ]));
 
        set("objects", ([
               __DIR__"npc/horsebaby": 1,
        ]));
 


        setup();
}
