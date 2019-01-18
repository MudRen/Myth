// created 10/05/1997 by snowcat
#include <ansi.h>

inherit NPC;

#define DEBUG 0

#define MYFILE "/d/huanggong/npc/pang.c"

#define MAXCATEGORY 5
#define MAXPOSITION 3

string *categories = ({
  "���",
  "����",
  "ͭ��",
  "����",
  "����",
 });

string *positions = ({
  "״Ԫ",
  "����",
  "̽��",
 });

int *limits = ({
  200000,
  100000,
  50000,
  10000,
  1000,
 });

#define LEVEL_NONE 0
#define LEVEL_ASKED 1
#define LEVEL_RANKED 2

int interval_set = 0;
int fight_times = 0;
string FST = 0;

void create()
{
  set_name("������", ({ "pang xuanling", "pang", "xuanling" }));
  set("title", "������");
  set("gender", "����");
  set("age", 60);
  set("per", 30);
  set("combat_exp", 300000);
  set_skill("force", 80);
  set_skill("spells", 80);
  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set("gin", 3000);
  set("max_gin", 3000);
  set("kee", 3000);
  set("max_kee", 3000);
  set("sen", 3000);
  set("max_sen", 3000);
  set("force", 1000);
  set("max_force", 1000);
  set("mana", 1000);
  set("max_mana", 1000);
  set("force_factor", 80);
  setup();
  carry_object("/d/obj/cloth/jinpao")->wear();

}

int execute_help();
int execute_ask();

void init()
{
  ::init();
  add_action("do_fight", "fight");
  add_action("do_kill", "kill");
  add_action("do_steal", "steal");
  add_action("do_cast", "cast");
  add_action("do_exert", "exert");
  add_action("do_perform", "perform");
  add_action("do_bian", "bian");
  set("inquiry", ([
        "?":   (: execute_help() :),
        "help":   (: execute_help() :),
        "fight":  (: execute_ask() :),
        "Ͷ״":   (: execute_ask() :),
        "״Ԫ":   (: execute_ask() :),
        "��״Ԫ": (: execute_ask() :),
        "����":   (: execute_ask() :),
      ]));
  if (FST == 0)
  {
    FST = "/d/huanggong/fst";
  }
}

string randomize (string *strs)
{
  return strs[random(sizeof(strs))];
}

string get_name (object who)
{
  return who->query("name");
}

string get_respect (object who)
{
  return "��λ"+RANK_D->query_respect(who);
}

void announce (object me, string str)
{
  if (DEBUG)
  { 
    object snowcat = find_player ("snowcat");
    if (snowcat && wizardp(snowcat))
      tell_object (snowcat,"�� "+str+"\n");
  }
  else
  {
    CHANNEL_D->do_channel(me,"chat",str);
  }
}

int do_fight(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
    message_vision ("$N��$n��æʾ��: "+get_respect(who)+
                    "��������ɶ��֣�\n",me,who);
    return 1;
  }
  return 0;
}

int do_kill(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
    message_vision ("$N��$n��æʾ��: "+get_respect(who)+
                    "�����ڲ�������ɱ�ˣ�\n",me,who);
    return 1;
  }
  return 0;
}

int do_cast(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg == "transfer")
    return 0;

  message_vision ("$N��$n��æʾ��: "+get_respect(who)+
                  "�����������ʩ������\n",me,who);
  return 1;
}

int do_exert(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg != "sheqi pang xuenling" &&
      arg != "sheqi pang" &&
      arg != "sheqi xuenling")
    return 0;

  message_vision ("$N��$n��æʾ��: "+get_respect(who)+
                  "���������˽ʩа����\n",me,who);
  return 1;
}

int do_perform(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N��$n��æʾ��: "+get_respect(who)+
                  "���������˽ʩа����\n",me,who);
  return 1;
}

int do_steal(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N��$n��æʾ��: "+get_respect(who)+
                  "�������������ԣ�\n",me,who);
  return 1;
}

