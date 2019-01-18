//sgzl

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
set("short", "���");
set("long", @LONG
    
�������ǻ�ϳ��������������ӣ���˵���ǵ�����ĸ����
����ͷ�ϵ����������ģ���������������֮�ϣ���֪������
���ٶ��˵Ĺ��¡�
LONG );


set("exits", ([
]));


set("objects", ([
]));



setup();
}

void init()
{
  object who = this_player();
  add_action("do_swim", "swim");
  add_action("do_xiayu", "xiayu");
  if(who->query("dntg/bmw")=="fight") call_out ("fight_river",3,who);
}

int do_swim()
{
object who = this_player();
object horse = who->query_temp("ridee");

if (! horse) 
  {
  message_vision(HIY "$N����������ӡ�\n" NOR, who);
  who->move(__DIR__"dadao1");
  }
else 
  {
  message_vision(HIY "$N"+horse->query("ride/msg")+"��"+horse->name()+"������ӡ�\n" NOR, who,horse);
  who->move(__DIR__"dadao1");
  horse->move(__DIR__"dadao1");
  }
return 1;
}

int do_xiayu()
{
object who = this_player();
object fu;
if ( present("feng ling fu", this_player()) 
     && present("yun ling fu", this_player()) 
     && present("lei ling fu", this_player()) 
     && present("dian ling fu", this_player()) 
    )
  {
  message_vision(HIY "$N����һָ�������Ʈ��һ�����ơ�\n" NOR, who);
  fu=present("feng ling fu", this_player());
  destruct(fu);
  fu=present("yun ling fu", this_player());
  destruct(fu);
  fu=present("lei ling fu", this_player());
  destruct(fu);
  fu=present("dian ling fu", this_player());
  destruct(fu);
  call_out ("get_rain",3,who);
  }
else 
  {
  message_vision("$N���Ǵ��룢�磢�����ƣ������ף������磢���������������ɡ�\n", who);
  }
return 1;
}

void get_rain (object who)
{
  object horse = who->query_temp("ridee");

  message_vision(HIY "ת˲�䣬����е���������������Ʈ�ô��ꡣ\n" NOR, who);
  if ((who->query("dntg/bmw") == "allow")  && (horse) )
    {
    if ((horse->query("kee")>200) && (horse->query("id")=="ma ju"))
          call_out ("become_horse",3,who);
    }
}

void become_horse (object who)
{
  object horse = who->query_temp("ridee");
  message_vision("С��������и��˵ĳ���һ����\n", who);
  message_vision(HIY "С��Գ����ˣ�\n" NOR, who);
  destruct(horse);
  horse = new ("/d/dntg/bmw/npc/horse");
  horse->move(environment(who));
  who->command("mount horse");
  who->set("dntg/bmw","fight");
  call_out ("fight_river",3,who);
}

void fight_river (object who)
{
  object fighter;

  fighter=new("/d/dntg/sky/npc/tianpeng");
  fighter->move(environment(who));
  message_vision("��Ȼ����Ԫ˧����ææ�����������ȵ������������Σ����˲��ɣ�\n", who);
  fighter->command("follow " + who->query("id"));
  fighter->command("kill " + who->query("id"));
  who->fight_ob(fighter);
  
}
