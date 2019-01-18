#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", "���ԡ��");
        set("long", @LONG
���Ϲ���һ����ң������ĸ�������֡����ԡ�ء���������������
������ɫ�ĵط�������Ů���䣬���㿪�й��Ŵ�ԡ��֮�Ⱥӣ�һЩ��Ǯ��
��ү��үС��̫̫���������������൱�������ſ����Ÿ���ͷ����
��������Ǯ�ġ�¥����Ů�䣬¥�����м䣬��ǧ����ߴ�Ӵ��
LONG);
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"rest1",
                "up" : __DIR__"rest2",
                "west" : __DIR__"sroad3",
        ]));
        set("objects", ([
                __DIR__"npc/zaotang" : 1,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        if (me->query("gender") == "Ů��" && dir == "east") 
                return notify_fail(CYN "���û��һ����ס�㣬˵���������Ů��"
                                   "���뵽����ȥ��\n" NOR);

        if (me->query("gender") != "Ů��" && dir == "up") 
                return notify_fail(CYN "���û��һ����ס�㣬˵����ι����һ����"
                                   "��ү�Ƕ���ô��Ůԡ���갡��\n" NOR);

        return ::valid_leave(me, dir);
}

