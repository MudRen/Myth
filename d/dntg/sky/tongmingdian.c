#include <ansi.h>
#include <room.h>
#include </d/dntg/sky/laojunluhelp.h>

inherit ROOM;

int leave_here(string arg,object who);


void create()
{
set("short", "ͨ����");
set("long", @LONG
    
�빬�Ĵ��������ǰ���죬�߲���Զ�������������ˡ�
�������������Կ���������ΰ�ĵ��ţ��ʹ�˵�����
����������ǡ�
LONG );



set("exits", ([
  "north"   : __DIR__"bishagong",
  "south"   : __DIR__"caihongqiao2",
  "west"   : __DIR__"baoguangdian",
  "east"   : __DIR__"lingxudian",
]));

set("objects", 
([
    __DIR__"npc/youshengzhenjun" : 1,
]));

setup();
}


void init()
  {
   object who=this_player();
   object where=this_object();
   object zhenjun,lingguan;
   int i;



   add_action("do_quit", "quit");
   add_action ("do_cast","cast");

   if (who->query("dntg/laojunlu")=="allow")
     {
     tell_room(environment(who),"ֻ��"+who->name()+"���������\n",who); 

     if (! present ("yousheng zhenjun",where))
       {
       zhenjun=new (__DIR__"npc/youshengzhenjun");
       zhenjun->move(where);
       tell_room(environment(who),zhenjun->name()+"�ҴҸ�����\n",who); 
       }
       zhenjun=( present ("yousheng zhenjun", where));
       zhenjun->command("chat "+who->query("name")
          +"��ͨ�����ˣ�");
       message_vision("$Nһ���֣�����������٣���$nΧ�ڵ��У�\n",zhenjun,who);
       for (i=0;i<4;i++)
         {
         lingguan=new (__DIR__"npc/lingguan");
         lingguan->move(where);
         lingguan->kill_ob(who);
         }
       where->set("fight_here","yes");
       zhenjun->kill_ob(who);
       leave_here("��ʥ���",who);      
     }
   else if(where->query("fight_here") == "yes") you_leave("��ʥ���",who);
  }


int valid_leave(object me, string dir)
{
   object where=this_object();

   if (me->query("dntg/laojunlu") != "allow")
      return ::valid_leave(me, dir);
   else if (present ("yousheng zhenjun",where) || present ("ling guan",where))
      return notify_fail("��ô����Χ���㣬��ô�ߣ�\n");
   else if (dir != "north")
      return notify_fail("�Ѿ��ֵ��ⲽ��أ�����һ�����������ޣ�����������\n");
   else 
     {
     me->set("dntg/laojunlu","allow1");
     where->set("fight_here","no");
     return ::valid_leave(me, dir);

     }
}

int do_cast (string arg)
{
  object who = this_player();
  string cast_id,cast_name;

  if (who->query("dntg/laojunlu")=="allow" && 
             (arg=="escape" || arg=="shuidun" || arg=="tudun" || arg=="chuqiao"))
     {
      tell_object(who,"�����ܣ�\n");
      return 1;
     }
  else if (who->query("dntg/laojunlu")=="allow" 
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
