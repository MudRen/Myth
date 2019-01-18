#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short", HIR"���Ҷ�"NOR);
set("long", @LONG
    
�ⶴ���Ĵ���������֮��ֻ�ȵ��㴭����������
 
LONG );
     set("exits/east", __DIR__"huomigong"+(string)random(8));
     set("exits/west", __DIR__"huomigong"+(string)random(8));
     set("exits/south", __DIR__"huomigong"+(string)random(8));
     set("exits/north", __DIR__"huomigong"+(string)random(8));
     set("objects", ([ /* sizeof() == 4 */
       __DIR__"npc/shenjiang" : 1,
       __DIR__"obj/fire" : 1,
]));
setup();
}
void init() 
{
  delete("exits/out");
   if(this_player()->query_temp("shendian/huomigong_kill") >= 2)
    {
        message_vision(HIY"\nɲ�Ǽ�һ��·�ڳ����������ǰ��\n\n"NOR,this_player());
     set("exits/out", __DIR__"dongwai");
    } 
if (!((this_player()->query_temp("shendian/huomigong") == "begin") || (this_player()->query("id") == "shen jiang")))
   {
    message_vision(HIW"\n���д���$N����ô�����ģ���ȥ��\n\n"NOR,this_player());
    this_player()->move("/d/city/kezhan");
   }
 
   if (this_player()->query_temp("shendian/huomigong") == "begin")
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
  if (random(5)==1 && who->query("kee") > 100 )
    {
     who->add("kee",-(70+random(50)));
    message_vision(HIY"���ܾ���һ����ǽ���յ�$N��ͷ�ö\n"NOR,who);
    COMBAT_D->report_status(who);
    }
  if ( (100*(who->query("kee")))/(who->query("max_kee")) <= 10)
    {
     message_vision(HIY"$N���յ�ͷ���ۻ�����Ҳ֧�Ų�ס�ˡ�\n"NOR,who);
     who->delete_temp("last_damage_from");
     who->set_temp("death_msg", "�����Ҷ��б��ճ��˻ҽ���\n");
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
