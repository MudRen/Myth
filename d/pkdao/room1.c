#include <ansi.h>

inherit ROOM;
void create()
{
  set ("short",HIR "Ｐ Ｋ 舞 台" NOR);
  set ("long",@LONG
  
           八  仙  过  海         各  显  神  通

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
  str=me->name()+"被"+ob->name()+"在"NOR+HIR"杀手乐园"NOR+HIM"杀死了。";
  message("channel:rumor",HIM"【空穴来风】某人："+str+"\n"NOR,users());}
  me->remove_killer(ob);
  ob->remove_killer(me);
  message_vision(HIG"$n把$N打翻在地，飞起一脚，将$N踢下了ＰＫ舞台。\n"NOR,me,ob);
  message_vision(HIG"$n在观众的欢呼声中，高高兴兴地下场休息了。\n"NOR,me,ob);
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
  string prefix = HIY"〖ＰＫ舞台〗"NOR;
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
void greeting(object who)
{
if( who->query("combat_exp") < 500000)
{
message_vision(HIR"天上传来一声怒嚎：“$N武学不够50万了，请回去把！”\n"NOR,who);
who->move("/d/city/kezhan");
}
}
int do_stop(string arg)
{
  string *banned_cast=({"jieti"});
  string *banned_action=({ //"jinsheng"});
  object who = this_player();
//object me = this_object();
  if(!arg) return 0;
  while(sscanf(arg,"%s %*s",arg)==2);
  if(member_array(arg,banned_cast)==-1) return 0;
  message_vision(HIR"天上传来一声怒嚎：“小朋友，$N不能在这里用这种技巧！”\n"NOR,who);
  return 1;
}
void greeting(object who) {
if( who->query("combat_exp") < 500000)
{
message_vision(HIR"天上传来一声怒嚎：“$N武学不够50万了，请回去把！”\n"NOR,who);
who->move("/d/city/kezhan");
}
}