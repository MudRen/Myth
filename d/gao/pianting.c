// pianting.c

inherit ROOM;

void create()
{
  set ("short", "ƫ��");
  set ("long", @LONG

�������Ż𿻣��������Ƥ���ӣ���������ů����ģ�����̫̫
�����������ڿ��ϣ���ͷ���ž��ʣ��Ա�һ��Ѿ���ź��ţ�
LONG);
set("exits", ([ /* sizeof() == 4 */
"east" : __DIR__"zhting",
]));
set("objects", ([
                __DIR__"npc/gaopo": 1,
                __DIR__"npc/yahuan1": 1,
]) );

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


