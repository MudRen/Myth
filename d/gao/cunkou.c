// shanlu.c

inherit ROOM;

void create()
{
  set ("short", "���");
  set ("long", @LONG

���˴�ڣ��������ȥ��ϡϡ����Ҳ�а�ʮ�����߷��������˶�
ææµµ�ģ��˲��ϴ����㣬ֻ�м���Сͯ�ڴ��Եĳ���������
���ǵ����š�
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"tulu",
"east" : __DIR__"house",
"southwest" : __DIR__"xuetang",
]));
set("objects", ([
            "/d/gao/npc/cunzhang": 1,
]));


        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


