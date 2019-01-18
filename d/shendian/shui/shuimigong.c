#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short", HIB"ˮ����"NOR);
set("long", @LONG
    
�⹬����ȫ��ˮ���ǣ���Ȼ��ˮ�£���ˮ����Ȼ�ļ���
  
LONG );
     set("exits/east", __DIR__"shuimigong"+(string)random(8));
     set("exits/west", __DIR__"shuimigong"+(string)random(8));
     set("exits/south", __DIR__"shuimigong"+(string)random(8));
     set("exits/north", __DIR__"shuimigong"+(string)random(8));
     set("objects", ([ /* sizeof() == 4 */
       __DIR__"npc/shenjiang" : 1,
        __DIR__"obj/shui" : 1,
]));
setup();
}
void init() 
{
  delete("exits/out");
    if(this_player()->query_temp("shendian/shuimigong_kill") >= 2)
    {
        message_vision(HIY"\nɲ�Ǽ�ˮ�����߷ֿ����м������һ��·��\n\n"NOR,this_player());
     set("exits/out", __DIR__"gongwai");
    } 
   if (!((this_player()->query_temp("shendian/shuimigong") == "begin") || (this_player()->query("id") == "shen jiang")))
   {
    message_vision(HIW"\n���д���$N����ô�����ģ���ȥ��\n\n"NOR,this_player());
    this_player()->move("/d/city/kezhan");
   }

    if (this_player()->query_temp("shendian/shuimigong") == "begin")
    {
    remove_call_out ("check_hp");
    call_out ("check_hp", 3,this_player());
    }
   add_action ("do_cast","cast");
}
int check_hp(object who)
  {
  object where = this_object();
  if ( (! who)  ||    (! present(who, where)) )  return 1;
  if (random(6)==1 && who->query("kee") > 50  )
    {
    who->add("kee",-(100+random(50)));
   message_vision(HIB"\nһ������ӿ����$N�����˽�ȥ��\n\n"NOR,who);
    COMBAT_D->report_status(who);
    }
  if ( (100*(who->query("kee")))/(who->query("max_kee")) <= 10)
    {
     message_vision(HIY"$N��ˮ�������ͷת����Ҳ֧�Ų�ס�ˡ�\n"NOR,who);
     who->delete_temp("last_damage_from");
     who->set_temp("death_msg", "��ˮ�����б������ˡ�\n");
     who->die();
     who->save();
     return 1;
    }
  remove_call_out ("check_hp");
  call_out ("check_hp", 3,who);
  return 1;
  }
int do_cast (string arg)
{
  object who = this_player();
if (who->query_temp("shendian/huomigong")=="begin" && 
             (arg=="escape" || arg=="shuidun" || arg=="tudun"))
     {
      tell_object(who,"���ﲻ��������\n");
      return 1;
     }
  else return 0;
}
