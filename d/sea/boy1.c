// boy1.c

inherit ROOM;

void create()
{
  set ("short", "�����");
  set ("long", @LONG

��������̫��ס�Ĺ���������򵥣�����һ�����Ρ�̫��ƽ
ʱҲ����������ϵ����齫�����յ�һƬͨ����
LONG);
set("exits", ([ /* sizeof() == 4 */
"southwest" : __DIR__"inside1",
"northeast" : __DIR__"boy2",
]));
set("objects", ([
                __DIR__"npc/haima": 1]) );
        set("no_clean_up", 0);
//
	set("water", 1);
//
        setup();
}

