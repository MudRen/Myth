//room

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","ɽ·");
        set ("long", @LONG

һ���������۵�С·������ֻͨ��ɽ�ϣ�������·���ͣ���̫��
�ߡ������ǵ��Ұ��������С�ݡ�
LONG);

    set("item_desc", ([ /* sizeof() == 1 */
  "northup" : "������Լ����ɽ�ߡ�\n",
]));

        set("exits", 
        ([ //sizeof() == 2
                "northup" : __DIR__"shanlu7",
                "westdown" : __DIR__"shanlu5",
        ]));

        set("objects", 
        ([ //sizeof() == 2
               __DIR__"npc/guard" : 2,
        ]));


        set("outdoors", "huashan");
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
   if (dir == "northup" ) {
        if (objectp(present("shan shen", environment(me))))
   return notify_fail(HIW"ɽ��"NOR+"������˵���������˽��أ�������ذɣ���\n");

        }   
        return ::valid_leave(me, dir);
}

