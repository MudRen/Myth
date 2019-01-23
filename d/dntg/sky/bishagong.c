#include <ansi.h>
#include <room.h>
#include "laojunluhelp.h"

inherit ROOM;

int leave_here(string arg,object who);

string *files = ({
  "/d/dntg/laojunlu/npc/moli-qing",
  "/d/dntg/laojunlu/npc/moli-hong",
  "/d/dntg/laojunlu/npc/moli-hai",
  "/d/dntg/laojunlu/npc/moli-shou",
});


void create()
{
set("short", "��ɳ��");
set("long", @LONG

��ɳ����վ���ż���ׯ�ϵ���ʿ��ɨ����ûһ���������ˡ�
LONG );

set("exits", ([
  "south"   : __DIR__"tongmingdian",
  "north"   : __DIR__"tonglugong",
]));


set("objects", ([
    __DIR__"npc/yishengzhenjun" : 1,
]));

setup();
}


void init()
  {
   object who=this_player();
   object where=this_object();
   object zhenjun,defender;
   int i;



   add_action("do_quit", "quit");
   add_action("do_ji", "ji");
   add_action ("do_move","move");
   add_action ("do_cast","cast");

   if (who->query("dntg/laojunlu")=="allow1")
     {
     tell_room(environment(who),who->name()+"ŭ��崳�˹�����\n",who); 

     if (! present ("yisheng zhenjun",where))
       {
       if (!(zhenjun=find_living("yisheng zhenjun")))
       zhenjun=new (__DIR__"npc/yishengzhenjun");
       zhenjun->move(where);
       tell_room(environment(who),zhenjun->name()+"�ҴҸ�����\n",who); 
       }
       zhenjun=( present ("yisheng zhenjun", where));
       zhenjun->command("chat "+who->query("name")+"��"+RANK_D->query_rude(who)+"����ɳ���ˣ��Ĵ����������ȼݣ�");
       message_vision("ֻ���Ĵ�������ӵ��������$NΧ�ڵ��У�\n",who);
       for (i=0;i<4;i++)
         {
         defender=new (files[i]);
         defender->move(where);

         defender->kill_ob(who);
         }
       where->set("fight_here","yes");
       zhenjun->kill_ob(who);
       leave_here("�ʥ���",who);      
     }
   else if(where->query("fight_here") == "yes") you_leave("�ʥ���",who);
  }


int valid_leave(object me, string dir)
{
   object where=this_object();

   if (me->query("dntg/laojunlu") != "allow1")
      return ::valid_leave(me, dir);
   else if (present ("yisheng zhenjun",where) || present ("tian wang",where))
      return notify_fail("��ô����Χ���㣬��ô��ȥ��\n");
   else if (dir != "north")
      return notify_fail("�Ѿ��ֵ��ⲽ��أ�����һ�����������ޣ�����������\n");
   else 
     {
     me->set("dntg/laojunlu","finish");
     where->set("fight_here","no");
     return ::valid_leave(me, dir);
     }
}

int do_cast (string arg)
{
  object who = this_player();
  string cast_id,cast_name;

  if (who->query("dntg/laojunlu")=="allow1" 
         && (arg=="escape" || arg=="shuidun" || arg=="tudun" || arg=="chuqiao"))
     {
      tell_object(who,"�����ܣ�\n");
      return 1;
     }
  else if (who->query("dntg/laojunlu")=="allow1" 
        && ((sscanf(arg, "%s on %s", cast_id,cast_name) == 2 
                && cast_id=="qiankun") || arg=="qiankun"))
     {
      tell_object(who,"��������������Ԫ���ɵ�������������ͽ��"
                +"�ֵ������ⲽ��أ���Ҫ���ҹ��з���������ǣ����ȫ�۵��ӣ�\n");
      return 1;

     }
  else return 0;
}

int do_quit(string arg)
{
    tell_object(this_player(), "���ﲻ���뿪��Ϸ��\n");
    return 1;
}
int do_ji(string arg)
{
tell_object(this_player(), "�������뻹�����ɼұ�����\n");
  return 1;
}
int do_move(string arg)
{
    tell_object(this_player(), "��ʴ�۴��һ����������С���������޻أ�����С���ɡ���\n");
    return 1;
}