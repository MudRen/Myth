// Room: some place in ��ţ����
// cave1.c

inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG

�ò����״����������˳�������ǰһ������������ǰ��һ��С
ɽ�������ڻ��в���Ѫ����һ��ɽ�紵����������������Ż��
�������������������ѵ���Ұ�ޣ�
LONG);
set("exits", ([ /* sizeof() == 4 */
"east" : __DIR__"forrest",
"west": __DIR__"cave2",
]));
set("objects", ([
                __DIR__"npc/oldwolf.c": 1 ]) );

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if ( dir == "west" && objectp(present("wolf", environment(me)))) 
        return notify_fail("�����͵�������ǰ����ס�㣡\n");

        return ::valid_leave(me, dir);
}

