// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "���޴���");
  set ("long", @LONG

��������������£����������ľ����������޵ظ��������󶼻�
�������ܵ�Ӧ�еĴ��á����ҷ�����������������������ֲ�
֮�������ܻ�����һЩ�̾ߣ����涼��Ѫ��
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"walk2",
  "east" : __DIR__"roomout",
  "west" : __DIR__"walk3",
  "north" : __DIR__"zhengtang",
]));
  set("hell", 1);
  set("out_doors", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/qinggui" : 2,
  __DIR__"npc/liaogui" : 2,
]));

  setup();
}

int valid_leave(object me, string dir)
{       if (dir == "north") {
	if((string)me->query("family/family_name")!="���޵ظ�") {

        if (objectp(present("qingmian gui", environment(me)))
		|| objectp(present("liaoya gui", environment(me)))) {
return notify_fail("��������и��˱�ס���㣬�㶯Ҳ�����ˣ�\n");
                }
        return ::valid_leave(me, dir);
        }
        return ::valid_leave(me, dir);
        }

        return 1;
}

