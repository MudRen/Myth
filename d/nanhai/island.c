//Cracked by Roath
// Room: /d/nanhai/haibian
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "С��");
  set ("long", @LONG

��������Ƹ����񣬹²����С�׻����������Ϻ��ϵ�һ��С����
����Сȴ�����������˵�����������ڵ��ϴ���˵������ĿԶ����
�����ɼ���½��������
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"tingjing",
]));
  set("outdoors", "/d/nanhai");

  setup();
}

void init()
{
        add_action("do_swim", "swim");
}

int do_swim()
{
        object me, horse;
	me = this_player();
/*	
        if(me->query_temp("ridee")){
                horse=me->query_temp("ridee");
                me->command_function("dismount "+horse->query("id"));
        }                        
*/
//              if(me->query("force") < 60)  
//                       return notify_fail("��û����������������к�ģ�\n");  
              if(me->query("kee") < 60)  
                      return notify_fail("�����Ѫ�������޷�ȥ�԰��ˣ�\n");  
              if(me->query("sen") < 60)  
                      return notify_fail("��ľ��񲻹����޷��ε��԰���\n");  

message_vision(HIY "$N����һԾ�����뺣�С�ֻ��$Nʹ����ȫ�����������㲢�ã���һ������ε��˴�½���ߡ�\n" NOR, me);
        me->move("/d/changan/southseashore");
	message_vision(HIY "ֻ��$N����ʪ�����شӺ�������������\n" NOR, me);
	me->receive_damage("kee", 20);
	me->receive_damage("sen", 20);
        return 1;
}

