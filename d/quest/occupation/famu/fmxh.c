//Created by kuku@sjsh 2003.2

inherit ROOM;

void create ()
{
        set ("short", "��ľ��Э��");
        set ("long", @LONG

��ľ��Э��������һƬ������ӳ�������У����ﻷ�����ţ�
�����﹤�����Ǽ��������顣
LONG);

        set("exits", ([ /* sizeof() == 2 */             
                "east" : __DIR__"shulin2",
                "south": __DIR__"songlin",
        ]));
        set("objects", ([  
                __DIR__"npc/guanshi" : 1,
        ])); 
        setup();
}
