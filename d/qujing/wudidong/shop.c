//shop.c
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "�ż��ϵ�");
	set("long", @LONG

��С�������Ǹ��ö����þ����������հѵ�������Ƕ��ӹ���ûһ��
�£����������ʮ�ϰٻ��ˣ�������Լ����Ҳ����������������
С��Ҳ�ò���ʲô�ö��������޷���Щ�ҳ��Ʋ�֮�ࡣǽ���п�����
(sign)���ƺ����ﻹ���Թ�ҹ��

LONG
        );
	set("no_clean_up", 1);
	set("resource/water", 1);
	set("exits",([
		"north"  : __DIR__"road2",
		"south" : __DIR__"kefang",
        ]));
	set("objects", ([
                __DIR__"npc/waiter" : 1,
        ]));
	set("item_desc", (["sign":"
\t����ͷ���һҹ����������С�˵�С�������Ų���Ƿ��

\t�֣�����ṩ��ˮ��\n
"]));
        set("valid_startroom", 1);
        setup();
}
int valid_leave(object me, string dir)
{
        if ( !me->query_temp("rent_paid") && dir == "south" )
                return notify_fail("û����Ǯ����ס�ꣿ\n");
        return ::valid_leave(me, dir); 
}
