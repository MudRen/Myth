#include <ansi.h>

inherit ROOM;
void create()
{
  set ("short","���䳡");
  set ("long",@LONG
  
���������¹�ÿ����б�����ĵط�����Ϊ������Ļ���
������������䲻�����������


LONG);
  set("no_quit",1);
  set("broadcast",1);
  set("alternative_die",1);
  set("exits",([ "east": __DIR__"gong1",]));
  setup();
}
  
void init()
{
  add_action("do_stop", ({"cast","perform"}));
}

void alternative_die (object me)
{
  object ob = me->query_temp("last_damage_from");
  if (me->query("kee")<0) me->set("kee",10);
  if (me->query("eff_kee")<0) me->set("eff_kee",10);
  me->remove_killer(ob);
  ob->remove_killer(me);
  message_vision(HIY"$n��$N���ڵأ�˫ȭһ��΢Ц�����������ˡ���\n"NOR,me,ob);
  message_vision(HIW"���ϴ������뱦���������������ŵ��ӻ����д裬�������١���\n"NOR,me,ob);
  tell_room( __DIR__"juyitang","\n>\n");
  me->move(__DIR__"juyitang");
  ob->move(__DIR__"juyitang");
  me->set("gin", (int)me->query("max_gin"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("kee", (int)me->query("max_kee"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("sen", (int)me->query("max_sen"));
  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("force", (int)me->query("max_force"));
  me->set("mana", (int)me->query("max_mana"));
//me->add("combat_exp",-10000);
//me->add("daoxing",-10000);
  ob->set("gin", (int)ob->query("max_gin"));
  ob->set("eff_gin", (int)ob->query("max_gin"));
  ob->set("kee",(int)ob->query("kee"));
  ob->set("eff_kee",(int)ob->query("eff_kee"));
  ob->set("eff_sen",(int)ob->query("eff_sen"));
  ob->set("sen",(int)ob->query("sen"));
  ob->set("force",(int)ob->query("force"));
  ob->set("mana",(int)ob->query("mana"));
}

void broadcast(string str)
{
  string prefix = HIG"�����䳡�ϡ�"NOR;
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
  tell_room( __DIR__"gong1","\n"+prefix+s1 );
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
  message_vision(HIW"���ϴ������뱦���������������С���ѣ�$N���������������ּ���Ŷ����\n"NOR,who);
  return 1;
}


