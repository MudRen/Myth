inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG

һ��СС�ķ��ӡ�����ǽ�Ϲ���һ�����ӵĻ���һ��������
������һȺ������֮����Ҳ������
LONG);

set("exits", ([ /* sizeof() == 4 */
"northeast" : __DIR__"cunkou",
]));

 set("objects", ([ /* sizeof() == 2 */
"/d/gao/npc/teacher" : 1,
"/d/gao/npc/kid" : 2,
]));


        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

