//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "�޺���");
  set ("long", @LONG


			��


LONG);

          set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/luohan16" : 1,
]));

  set("exits", ([ /* sizeof() == 4 */
  "westup" : __DIR__"luohanw3",
  "northdown" : __DIR__"luohanw1",
]));
  setup();
}
int valid_leave(object me, string dir)
{
        object pai;

        if( (string)me->query("family/family_name")=="�Ϻ�����ɽ" ) return 1;
        if( wizardp(me)) return 1;


        if (dir == "westup") {
        if (objectp(present("luo han", environment(me))) )

        return notify_fail("�޺����ֵ�ס�����ȥ·��\n");
        }   
        return ::valid_leave(me, dir);
}


