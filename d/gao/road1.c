// gate.c

inherit ROOM;

void create()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

һ��ʯ��С·�����¹��꣬·�Ͽ����������ɾ��ģ�һЩ������
�����Լ��ֵ��߲˵����������˲��Ǻܶ࣬ߺ����������Զ����
������ص���
LONG);
set("exits", ([ /* sizeof() == 4 */
//"north" : __DIR__"zhyuan",
"south" : __DIR__"inn",
"east" : __DIR__"gate",
"west" :__DIR__"road2",
]));
set("objects", ([
                __DIR__"npc/xiaofan": 1]));
        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


