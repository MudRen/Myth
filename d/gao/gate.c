// gate.c

inherit ROOM;

void create()
{
  set ("short", "�߼Ҵ���");
  set ("long", @LONG

������Ǹ߼ҵĴ��ſڣ�����һ�Ժ�ľ���Ĵ��Ű뿪�ţ���������һ
�����������Ұ���һ��������צ��ʯʨ��������Դ����������Ʒ��
���ŵ�����ͷ�������˯�����˽��߼ҽ����л��£�����Ժ�Ӿ���
�ĵģ�
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"zhyuan",
"east" : __DIR__"lu2",
"west" :__DIR__"road1",
]));

set("objects", ([
                __DIR__"npc/laoyu": 1 ]) );
        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


