//dongmenting.c
//created 4-8-97 pickle
#include <room.h>
inherit ROOM;
 
void create()
{
        set("short", "�����");
        set("long", @LONG

�������ڲ��󣬰���Ҳ��ƽ�����м�ة�䲾����������������
�����콫��������ƥ������ľ��һ�ȣ��ź���������������
������ʿ���ش߰죬�������㲻Ϣ���������֡�
LONG
        );
 
        set("exits", ([
                "south" : __DIR__"dongmenting",
        ]));
 	set("no_fight",1);
	set("no_magic",1);
 
        set("objects", ([
                __DIR__"npc/jiancheng" : 1,
		__DIR__"npc/dianbu": 1,
        ]));
 
        setup();
}
