// gate.c

inherit ROOM;

void create()
{
  set ("short", "��·");
  set ("long", @LONG

��Χ��һƬ���һЩũ��������������ڸ��֣�������ȥ��һ��
ɽ���������ɣ����������������С��Ҳ�Ƿ�Բ��ʮ����Ϊ����
�ĵط������䲻�󣬵���������������ȱ��
LONG);
set("exits", ([ /* sizeof() == 4 */
//"north" : __DIR__"zhyuan",
//"south"
"east" : __DIR__"road2",
"west" : __DIR__"road4",
]));

        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


