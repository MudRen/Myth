//Created by kuku@sjsh 2003.2

inherit ROOM;

void create ()
{
        set ("short", "ľ�ļӹ���");
        set ("long", @LONG

Ҫ������ñ����͵��ҵ����ո�ǿ�Ĺ������������
Զ��������ľ�ļӹ����ӣ�����Ļ�ƿ��԰���ӹ�
��������������������ϡ�
LONG);

        set("exits", ([ /* sizeof() == 2 */             
                "north" : "/d/kaifeng/east2",
        ]));
        set("objects", ([    
                __DIR__"npc/huoji" : 1,
        ])); 
        setup();
}
