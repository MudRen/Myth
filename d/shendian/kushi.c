#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
  set("short", "����");
  set ("long", @LONG

����������̨�ϵ�����һ�����䡣�����������ĵط���

LONG);
  set("exits", ([ /* sizeof() == 1 */
                 "east" : __DIR__"tianshentai",
                 ]));
  set("no_clean_up", 1);
  set("no_fight", 1);
   set("no_magic", 1);
  set("alternative_die",1);
  set("sleep_room", 1);
  set("outdoors", 0);
  setup();
}       
void init()
{
  add_action("do_zuochan", "zuochan");
}
 int do_zuochan()
{
  int myforce, myspi, learned, sencost;
    object me = this_player();
   int num;
   num = 0;
   if((int)me->query("combat_exp") < 2000000)
   num = 150;
    else {if((int)me->query("combat_exp") < 3500000)
    num = 250;
    else num = 350;}
   if((int)me->query_skill("force",1) < num)
   {
    if(me->query("babu/shendian") == "done")
    {
    myforce = me->query_skill("force");
      myspi=(int)me->query_spi();
  learned=(myforce+myspi)/6;

  if( myforce < 100 )
       sencost = 30+(myforce/10);
  else  
        sencost = 30+(myforce/5);

  if ((int)me->query("sen")<=sencost)
      return notify_fail("�����ǲ��壬��������ȥ����Σ�յģ�\n");
  if(me->query("force")<=(sencost/2))
    return notify_fail("����������㣬������������ڹ���\n");
  me->receive_damage("sen", sencost);
  me->add("force", -(sencost/2));
   tell_object (me, "��ġ������ڹ������н�չ��\n");
  me->improve_skill("force",learned);
   return 1;
    }
    else
    {
    message_vision(HIY"$N��ô�����ģ���ȥ�ɣ�\n"NOR,this_player());
   message_vision(HIY"$N��һֻ���е���ץ�����ϳǿ�ջ��\n"NOR,this_player());
   this_player()->move("/d/city/kezhan");
    return 1;
    }
   }
   else
   {
   message_vision(HIW"$N����Ϊ�Ѿ������ˣ�\n"NOR,this_player());
       return 1;
   }
}