int do_bian(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N��$n��æʾ��: "+get_respect(who)+
                  "���������������\n",me,who);
  return 1;
}

int execute_help ()
{
  object who = this_player();
  object me = this_object();

  switch (me->query_temp("huanggong/level"))
  {
    case LEVEL_NONE:
    {
      message_vision ("$N��$n˵����"+get_respect(who)+
                      "�빬Ӧ��Ͷ״���к��Ѵ����ʱ��ǡ�\n",me,who);
      break;
    }
    case LEVEL_ASKED:
    {
      message_vision ("$N��$n˵����"+get_respect(who)+
                      "��ƾ�����书�ߵͣ���ȥ�������ͭ������������ѡ��һ��"+
                      "����״Ԫ����̽��֮һ��֮��ս��\n",me,who);
      break;
    }
    case LEVEL_RANKED:
    {
      message_vision ("$N��$n˵����"+get_respect(who)+
                      "��ƾ�����书�ߵͣ���ȥ�������ͭ������������ѡ��һ��"+
                      "����״Ԫ����̽��֮һ��֮��ս��\n",me,who);
      break;
    }
  }
  return 1;
}

void reset_interval ()
{
  interval_set = 0;
  fight_times = 0;
}

int execute_ask ()
{
  object who = this_player();
  object me = this_object();

  if (who->query("combat_exp") >= limits[0])
  {
    message_vision ("$N��$n��æҡͷ����"+get_respect(who)+
                    "���书��Ϊ�����ﻹ�õ�������СС������!\n",me,who);
    return 1;
  }

  if (me->query_temp("huanggong/is_busy"))
  {
    message_vision ("$N��$nҡҡͷ��"+get_respect(who)+
                    "���Ϸ���æ�ò��ɿ�����ˡ��ʧ���ˡ�\n",me,who);
    return 1;
  }

  if(me->query_temp("huanggong/level") < LEVEL_ASKED)
  {
    if (interval_set)
    {
      message_vision ("$N��$nҡҡͷ��"+get_respect(who)+
                      "��Ͷ״ʱ���ѹ���ˡ��ˡ�\n",me,who);
      return 1;
    }

    announce (me,who->query("name")+get_respect(who)+"ǰ���빬Ͷ״��\n");
    message_vision ("$N��$n˵����"+get_respect(who)+
                    "���Ϸ����������£������׼���±����ѡ��״Ԫ��\n",me,who);
    message_vision ("$Nһ˦���䣬��һ����ȥ��\n",me);
    //me->set("env/invisibility",9);
    me->set_temp("huanggong/reappear",environment(me));
    load_object("/obj/empty");
    me->move("/obj/empty");
    remove_call_out ("make_asked");
    call_out ("make_asked",10,me,who);
    return 1;  
  }
  // LEVEL_ASKED, LEVEL_RANKED
  remove_call_out ("continue_asked");
  call_out ("continue_asked",1,me,who);
  return 1;  
}

void make_asked (object me, object who)
{
  int i;
  object *list;

  if (!who ||
      !environment(who) ||
      environment(who) != me->query_temp("huanggong/reappear"))
  {
    me->move(me->query_temp("huanggong/reappear"));
    message_vision ("$N˦�ų��䣬��һ��Ʈ�˹�����\n",me);
    return;
  }

  announce (me,"���¶�׼���±����ѡ��״Ԫ��");
  announce (me,"����ĺ���·���ʿ�������Ͷ״��");

  interval_set = 1;
  fight_times = 0;
  call_out ("reset_interval", 14400); // 4h
  me->set_temp("no_return",1);
  me->set_temp("huanggong/level",LEVEL_ASKED);
  //me->set("env/invisibility",0);
  me->move(me->query_temp("huanggong/reappear"));
  message_vision ("$N˦�ų��䣬��һ��Ʈ�˹�����\n",me);
  remove_call_out ("continue_asked");
  call_out ("continue_asked",1,me,who);

}

