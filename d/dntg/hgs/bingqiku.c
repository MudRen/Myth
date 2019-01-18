//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "������");
set("long", @LONG
    
�����ǰ������ı����⣬������ֱ���(bingqi)������ǹ��
����ꪡ������ᡢë�������ޡ��١��Ρ�ﵡ������󡢲桢
ì�������㱸����������Ķѷ��ţ������������ʿ����
�ﱣ���š�
LONG );

set("item_desc",(["bingqi":"
���ָ����ı��������������߲����㣬����(kun)һ�²ź��á�\n"
]));

set("exits", ([
  "north"   : __DIR__"fight_room",
]));


set("objects", ([
  __DIR__"npc/pianjiang" : 4,
]));


set("no_magic", 1);

setup();
}


void init()
{
   add_action("do_kun", "kun");
   add_action("do_ji", "ji");
}


int do_kun(string arg)
{
  object me=this_player();
  object bingq;

  if ( !arg || ( arg != "bingqi" ) ) 
      return notify_fail("��Ҫ��ʲô��\n");

  if(objectp(present("pian jiang", environment(me)))) 
     {
     return notify_fail("ƫ����ȵ����Ҷ��ҹ���������Ķ��������˲��ɣ�\n",me);
     }

  else
    {
    if (me->is_busy())
      return notify_fail ("������æ���ء�\n");

    else if (me->query("kee")<50)  me->unconcious(); 

    else
      {
      me->add("kee",-50);
      message_vision ("$N����ææ��ʰ��һ�ѱ�����������������������������һЩ��\n",me);
      bingq = new ("/d/dntg/hgs/obj/bingqi");
      bingq->move(me);
   me->start_busy(5,5);

      return 1;
      }
    }
    return 1;
}


int do_ji(string arg)
{
        object who;
        object where = this_object();
        object hb = this_object();
        object me = this_player();

        if ( !arg || ( arg != "feng ling fu" ) ) return  notify_fail("�����ʲô��\n");

        else if (!(hb=present(arg, me)) || userp(hb))  // prevent using "bian"
           return notify_fail("������û���ⶫ����\n");
    
        else if (me->query("mana")+random(500)<1000)
          {
          message_vision("$N�ó�����������һ��������������\n", me);
          message_vision("��ʲôҲû�з�������\n", me);
          destruct(hb);
          }
        else
          { 
          message_vision("$N�ó�����������һ��������������\n", me);
          call_out("away",2,me);
          destruct(hb);
          call_out("go_back",60,me);
          }

        return 1;
}

void away(object who)
{
  object where = this_object();
  object who1 = present ("pian jiang 1",where);
  object who2 = present ("pian jiang 2",where);
  
  if(!who1) return;

  destruct(who1);
  destruct(who2);
  tell_object(where,
	  "ֻ��һ�ɿ��ι����������Ƕ��������ۣ�����ƫ���޺������˳�ȥ��\n");
}

void go_back(object who)
{
  object who1,who2;
  object where = this_object();

  // mon 3/24/99
  // prevent getting too many pian jiang by go_back.
  // at most 4.
  if(present ("pian jiang 4",where)) return;

  who1 = new (__DIR__"npc/pianjiang");
  who2 = new (__DIR__"npc/pianjiang");
  who1->move(where);
  who2->move(where);
  tell_object(where,"ƫ���������۾��߻ر����⡣\n");
}


