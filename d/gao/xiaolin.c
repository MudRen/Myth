// xiaolin.c

inherit ROOM;

void create()
{
  set ("short", "С����");
  set ("long", @LONG

С������ľ�������飬������һ����Ӱ��ȴż������������˵
��ʲô������ǰ���ţ�ȴ�е��������˰��ж����㡣�����һ
����������������
LONG);
set("exits", ([ /* sizeof() == 4 */
"south" : __DIR__"xiaolu",
"north" : __DIR__"xiaolin1",
]));

        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


