// gate.c

inherit ROOM;

void create()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

�����������ƺ�����Щ��Ҳ��Щ��С�����ģ������ʯ������·
�ϣ������������һ�ˣ�
LONG);
set("exits", ([ /* sizeof() == 4 */
//"north" : __DIR__"zhyuan",
//"south"
"east" : __DIR__"lu1",
"west" :__DIR__"gate",
]));

        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


