// ���ɵ� by Calvin
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "���ɵ�");
  set ("long", @LONG

�����Ǵ�˵�й������������Եĵط�,�����ļ��紺��

LONG);

  set("exits", ([ /* sizeof() == 2 */
//  "east" : "/d/longzhu/xxx",
]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/quest/longzhu/npc/gui" : 1,
        ]));

        set("sleep_room",1);
        set("if_bed",1);                             

  setup();
}

void init()
{
        add_action("do_swim", "swim");
}

int do_swim()
{
        object  me, horse;
        me = this_player();
/*        
        if(me->query_temp("ridee")){
                horse=me->query_temp("ridee");
                me->command_function("dismount "+horse->query("id"));
        }
*/

message_vision(HIY "$N����һԾ�����뺣�С�ֻ��$Nʹ����ȫ�����������㲢�ã���һ������ε�����ʯ�ϡ�\n" NOR, me);
        me->move("/d/quest/longzhu/qy/haibian");
        message_vision(HIY "ֻ��$N����ʪ�����شӺ�������������\n" NOR, me);
        me->receive_damage("kee", 100);
        me->receive_damage("sen", 150);
        return 1;
}

