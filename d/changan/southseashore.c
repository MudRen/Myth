//Cracked by Roath
// Room: /changan/southseashore.c
//cglaem...12/12/96.
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "�Ϻ�֮��");
  set ("long", @LONG

�Ϻ�֮����������һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�
��������һƬ����󺣣���֪ͨ��η������Ϻ����������ɼ�
һС����ǳ�����������м�����Ӿ���ˡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"broadway5",
"west" : "/d/jz/egate",
  "east" : __DIR__"seashore1",
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


//               if(me->query("force") < 60)  
//               return notify_fail("��û����������������к�ģ�\n");  
              if(me->query("kee") < 60)  
                      return notify_fail("�����Ѫ�������޷�ȥ�԰��ˣ�\n");  
              if(me->query("sen") < 60)  
                      return notify_fail("��ľ��񲻹����޷��ε��԰���\n");  
message_vision(HIY "$N����һԾ�����뺣�С�ֻ��$Nʹ����ȫ�����������㲢�ã���һ������ε��˺���С���ϡ�\n" NOR, me);
        me->move("/d/nanhai/island");
        message_vision(HIY "ֻ��$N����ʪ�����شӺ�������������\n" NOR, me);
        me->receive_damage("kee", 35);
        me->receive_damage("sen", 30);
        return 1;
}




