// Room: some place in ��ţ����
// inside2.c

inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG

һ��СС��������������һ�������ʿ�ڽ�һЩС�����书����
Χ�������Ϸ���һЩ������
LONG);
set("exits", ([ /* sizeof() == 4 */
"west": __DIR__"gate1",
"east": __DIR__"inside7",
"north": __DIR__"inside8",
"south": __DIR__"sleep",
]));
set("objects", ([
                __DIR__"npc/xiao": 3, 
  "/obj/zhangmen/lingtai": 1,
		__DIR__"obj/rack": 1,
]) );
        set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "south" ) {
        if (objectp(present("zhang men", environment(me)))) {
        if((string)me->query("family/family_name")=="����ɽ���Ƕ�") {
        return ::valid_leave(me, dir);
        }
        return notify_fail("���Ŵ�����µ����ǲ������ȥ�ĵط���\n");
        }
        }
        return ::valid_leave(me, dir);
}


