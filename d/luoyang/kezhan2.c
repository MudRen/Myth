
inherit ROOM;

void create()
{
        set("short", "��ջ��¥");
        set("long", @LONG
�����Ƕ�¥����������¥�¾�Ҫ���Ŷ��ˣ�������Ĳ;ߣ���ľ����
�Σ��ڹ���֮�·���������ĵĹ����ƴ���ȥ�����������ľ����۵ס�
һȺ�ƿ��Ʊ���յ�����ȵ����֡������ǿͷ�������˯����Ϣ֮�á�
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 5 */
  "east" : __DIR__"kefang1",
  "down" : __DIR__"kezhan",
  "south" : __DIR__"kefang2",
  "west" : __DIR__"kefang3",
  "north" : __DIR__"kefang4",
]));

        setup();
        replace_program(ROOM);
}

