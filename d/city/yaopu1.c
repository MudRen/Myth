//changan city

inherit ROOM;
#include <ansi.h>
void create ()
{
        set ("short","ҩ��" );
        set ("long", @LONG

���ǳ�����һ�����ֺŵ�ҩ�̵�ҩ����ҩ���а����˸��ָ�����
ҩ�ģ�����ҩ�̻�ư���Щҩ��ĥ����Ҫ��ҩ�ۣ�ҩ��֮�ࡣ
LONG);

        set("exits", 
        ([ //sizeof() == 1
                "west" : __DIR__"yaopu",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                "/adm/npc/city_yao" : 1,
        ]));
        
        set("no_fight", 1);;
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);


}



