//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.3
//  /d/qujing/yingjian/lakeside1.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "ӥ���");
  set ("long", @LONG

��һ��������ȥ��ֻ��������������絶��һ�㣬ˮ���峹
���壬������Щ��ȵ�����˽�ʱ������ˮ�����Լ�����Ӱ������
Ϊ���Լ���ͬ�飬������ˮ�У�����ӥ�����
LONG);

  set("exits", ([
        "east" : __DIR__"lakeside2",
        "southwest" : __DIR__"grass",
        "west" : __DIR__"grass2",
      ]));
  set("outdoors","yj");
  setup();

}
void init()
{
        object me = this_player();
        add_action("do_dive","dive");
                
        if( me->query("obstacle/yj") == "done" )
                return;
        if(! me->query("obstacle/sc") )
                return;
        if( me->query_temp("see_dragon") )
                return; 
        if( present("bai long") )
                return;

        remove_call_out("dragon_appear");
        call_out("dragon_appear",1,me);
        
}

int dragon_appear(object me)
{
        object dragon = new(__DIR__"npc/long");
        dragon->move(environment(me));
        tell_room(environment(me),HIW"��Ȼ��������һ�������Խ��׳����\n"NOR);
        me->set_temp("see_dragon",1);
        message_vision(HIR"��Ȼ����β����$N����ȥ��\n"NOR,me);
        me->unconcious();
        destruct(dragon);        
        return 1;
}

int do_dive()
{
        object me = this_player();
        object zhou; 
       if(( !(zhou=present("bishui zhou", me))
       ||(string)zhou->query("unit")!="��" ) )
       return notify_fail("��һ����������ˮ�����\n"+
       "\n��û�����ͱ���ð�����ֻ�øϽ����ϰ�����\n");

        message_vision(HIY "$N����һԾ�����������\n" NOR, me);
        me->move(__DIR__"jiandi1");
        message_vision(HIY "$N�ӽ�������������\n"NOR,me);
        return 1;
}

