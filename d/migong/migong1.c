#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
   ����һ����᫵�ɽ·�����ܶ���ï�ܵĹ�ľ�ԣ�ʱ��ʱ����
һ��Ұ�޵ĺ������
LONG );
        set("exits", ([
// 13                  "east" : __DIR__"migong2",
                "southdown" :"d/milin/qy/7",                                        
                                                ]));
                set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

