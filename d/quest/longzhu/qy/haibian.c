// ���ɵ� by Calvin
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����Ǹ��ܸߵ��ͱ�,�±������޾��Ĵ�,ǳ�������м���������Ӿ��
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : "/d/calvin/lanling/xiaolu8",
]));
  set("outdoors", 1);

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

message_vision(HIY "$N����һԾ�����뺣�С�ֻ��$Nʹ����ȫ�����������㲢�ã���һ������ε��˺��й��ɵ��ϡ�\n" NOR, me);
        me->move("/d/quest/longzhu/qy/dao");
        message_vision(HIY "ֻ��$N����ʪ�����شӺ�������������\n" NOR, me);
        me->receive_damage("kee", 500+random(500));
        me->receive_damage("sen", 1000+random(500));
//        me->receive_damage("combat_exp", 1000);
//        me->receive_damage("max_kee", 20);
//        me->receive_damage("max_sen", 20);
        return 1;
}





