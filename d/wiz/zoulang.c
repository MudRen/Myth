// Room: /u/rainy/sea/huilang1.c
#include <ansi.h>
inherit ROOM;

int valid_leave();
void create ()
{
      set ("short", HIY "����" NOR);
  set ("long", @LONG

һ���������ȣ���������С�����ʰ�ĸɸɾ����ģ�
����˵��������ի�ˡ�

LONG);

  set("exits", ([ /* sizeof() == 2 */
    "down" : "/d/city/bookstore.c",
    "enter" : __DIR__"bookroom",
]));
          set("objects", 
          ([ //sizeof() == 1
                      __DIR__"npc/huoji" : 1,
          ]));
//      
//          set("water", 1);
//  
  setup();
}
int valid_leave(object me, string dir)
{       
int parry_skill,force_skill,player_combat;
        object a;
//          if( wizardp(me)) return 1;
me=this_player();
parry_skill=me->query_skill("parry");
force_skill=me->query_skill("force");
player_combat=me->query("combat_exp");
            if (dir == "enter" &&
parry_skill < 90 &&
force_skill < 90 &&
player_combat < 100000 )
{
                if(objectp(a=present("huoji", environment(me))) && living(a) )
                return notify_fail("С���һ����ס�㣬ƾ�����书�������ǵ����黹����Щ�أ�\n");
        return ::valid_leave(me, dir);
}
return 1;
}
