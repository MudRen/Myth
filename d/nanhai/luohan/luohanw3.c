//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "�޺���");
  set ("long", @LONG


			��


LONG);

          set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/luohan15" : 1,
]));

  set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"luohanw4",
  "eastdown" : __DIR__"luohanw2",
]));
  setup();
}
int valid_leave(object me, string dir)
{
        if( (string)me->query("family/family_name")=="�Ϻ�����ɽ" ) return 1;
        if( wizardp(me)) return 1;


        if (dir == "northup") {
        if (objectp(present("luo han", environment(me))))

        return notify_fail("�޺����ֵ�ס�����ȥ·��\n");
        }   
        return ::valid_leave(me, dir);
}


