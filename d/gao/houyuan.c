// houyuan.c

inherit ROOM;

void create()
{
  set ("short", "��Ժ");
  set ("long", @LONG

��Ժ֮�м�Ϊ��������ʱ���Ǹ߼���ɹ���ȵĵط������߿�ǽ��
һ���������Ա߷��˼�ֻľͰ������һ��С¥����С��ס�ĵط���
�����Ǹ߼ҵĺ�԰��
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"huayuan",
"south" : __DIR__"zhting",
"east" : __DIR__"washing",
"west" :__DIR__"guige",
]));
	set("outdoors", 1);
        set("no_clean_up", 0);
	set("resource/water", 1);
        setup();
        replace_program(ROOM);
}


