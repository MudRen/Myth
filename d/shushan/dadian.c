//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "���");
        set("long", @LONG
        ��������ɽ���ɵĴ��ǻ�͵ĵص㡣����Ԫʼ����̫�ϵ�
���������Ͼ��������㰸���������ơ���ǽ���ż���̫ʦ�Σ����Ϸ���
�������š�������������Ϣ�ң��ϱ�������Ĺ㳡�������Ǻ�
LONG);

        set("valid_startroom", 1);
        set("exits", ([
                "south" : __DIR__"square",
                "north" : __DIR__"houdian",
                "northeast" : __DIR__"zhmroom",
        ]));

        set("objects", ([
                __DIR__"npc/jiansheng" : 1,
        ]));

        setup();
//      replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if (me->query("family/master_id") == "master swordsman")        
        return ::valid_leave(me, dir);
   if (dir == "northeast" ) {
        if (objectp(present("master swordsman", environment(me))))
   return notify_fail("һ�����ص�������ֹ���㣬Ҳ���ǽ�ʥ��������\n");
        }   
        return ::valid_leave(me, dir);
}
