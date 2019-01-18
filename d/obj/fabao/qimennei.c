#include <ansi.h>
inherit ITEM;
int do_quit();
void self_destruct();
int is_qimen() {return 1;}
int set_exits(string s) {
  if (!s) return 0;
  set("exits", ([
       "east": s,      
       "west": s,      
       "north": s,      
       "south": s,      
       "northeast": s,      
       "southeast": s,      
       "southwest": s,      
       "northwest": s,      
     ]));
  return 1;
}
void create()
{
     set_name("����",({"in qimen","qimen"}));     
     set("short","���Ŷݼ���");
     set("long", @LONG

��ͻȻ����������ת�������ǳ�ȫ����ʧ����Ҳ�ֲ��嶫���ϱ���
��ǰ�������һƬ�������������䣬����������˸������һʱ����
��ţ�һʱ������죬һ�ɾ�������������ֱ�����飬���ɼ�
�ػ���ֱ�����

LONG
     );
     set_max_encumbrance(100000000000);
     set_weight(100);
     set("no_get",1);
     seteuid(getuid());
     set_exits("/d/city/center");     
     setup();
}
void init() {
   object host=query("host");
   object old_room=query("old_room");
   string dir,dest;
   object me=this_player();
   add_action("do_quit", "quit");
   add_action("no_halt","surrender");
   //if (!old_room) return;
   if (!host || environment(host)!=this_object()) 
      call_out("self_destruct",1);
   if (me!=host) 
     add_action("block",({"exert","cast","perform"}));
   else add_action("do_finish","finish");
   if (!userp(me)) {
      me->set("chat_chance_combat_bk",
              me->query("chat_chance_combat"));
      me->delete("chat_chance_combat");
   } else me->set_temp("time_in_qimen",time());
}
int block() {
   write("���������Ŷݼ������Ѽ��������޴룬������˼�������\n");
   return 1;
}
int no_halt() {
   if (this_player()==query("host") && this_player()->is_fighting()) {
      write("Ͷ����û�Ŷ�������������\n");
      return 1;
   }
   return 0;
}
void self_destruct() {
  string dir,dest;
  object old_room=query("old_room");
  object *inv=all_inventory(this_object());
  object host=query("host");
  if (old_room) {
    dir=old_room->query("altered_dir");
    dest=old_room->query("old_room");
    old_room->set("exits/"+dir,dest);
  } else old_room=load_object(query("exits/east"));
  for (int i=0;i<sizeof(inv);i++) {
     if (userp(inv[i])) 
        tell_object(inv[i],"��ͻȻ������ǰ���һ��������һ�����������\n");
     else inv[i]->set("chat_chance_combat", 
               inv[i]->query("chat_chance_combat_bk"));
     inv[i]->move(old_room);
  }
  if (host) host->delete_temp("cast_qimen");  
  destruct(this_object());
}
int do_quit() {      
     write("���ķ����ң���֪����β����˳���\n");
     return 1;
 }
int do_finish() {
  object host=query("host");
  object me=this_player();
  if (host!=me) return 0;
  if (me->is_fighting()) {
    write("����æ�Ŵ�ܣ�û���й���\n");
    return 1;
  }
  message_vision(HIB"$N��һ�ӣ����������Ŷݼ�����\n"NOR,me);
  call_out("self_destruct",1);
  return 1;
}
int valid_leave(object me,string dir) {
  object host=query("host");
  int spells;
  int ap,dp;
  if (!host) return 1;
  if (me==host) 
    if (me->is_fighting()) {
       return notify_fail("�������ӣ������ʰɣ�\n");
    } else return 1;
  spells=host->query_skill("spells");
  ap=host->query("daoxing")+spells*spells*spells/10;
  if (spells>200) spells=200;
  if (userp(me)) {
    me->add("sen",-spells);
    me->add("kee",-spells);
    if (!query_temp("time_in_qimen"))
      set_temp("time_in_qimen",time());
    else 
       if (time()-query_temp("time_in_qimen")>spells)
           return 1;
  }
  spells=me->query_skill("spells");
  dp=me->query("daoxing")+spells*spells*spells/10;
  if (random(ap)<random(dp)) return 1;
  message_vision(HIR"$N��ֻûͷ��Ӭ��ײ��ײȥ���ɾ����Ҳ��ű���\n"NOR,me);
  if (userp(me)) me->start_busy(3+random(5));
    else me->start_busy(2);
  return 0;
}
