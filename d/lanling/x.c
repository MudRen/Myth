// ʱ��ת���� by Calvin

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "ʱ����");
  set ("long", @LONG
LONG);

  set("exits", ([ /* sizeof() == 2 */
//            "up" : __DIR__"feixu",
]));
//  set("outdoors", 1);

  setup();
}

void init()
{
        add_action("do_ca", "ca");
        add_action("do_yt", "yt");
        add_action("do_swim", "ml");
        add_action("do_saiya", "saiya");
        add_action("do_swim", "gd");
        add_action("do_swim", "st");
        add_action("do_swim", "ps");
        add_action("do_fc", "fc");
        add_action("do_swim", "xs");
        add_action("do_swim", "lg");
        add_action("do_swim", "ss");
        add_action("do_swim", "jt");
        add_action("do_swim", "mg");
        add_action("do_swim", "tz");
}

int do_ca()
{
        object  me, horse;
        me = this_player();
/*        
        if(me->query_temp("ridee")){
                horse=me->query_temp("ridee");
                me->command_function("dismount "+horse->query("id"));
        }
*/

message_vision(HIY "$N�������,ֻ��һ������֮�����ʧ�ˡ�\n" NOR, me);
        me->move("/d/city/center");
        message_vision(HIY "������˫��,ԭ��������������һ�ռ��ˡ�\n" NOR, me);
        me->receive_damage("kee", 100);
        me->receive_damage("sen", 100);
        return 1;
}

int do_saiya()
{
        object  me, horse;
        me = this_player();

/*        
        if(me->query_temp("ridee")){
                horse=me->query_temp("ridee");
                me->command_function("dismount "+horse->query("id"));
        }
*/

message_vision(HIY "$N�������,ֻ��һ������֮�����ʧ�ˡ�\n" NOR, me);
        me->move("/d/longzhu/qy/saiya");
        message_vision(HIY "������˫��,ԭ��������������һ�ռ��ˡ�\n" NOR, me);
        me->receive_damage("kee", 600);
        me->receive_damage("sen", 700);
        return 1;
}

int do_fc()
{
        object  me, horse;
        me = this_player();
/*        
        if(me->query_temp("ridee")){
                horse=me->query_temp("ridee");
                me->command_function("dismount "+horse->query("id"));
        }
*/

message_vision(HIY "$N�������,ֻ��һ������֮�����ʧ�ˡ�\n" NOR, me);
        me->move("/d/lingtai/gate");
        message_vision(HIY "������˫��,ԭ��������������һ�ռ��ˡ�\n" NOR, me);
        me->receive_damage("kee", 100);
        me->receive_damage("sen", 100);
        return 1;
}

int do_yt()
{
        object  me, horse;
        me = this_player();

/*        
        if(me->query_temp("ridee")){
                horse=me->query_temp("ridee");
                me->command_function("dismount "+horse->query("id"));
        }
*/

message_vision(HIY "$N�������,ֻ��һ������֮�����ʧ�ˡ�\n" NOR, me);
        me->move("/d/dntg/yunlou/yunloutai");
        message_vision(HIY "������˫��,ԭ��������������һ�ռ��ˡ�\n" NOR, me);
        me->receive_damage("kee", 100);
        me->receive_damage("sen", 100);
        return 1;
}

