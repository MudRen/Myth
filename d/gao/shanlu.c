// shanlu.c

inherit ROOM;

void create()
{
  set ("short", "ɽ·");
  set ("long", @LONG

�ò������߳���С�֣�������һ��ɽ��С·��Խ������Խ�ܣ�����
��������������Ҳ��ð߰ߵ�㡣é�ݽ��񣬹�ľ�������Ӷ�����
�����������磬����ë����Ȼ��
LONG);
set("exits", ([ /* sizeof() == 4 */
"west" : __DIR__"xiaolin1",
"northup" : __DIR__"room",
]));

        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


