//sgzl


#include <room.h>
inherit ROOM;
inherit "/d/dntg/hell/hell_sleep.c";
//the starting point of passing dntg_hell

void create()
{
set("short", "������");
set("long", @LONG
    
��Ƿ������ͷ�������ٿ���ȴ�����˼�ס��һ�㣬��������ڡ������ǣ�

������޺���������Ƹ��񣬹�ҡƬƬ��ϼ���鴰���ң����ʰ����������
���������йң��ӻ��������⡣�ּ���һ�����������������÷������
    �����ɳ����꣬��Ȼ����˼ҡ�

���ն�ʱ���������м䣬���ҹۿ���ֻ����������һʯ��(shi jie)��
LONG );

set("item_desc",(["shi jie":"
����������������������
����ˮ������������������������
��������������������������������
������������������ɽ����������
������������������������������
������������������ء���������
����������������������
��\n"
]));



set("exits", ([
"east"   : __DIR__"shifang",
]));


set("objects", ([
]));


create_door("east", "ʯ��", "west", DOOR_CLOSED);


setup();
}

void init ()
{
  object who = this_player();
  ::init();
      
  add_action("do_jump", "jump");

}

int do_jump(string arg)
{
        object me;

        me = this_player();
        if ( !arg || ( arg != "bridge" ) ) return  notify_fail("�����Ķ�����\n");

//        else if ( (random(10)+me->query("kar")+me->query("donation/1000000")) < 40 )
        else if ( random(30)+me->query("kar") < 30 )
          { 
          message_vision("$N��������һԾ���ִӰ����ˤ��������\n", me);
          me->unconcious();
          }

        else
          {
          message_vision("$N�����Ϸ����ݳ��ٲ���\n", me);
          me->move(__DIR__"pubu");
          }

        return 1;
}

