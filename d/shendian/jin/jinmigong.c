#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short", HIY"����"NOR);
set("long", @LONG
    
�����������ѽ������ǵ��������ġ�
  
LONG );
     set("exits/east", __DIR__"jinmigong"+(string)random(8));
     set("exits/west", __DIR__"jinmigong"+(string)random(8));
     set("exits/south", __DIR__"jinmigong"+(string)random(8));
     set("exits/north", __DIR__"jinmigong"+(string)random(8));
     set("objects", ([ /* sizeof() == 4 */
       __DIR__"npc/shenjiang" : 1,
        __DIR__"obj/jian" : 1,
]));
setup();
}
void init() 
{
        int i;
        object* inv;
        object me = this_object();
  delete("exits/out");
  if(this_player()->query_temp("shendian/jinmigong_kill") >= 2)
    {
        message_vision(HIY"\nɲ�Ǽ����еĽ�����ʧ�ˣ����ڳ����ˡ�\n\n"NOR,this_player());
     set("exits/out", __DIR__"zhenwai");
    } 
 if (!((this_player()->query_temp("shendian/jinmigong") == "begin") || (this_player()->query("id") == "shen jiang")))
   {
    message_vision(HIW"\n���д���$N����ô�����ģ���ȥ��\n\n"NOR,this_player());
    this_player()->move("/d/city/kezhan");
   }
 if (this_player()->query_temp("shendian/jinmigong") == "begin")
    {
    remove_call_out ("check_hp");
    call_out ("check_hp", 3,this_player());
    }
        inv = all_inventory(this_player());
        for(i=0; i<sizeof(inv); i++) 
        {
                if( inv[i]->query_unique() ) {
message_vision(HIW"ͻȻ�䣬$n��һ���׹��ȥ����Ӱ���٣�\n"NOR,inv[i]);
                        destruct(inv[i]);
                }
        }
   add_action ("do_cast","cast");
}
int check_hp(object who)
  {
  object where = this_object();
  if ( (! who)  ||    (! present(who, where)) )  return 1;
  if (random(6)==1 && who->query("sen") > 50 )
    {
        who->add("sen",-(110+random(50)));
   message_vision(HIY"\nಣ�һ�ѽ����Ա߷��˳���������$N�����塣\n\n"NOR,who);
     COMBAT_D->report_sen_status(who);
    }
  if ( (100*(who->query("kee")))/(who->query("max_kee")) <= 10)
    {
     message_vision(HIY"$N������Ѫ��ģ������Ҳ֧�Ų�ס�ˡ�\n"NOR,who);
     who->delete_temp("last_damage_from");
     who->set_temp("death_msg", "�ڽ����б�ɱ���ˡ�\n");
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
  if (who->query_temp("shendian/tumigong")=="begin" && 
             (arg=="escape" || arg=="shuidun" || arg=="tudun"))
     {
      tell_object(who,"���ﲻ��������\n");
      return 1;
     }
  else return 0;
}
