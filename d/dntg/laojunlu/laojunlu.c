#include <ansi.h>
#include <room.h>
inherit ROOM;


void create()
{
set("short", "����");
set("long", @LONG
    
�����¯���Ĵ���������֮���������У�ֻ�е����������ѵ���
LONG );

     set("exits/east", __DIR__"laojunlu"+(string)random(8));
     set("exits/west", __DIR__"laojunlu"+(string)random(8));
     set("exits/south", __DIR__"laojunlu"+(string)random(8));
     set("exits/north", __DIR__"laojunlu"+(string)random(8));

     set("objects", ([ /* sizeof() == 4 */
       __DIR__"npc/huoshen" : 1,

]));

     set("has_ppl","no");
setup();
}

void init() 
{
  delete("exits/out");
  if( userp(this_player()) )  this_object()->set("has_ppl","yes");
  if(this_player()->query_temp("dntg/laojunlu_day") >= 49)
    {
     if (this_player()->query("dntg/laojunlu") != "allow")
       {
        message_vision(HIY"ֻ��������������̫���Ͼ���������ʱ���ѵ���ͯ����¯�ɡ�\n"NOR,this_player());
        this_player()->set("dntg/laojunlu","allow");
       } 
     set("exits/out", __DIR__"luwai");
    } 


  if (this_player()->query("dntg/laojunlu") == "begin")
    {
    remove_call_out ("check_hp");
    call_out ("check_hp", 3,this_player());
    }


  add_action("do_quit", "quit");
   add_action ("do_cast","cast");
}

int check_hp(object who)
  {
  object where = this_object();


  if ( (! who)  ||    (! present(who, where)) )  return 1;

  if (random(4)==1 && who->query("kee") > 20  )
    {
    who->add("kee",-20);
    message_vision(HIY"�ıھ���һ�Ż��棬�յ�$N��ͷ�ö\n"NOR,who);
    }
  if ( (100*(who->query("kee")))/(who->query("max_kee")) <= 10)
    {
     message_vision(HIY"$N���յ�ͷ���ۻ�����Ҳ֧�Ų�ס�ˡ�\n"NOR,who);
     who->delete_temp("last_damage_from");
     who->set_temp("death_msg", "�ڰ���¯�б������һ��ճ��˻ҽ���\n");
     who->die();
     who->save();
     return 1;
    }


  remove_call_out ("check_hp");
  call_out ("check_hp", 3,who);

  return 1;
  }


int do_quit ()
{
  object me;
  object tiangong=load_object("/d/dntg/sky/lingxiao.c");
  object yuhuang;

  me = this_player();
  me->set("startroom",base_name(environment(me)));

  if ( present ("yuhuang dadi", tiangong))
    {
    yuhuang=( present ("yuhuang dadi", tiangong));
    yuhuang->delete("laojunlu");
    }

  this_object()->set("has_ppl","no");
  tell_object(me,"��ʱ�뿪�Ͼ�¯����\n");
  return 0; 
}


int valid_leave(object me, string dir)
{
/*
    object tiangong=load_object("/d/dntg/sky/lingxiao.c");
    object yuhuang;

    if ( present ("yuhuang dadi", tiangong) && dir=="out")
      {
      yuhuang=( present ("yuhuang dadi", tiangong));
      yuhuang->delete("laojunlu");
      }
*/
    this_object()->set("has_ppl","no");
    remove_call_out ("check_hp");
    return ::valid_leave(me, dir);
}

int do_cast (string arg)
{
  object who = this_player();

  if (who->query("dntg/laojunlu")=="allow" && 
             (arg=="escape" || arg=="shuidun" || arg=="tudun"))
     {
      tell_object(who,"�����ܣ�\n");
      return 1;
     }
  else return 0;
}
