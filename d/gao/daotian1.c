// gate.c

inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG

��������������ڸ����ţ�һƬһƬ��ũ�����������С��С��
�ܲ����У�
LONG);
set("exits", ([ /* sizeof() == 4 */
"south" : __DIR__"road4",
]));
set("objects", ([
                __DIR__"npc/farmer": 1,
		__DIR__"npc/bull": 1 ]) );


        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


