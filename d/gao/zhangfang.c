// zhangfang.c

inherit ROOM;

void create()
{
  set ("short", "�ʷ�");
  set ("long", @LONG

����Ǹ߼ҵ��ʷ����������һ�Ź��ӣ��߼��кü���Ķ�����
�����������ũ�ң��ܼ�ÿ�»�ȥ����һ�Σ����������ȫ������
����������Ӿ������أ�ľ���ѱ��������
LONG);
set("exits", ([ /* sizeof() == 4 */
"east" : __DIR__"zhyuan",
]));
set("objects", ([
                __DIR__"npc/guanjia": 1,
		__DIR__"npc/huoji": 1 ]) );

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


