//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "�޺���");
  set ("long", @LONG


			��


LONG);

          set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/luohan5" : 1,
]));

  set("exits", ([ /* sizeof() == 4 */
  "southup" : __DIR__"luohane6",
  "eastdown":__DIR__"luohane4",
]));
  setup();
}
int valid_leave(object me, string dir)
{

        if( (string)me->query("family/family_name")=="�Ϻ�����ɽ" ) return 1;
        if( wizardp(me)) return 1;


        if (dir == "southup") {
        if (objectp(present("luo han", environment(me))))

        return notify_fail("�޺����ֵ�ס�����ȥ·��\n");
        }   
        return ::valid_leave(me, dir);
}


