#include <ansi.h>

inherit ROOM;
void create()
{
  set ("short",HIR "�� �� �� ̨" NOR);
  set ("long",@LONG
  
           ��  ��  ��  ��         ��  ��  ��  ͨ

LONG);
  set("no_quit",1);
  set("broadcast",1);
  set("alternative_die",1);
  set("exits",([ "out": __DIR__"pkdao",]));
  setup();
}
  
void init()
{
  add_action("do_stop", ({"cast","perform"}));
call_out("greeting", 1, this_player());
}
void alternative_die (object me)
{
  object ob = me->query_temp("last_damage_from");
  if (me->query("kee")<0) me->set("kee",10);
  if (me->query("eff_kee")<0) me->set("eff_kee",10);
  {string str;
  str=me->name()+"��"+ob->name()+"��"NOR+HIR"ɱ����԰"NOR+HIM"ɱ���ˡ�";
  message("channel:rumor",HIM"����Ѩ���硿ĳ�ˣ�"+str+"\n"NOR,users());}
  me->remove_killer(ob);
  ob->remove_killer(me);
  message_vision(HIG"$n��$N���ڵأ�����һ�ţ���$N�����ˣУ���̨��\n"NOR,me,ob);
  message_vision(HIG"$n�ڹ��ڵĻ������У��߸����˵��³���Ϣ�ˡ�\n"NOR,me,ob);
  tell_room( __DIR__"pkdao","\n>\n");
  me->move("/d/city/kezhan");
  ob->move(__DIR__"pkdao");
  me->set("gin", (int)me->query("max_gin"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("kee", (int)me->query("max_kee"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("sen", (int)me->query("max_sen"));
  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("force", (int)me->query("max_force"));
  me->set("mana", (int)me->query("max_mana"));
   me->add("combat_exp",-10000);
   me->add("daoxing",-10000);
   ob->set("gin", (int)ob->query("max_gin"));
   ob->set("eff_gin", (int)ob->query("max_gin"));
   ob->set("kee",(int)ob->query("kee"));
   ob->set("eff_kee",(int)ob->query("eff_kee"));
   ob->set("eff_sen",(int)ob->query("eff_sen"));
   ob->set("sen",(int)ob->query("sen"));
   ob->set("force",(int)ob->query("force"));
   ob->set("mana",(int)ob->query("mana"));
   ob->add("combat_exp",5000);
   ob->add("daoxing",5000);
}

void broadcast(string str)
{
  string prefix = HIY"���У���̨��"NOR;
  string s1 = str, s2 = "";
  while (strsrch(s1,"\n\n") != -1)
  s1 = replace_string(s1,"\n\n","\n");
  if (s1[strlen(s1)-1]=='\n')
  {
  s1 = s1[0..strlen(s1)-2];
  s2 = "\n";
  }
  if (strlen(s1) == 0)
  return;
  s1 = replace_string(s1,"\n","\n"+prefix)+"";
  reset_eval_cost();
  tell_room( __DIR__"pkdao","\n"+prefix+s1 );
}

int do_stop(string arg)
{
  string *banned_cast=({"jieti"});
  string *banned_action=({"jinsheng"});
  object who = this_player();
  object me = this_object();
  if(!arg) return 0;
  while(sscanf(arg,"%s %*s",arg)==2);
  if(member_array(arg,banned_cast)==-1) return 0;
  message_vision(HIR"���ϴ���һ��ŭ������С���ѣ�$N���������������ּ��ɣ���\n"NOR,who);
  return 1;
}
void greeting(object who) {
if( who->query("combat_exp") < 500000)
{
message_vision(HIR"���ϴ���һ��ŭ������$N��ѧ����50���ˣ����ȥ�ѣ���\n"NOR,who);
who->move("/d/city/kezhan");
}
}
