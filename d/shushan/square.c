
inherit ROOM;

void create()
{
        set("short", "�㳡");
        set("long", @LONG
��ɽ�Ĺ㳡���������ᣬֻ��һ������ͯ
������������ʯ�̾͵ĵ��棬�����пӿ�����
�ĺۼ�������Ǽ������������������ĺۼ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dadian",
  "east" : __DIR__"jinglou",
  "south" : __DIR__"paifang",
]));

        set("objects",([
        __DIR__"npc/jiantong" : 2,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
