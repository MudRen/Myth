// gate.c

inherit ROOM;

void create()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

��Χ��һЩ���̣����Ϊ�������⣬�Ѷ������ڵ��˽��ϣ���һ
�������Ͳ����ʯ��ռ�˴�룮�������Ҳ�ԵĽ϶࣬�����Щ
�������ģ�������Щ�ճ���Ʒ��
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"budian",
"south": __DIR__"tiepu",
"east" : __DIR__"road1",
"west" :__DIR__"road3",
]));

        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


