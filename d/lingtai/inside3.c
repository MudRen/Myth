// Room: some place in ��ţ����
// inside3.c

inherit ROOM;

void create()
{
  set ("short", "�᷿");
  set ("long", @LONG

������һ�䲼�õ��൱���µ��᷿���Ӵ��ӿ��Կ���Ժ�еĺ��ģ�
����ǽ�Ϲ���̫�����ԣ����һ��ľ齣�һ����ʿ���ڴ���������
LONG);
set("exits", ([ /* sizeof() == 4 */
"east": __DIR__"gate1",
]));
set("objects", ([
                __DIR__"npc/yunjing": 1 ]) );
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}



