// gate.c

inherit ROOM;

void create()
{
  set ("short", "С�ƹ�");
  set ("long", @LONG

���������ôһ��С�ƹݣ�����һ��������˶������ȼ��ѣ��Ƶ�
��Ļ���ɶ��������ӳ��������ģ��Ǹ���ζû��˵�������ϼ���
�����ף�����Ҳ������ˣ�
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"road1",
]));
set("objects", ([
                __DIR__"npc/wang": 1, 
		__DIR__"npc/jiuke": 1]) );

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