void continue_asked (object me, object who)
{
  message_vision ("$N��$n˵����"+get_respect(who)+
                  "���Ϸ�ȥ�Ұ���ս��\n",me,who);
  message_vision ("$Nһ˦���䣬����Ʈ��$n���档\n",me,who);
  who->set_leader(me);
  me->set_leader(who);
}

int execute_approve_fight(object who, object ob, int position, int category)
{
  object *all, *list, *inv;
  int i, j;
  object me = this_object();

  if (who->query("combat_exp") >= limits[0])
  {
    message_vision ("$N��$n˵������"+get_respect(who)+
                    "���书��Ϊ�����ﻹ�õ�������СС������!\n",me,who);
    return 0;
  }

  if (who->query("combat_exp") >= limits[category-1])
  {
    message_vision ("$N��$n˵������"+get_respect(who)+
                    "���书��Ϊ���ݽ�"+categories[category-1]+"�������ֵ�����?���ñ���,���ñ��ˡ�\n",me,who);
    return 0;
  }

  if (category < MAXCATEGORY &&
      who->query("combat_exp") < limits[category])
  {
    message_vision ("$N��$n˵����"+get_respect(who)+
                    "���书��Ϊ�ƺ��������ݽ�"+categories[category-1]+"�ĵز�,�������аɡ�\n",me,who);
    return 0;
  }

  announce (me,who->query("name")+"ǰ���ݽ�"+categories[category-1]+
            "����"+ob->query("name")+"��������"+positions[position-1]+"��\n");
  
  me->set_temp("huanggong/is_busy",1);
  me->set_leader(0);
  call_out("reset_is_busy",60,me);
  return 1;
}

int execute_fight_result (object who, object ob, int success)
{
  object me = this_object();
  int i, y, d, h;

  reset_eval_cost();
  call_out("reset_is_busy",5,me);

  if (! success)
    return 1;
  if (!ob)
    return 1;
  if (!present(ob, environment(me)))
    return 1;

  announce (me,ob->query("name")+environment(me)->query("short")+
            "����"+who->query("name")+"��\n");
  announce (me,"������ּ����"+ob->query("name")+"Ϊ"+
            who->get_honor_str()+"��\n");
  i = ob->query("huanggong/wins")+1;
  ob->set("huanggong/wins",i);
  i = (MAXPOSITION*MAXCATEGORY*9)/i + random(9);
  ob->add("combat_exp",i);
  /*
  y = i/1000;
  d = (i - y*1000) / 4;
  h = (i - y*1000 - d*4) * 3;
  if (y > 0)
    tell_object(ob,"��ĵ���������"+chinese_number(y)+"��"+
                chinese_number(d)+"��"+chinese_number(h)+"ʱ����\n\n");
  else if (d > 0)
    tell_object(ob,"��ĵ���������"+
                chinese_number(d)+"��"+chinese_number(h)+"ʱ����\n\n");
  else if (h > 0)
    tell_object(ob,"��ĵ���������"+
                chinese_number(h)+"ʱ����\n\n");
  */
  tell_object(ob,"�����ѧ��Ϊ������"+chinese_number(i)+"��!\n\n");
  me->set_temp("huanggong/current_player",ob->query("id"));
  me->set_temp("huanggong/level",LEVEL_RANKED);

  fight_times++;
  if (fight_times > (MAXPOSITION*MAXCATEGORY/2))
  {
    announce (me,"������ּ��ѡ��״Ԫ������·���ʿ�����빬��\n");
    message_vision ("$N˦һ˦���䣬��һ��Ʈ���ˡ�\n",me);
    me->move(FST);
    me->set_temp("huanggong/is_busy",0);
    me->set_temp("huanggong/level",LEVEL_NONE);
    return 1;
  }

  message_vision ("$N���������ʿ��������ս��"+
                  "�ɴ��Ϸ�ȥ�Ұ�\n",me);
  message_vision ("$Nһ˦���䣬Ʈ��$n���\n",me,ob);
  me->set_leader(ob);
  return 1;
}

void reset_is_busy(object me)
{
  me->set_temp("huanggong/is_busy",0);
}

