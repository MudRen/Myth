// gate.c

inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG

���̵�����������ͷ�����������������ã������ڷ�Բ��ʮ��
��û��˵�������������Ҳ�ر�ĺã����ﵽ��������������ѧ
ͽ����������ͷ����ũ�ߣ�
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"road2",
]));

set("objects", ([
                __DIR__"npc/laoli": 1,
		__DIR__"npc/xuetu": 2]) );
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


