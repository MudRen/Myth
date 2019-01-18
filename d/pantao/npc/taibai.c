// created 5/30/1997 by snowcat
#include <ansi.h>

inherit NPC;

#define DEBUG 0

#define MYFILE "/d/pantao/npc/taibai.c"

#define MAXPOSITION 7

#define LEVEL_NONE 0
#define LEVEL_ASKED 1
#define LEVEL_RANKED 2
#define LEVEL_FEAST 3

int interval_set = 0;
string YAOCHI = 0;

void create()
{
  string saying = "̫�׽��������������";

  set_name("̫�׽���", ({"tai bai", "tai", "bai" }));
  set("title", "����");
  set("gender", "����");
  set("age", 10000);
  set("per", 30);
  set("long", "��������̫�׽��ǡ�\n");
  set("combat_exp", 10000000);
  set("daoxing", 2000000);

  set_skill("force", 500);
  set_skill("spells", 500);
  set_skill("unarmed", 500);
  set_skill("dodge", 500);
  set_skill("parry", 500);
  set("gin", 50000);
  set("max_gin", 50000);
  set("kee", 50000);
  set("max_kee", 50000);
  set("sen", 50000);
  set("max_sen", 50000);
  set("force", 15000);
  set("max_force", 15000);
  set("mana", 15000);
  set("max_mana", 15000);
  set("force_factor", 1000);
  set("chat_chance",3);
  set("chat_msg",({
    saying+"�����粻ʶ�Ϸ򣬿������Ϸ�helpһ�±��ǡ�\n",
    saying+"��ʱ��һ�����Ű񹫿����룬�����������½磬ʹaccept��ɡ�\n",
    saying+"�������������һ��������ʱ��ǡ�\n",
    saying+"���������������ȴ��Ϸ��������fight��ս��\n",
    saying+"���񵫻���׼�Ŷ��°�󣬷���̨���ǰݰ�����֮����\n",
    saying+"����̨���°���ɸ�����磬ʹfeast�����ˡ�\n",
    saying+"�����������ط��½�ʹback��ɣ��Ϸ��������͡�\n",
    saying+"��һ������������л��ɢϯ��ʹfinish������ĸ�����׼��\n",
  }));
  setup();
}

int execute_help();
int execute_ask();
int qualified(object me); 
//More than 1/4 of real players with 10k+ experience is required
//to attend the meeting. Modified by Wuliao

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
  add_action("do_confirm", "confirm");
  add_action("do_feast", "feast");
  add_action("do_back", "back");
  add_action("do_finish", "finish");
  set("inquiry", ([
        "here":   "�����������԰�ߴ�������·����ʥ����������۴��д������а������ĸ���������ڴ������ʤ������������\n",
        "?":      (: execute_help() :),
        "help":   (: execute_help() :),
        "���":   (: execute_ask() :),
        "��һ�": (: execute_ask() :),
        "�����": (: execute_ask() :),
        "����":   (: execute_ask() :),
        "�����": (: execute_ask() :),
      ]));
  if (YAOCHI == 0)
  {
    /*
    YAOCHI = __DIR__;
    YAOCHI[strlen(YAOCHI)-4] = 0;
    YAOCHI = YAOCHI + "yaob";
    */
    YAOCHI = "/d/pantao/yaob";
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
    if(!who) return " ";
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
    message_vision ("$N��$nҡҡͷ��"+get_respect(who)+
                    "�����÷�ͬ�½磬������㶯�֣�\n",me,who);
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
    message_vision ("$N��$nҡҡͷ��"+get_respect(who)+
                    "�����÷�ͬ�½磬�����������ɱ�ˣ�\n",me,who);
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

  message_vision ("$N��$nҡҡͷ��"+get_respect(who)+
                  "�����÷�ͬ�½磬���������ʩ������\n",me,who);
  return 1;
}

int do_exert(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg != "sheqi tai bai" &&
      arg != "sheqi tai" &&
      arg != "sheqi bai")
    return 0;

  message_vision ("$N��$nҡҡͷ��"+get_respect(who)+
                  "�����÷�ͬ�½磬���������ʩ�ڹ���\n",me,who);
  return 1;
}

int do_perform(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N��$nҡҡͷ��"+get_respect(who)+
                  "�����÷�ͬ�½磬���������ʩ�⹦��\n",me,who);
  return 1;
}

int do_steal(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N��$nҡҡͷ��"+get_respect(who)+
                  "�����÷�ͬ�½磬���������컯��ʩ�����ԣ�\n",me,who);
  return 1;
}

int do_bian(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N��$nҡҡͷ��"+get_respect(who)+
                  "�����÷�ͬ�½磬���������˱��\n",me,who);
  return 1;
}

int execute_help ()
{
  object who = this_player();
  object me = this_object();

  switch (me->query_temp("pantao/level"))
  {
    case LEVEL_NONE:
    {
      message_vision ("$N��$n˵����"+get_respect(who)+
                      "�����������һ��������ʱ��ǡ�\n",me,who);
      break;
    }
    case LEVEL_ASKED:
    {
      message_vision ("$N��$n˵����"+get_respect(who)+
                      "�������Ϸ�ȥ�����½�ľˮ��������"+
                      "��������սʹfight�����ˡ�\n",me,who);
      break;
    }
    case LEVEL_RANKED:
    {
      message_vision ("$N˵����������������������������ս����"+
                      "���Ϸ�ȥ�����½�ľˮ���������ɡ�\n",me,who);
      message_vision ("$N�ֲ�����������°��ѻ���׼�Ŷ���Ҳ����������"+
                      "ϸ�����ɣ������ɽ�������ս�㹲ȥ����̨�ݰ����硣"+
                      "����̨��ʹfeast�����ˡ�\n",me,who);
      break;
    }
    case LEVEL_FEAST:
    {
      message_vision ("$N��$n˵����"+get_respect(who)+
                      "������ط��½�ʹback��"+
                      "�����⼯��л�繲���½磬ʹfinish������ĸ�����׼��\n",
                      me,who);
      break;
    }
  }
  return 1;
}

void reset_interval ()
{
  interval_set = 0;
}

int execute_ask ()
{
  object who = this_player();
  object me = this_object();

  if (who->query("combat_exp")+who->query("daoxing") < 200000)
  {
    message_vision ("$N��$nҡҡͷ��"+get_respect(who)+
                    "�����ɿͣ�ȴ���в��㣬��������¼������\n",me,who);
    return 1;
  }

  if (me->query_temp("pantao/is_busy"))
  {
    message_vision ("$N��$nҡҡͷ��"+get_respect(who)+
                    "���Ϸ���æ���Է��㡣\n",me,who);
    return 1;
  }

  if(me->query_temp("pantao/level") < LEVEL_ASKED)
  {
    if (interval_set)
    {
      message_vision ("$N��$nҡҡͷ��"+get_respect(who)+
                      "�����ʤ��ʱ��δ�������´������ɡ�\n",me,who);
      return 1;
    }

    message_vision ("$N��$n˵��"+get_respect(who)+
                    "�����ʤ�����з����Ű��������ȷ��ɣ�\n"+
                    "���˴��·�ͬС�ɣ��Ϸ�����������ۣ�"+
                    get_respect(who)+"��Ը����ʹconfirm��\n",me,who);
    me->set_temp("pantao/confirm",1);
    return 1;  
  }
  // LEVEL_ASKED, LEVEL_RANKED
  if(me->query_temp("pantao/level") < LEVEL_FEAST)
  {
    remove_call_out ("continue_asked");
    call_out ("continue_asked",1,me,who);
    return 1;  
  }
  message_vision ("$N��$n˵����"+get_respect(who)+
                  "����һ��Ѿ����硣\n",me,who);
  return 1;
}

int do_confirm ()
{
  object who = this_player();
  object me = this_object();

  if (! me->query_temp("pantao/confirm"))
    return notify_fail("ʲô��\n");

  me->set_temp("pantao/confirm",0);
  message_vision ("$N�ش�Ը�⡣\n",who);

  announce (me,who->query("name")+get_respect(who)+"�����ˣ�\n");
  message_vision ("$N��$n˵����"+get_respect(who)+
                  "���Ϸ����������ۣ������·����ʥ�����������������Ű�"+
                  "�ٱ�����ĸ�������ʤ�������¿ͣ�\n",me,who);
  message_vision ("����Ʈ��$N��ȥ��\n",me);
  //me->set("env/invisibility",9);
  me->set_temp("pantao/reappear",environment(me));
  load_object("/obj/empty");
  me->move("/obj/empty");
  remove_call_out ("make_asked");
  call_out ("make_asked",10,me,who);
  return 1;
}

void make_asked (object me, object who)
{
  int i;
  object *list;

  if (!who ||
      !environment(who) ||
      environment(who) != me->query_temp("pantao/reappear"))
  {
    me->move(me->query_temp("pantao/reappear"));
    message_vision ("����Ʈ�䣬$N����������\n",me);
    return;
  }

  announce (me,"�����ּ�������·����ʥ�������������Ű�����");
  announce (me,"�������֮����ĸ���������Ҵ�������¿ͣ�\n");
  announce (me,"��λ�½��������븰�ᣬʹaccept tai bai�ɣ��Ϸ�������ӭ��\n");

  interval_set = 1;
  call_out ("reset_interval", 28800); // 8h
  me->set_temp("no_return",1);
  me->set_temp("pantao/level",LEVEL_ASKED);
  //me->set("env/invisibility",0);
  me->move(me->query_temp("pantao/reappear"));
  message_vision ("����Ʈ�䣬$N����������\n",me);
  remove_call_out ("continue_asked");
  call_out ("continue_asked",1,me,who);

  me->set_temp("invite","public");
  list = users();
  i = sizeof(list);
  while  (i--)
  {
    reset_eval_cost();
    if (!environment(list[i]))
      continue;
    list[i]->set_temp("accept",0);
  }
  remove_call_out ("inviting");
  call_out ("inviting",1,me);
}

void continue_asked (object me, object who)
{
    if(!who) return;

  message_vision ("$N��$n˵����"+get_respect(who)+
                  "�ɴ��Ϸ�ȥ����λ����"+
                  "�����������������ս��\n",me,who);
  message_vision ("$N�������ϣ�������$nͬ�С�\n",me,who);
  who->set_leader(me);
  me->set_leader(who);
}

void inviting (object me)
{
  int i;
  object *list;

  if (me->query_temp("pantao/level") == LEVEL_NONE)
    return;

  if (DEBUG)
    return;

  remove_call_out ("inviting");
  call_out ("inviting",4+random(4),me);

  if (me->query_temp("pantao/is_busy"))
  {
    return;
  }

  list = users();
  i = sizeof(list);
  while  (i--)
  {
    string here, there;

    reset_eval_cost();
    if (!environment(list[i]))
      continue;
    if (environment(list[i])->query("unit")) // not a room
      continue;
    if (list[i]->is_fighting())
      continue;
    if (list[i]->is_busy())
      continue;
    if (list[i]->query_temp("no_move"))
      continue;
    if (list[i]->is_ghost()) // Checking a ghost or not. 
      continue;
    if (!living(list[i]))
      continue;
    if ((string)list[i]->query_temp("accept")!=me->query("id"))
      continue;

    list[i]->set_temp("accept",0);
    here = (string)environment(me);
    there = (string)environment(list[i]);
    if (here == there)
      continue;

    message_vision("$N˵�������Ժ��Ϸ��ּӭ��"+list[i]->query("name")+
                   "���ᣬ������\n",me);
    list[i]->set_temp("accept",0);
    list[i]->set_temp("pantao/from",there);
    message_vision("һ������Ʈ��$N��ȥ������\n",me);
    //me->move(there);
    message_vision("ֻ��һ������Ʈ�£�̫�׽��Ǵ������߳���\n",list[i]);
    message_vision("̫�׽��Ƕ�$N˵�����Ϸ��ּӭ��$N���ᣡ\n",list[i]);
    message_vision("����ӵ��̫�׽��Ǻ�$N�ڿն��������ȥ������\n",list[i]);
    //me->move(here);
    list[i]->move(here);
    message_vision("�����������콵�䣬$N��$n�����߳���\n",me,list[i]);
    list[i]->set_leader(me);
    break;
  }
}

int execute_approve_fight(object who, object ob)
{
  object *all, *list, *inv;
  int i, j;
  object me = this_object();

  if (who->query("combat_exp")+who->query("daoxing") < 100000)
  {
    message_vision ("$N��$nҡҡͷ��"+get_respect(who)+
                    "���в��㣬�����������������\n",me,who);
    return 0;
  }
  all = users();
  i = sizeof(filter_array(all, (:qualified:))); //modified by wuliao
  list = all_inventory(environment(me));
  j = sizeof(filter_array(list, (:qualified:))) + 30;
  // only interactive players count.

  if ((i/4-j) > 0 && (! DEBUG)) 
  {
    message_vision ("$N��$nҡҡͷ�����μ�����"+chinese_number(i)+"λ���֣�"
                    "�˴�������λ����������"+
                    get_respect(who)+"�ɷ�����"+chinese_number(i/4-j)+
                    "λ���͸��᣿\n",me,who);
    return 0;
  }
  announce (me,"���������"+who->query("name")+"��"+ob->query("name")+
            "��"+environment(me)->query("short")+"���������\n");
  
  me->set_temp("pantao/is_busy",1);
  me->set_leader(0);
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
            "��ս"+who->query("name")+"������ʤ��\n");
  announce (me,"�Ϸ�Ϸ���ּ����"+ob->query("name")+"Ϊ"+
            who->get_honor_str()+"��\n");
  i = ob->query("pantao/wins")+1;
  ob->set("pantao/wins",i);
  i = (10 + MAXPOSITION - who->get_position_int())*(999+random(9))/i;
  ob->add("daoxing",i);
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
  me->set_temp("pantao/current_player",ob->query("id"));
  me->set_temp("pantao/level",LEVEL_RANKED);
  message_vision ("$N����Ц�ݵ�˵������������������������ս����"+
                  "�ʹ˴��Ϸ�ȥ������\n",me);
  message_vision ("$N�ֵ�����ʴ����׼�����°���������$n"+
                  "��ѯ�����ɸ�λ�����������ս��һͬ����̨�ݰ����硣"+
                  "ȥ�˷���̨��ʹfeast��ɡ�\n",me,ob);
  message_vision ("$N�������ϣ�������$nͬ�С�\n",me,ob);
  me->set_leader(ob);
  return 1;
}

void reset_is_busy(object me)
{
  me->set_temp("pantao/is_busy",0);
}

int is_tian_shen (object who)
{
  int i;

  for (i = 1; i <= MAXPOSITION; i++)
  {
    string npc = __DIR__"tian"+sprintf("%d",i);
    object ob = find_object(npc);
    reset_eval_cost();
    if (! ob ||
        ! ob->restore())
      ob = new (npc);
    if (ob->query("current_player") == who->query("id"))
      return 1;
  }
  return 0;
}

int do_feast ()
{
  object me = this_object();
  object who = this_player();

  message_vision("$N����$n������ĸ���硣\n",who,me);
  if (me->query_temp("pantao/level") == LEVEL_FEAST)
  {
    message_vision ("$N˵������һ��Ѿ���ʼ�ˡ�\n",me);
    return 1;
  }
  if (me->query_temp("pantao/level") != LEVEL_RANKED)
  {
    message_vision ("$N˵���������°���δ��׼���Ϸ����Ҿ�����ĸ���"+
                    "$n�ɷ�Ը���ߴ����������"+
                    "����Ӯ�ˣ��Ϸ�����������ʴ����׼��\n",me,who);
    return 1;
  }
  if (! is_tian_shen(who))
  {
    message_vision ("$N˵����$n������Ҳ���ɷ��������������ݰ����磿\n",me,who);
    return 1;
  }
  if (environment(me)->query("short")!="����̨")
  {
    message_vision ("$N�������ɸ�λ�ɷ�ͬȥ����̨�Ȱݰ������磿\n",me);
    return 1;
  }
  message_vision ("$N��$n˵����"+get_respect(who)+
                  "���Ϸ���ͱ�������ĸ�������ʤ�������¿ͣ�\n",me,who);
  message_vision ("����Ʈ��$N��ȥ��\n",me);
  //me->set("env/invisibility",9);
  me->set_temp("pantao/reappear",environment(me));
  load_object("/obj/empty");
  me->move ("/obj/empty");
  remove_call_out ("make_feast");
  call_out ("make_feast",5,me,who);
  return 1;
}

void make_feast (object me, object who)
{
  int i;
  object *list;

  if (!environment(who) ||
      environment(who) != me->query_temp("pantao/reappear"))
  {
    me->move(me->query_temp("pantao/reappear"));
    message_vision ("����Ʈ�䣬$N����������\n",me);
    return;
  }

  announce (me,"��������ʥ�������̨�ݰ�\n");
  announce (me,"��ĸ�����׼������Ҵ�������¿ͣ�\n\n");

  me->set_temp("pantao/level",LEVEL_FEAST);
  me->set_leader(0);
  //me->set("env/invisibility",0);
  me->move(me->query_temp("pantao/reappear"));
  message_vision ("����Ʈ�䣬$N����������\n",me);

  remove_call_out ("execute_start_feast");
  call_out ("execute_start_feast",1,me);
}

void execute_start_feast (object me)
{
  int i;
  object *list;

  message_vision ("$N˵��������λ���͸��Ϸ�ȥ���ر���\n",me);
  me->set_temp("no_return",0);
  //command ("north");
  //command ("north");
  //command ("north");
  //command ("north");
  //command ("north");
  //command ("north");
  //command ("north");
  //command ("north");

  message_vision("ֻ��һ���������������������������𡭡���\n",me);
  list = all_inventory(environment(me));
  i = sizeof(list);
  message_vision("�������ƻ������¡�\n",me);
  while  (i--)
  {
    reset_eval_cost();
    if (!interactive(list[i]))
      continue;

    list[i]->move(YAOCHI);
    message_vision("$N�����������˳�����\n",list[i]);
  }
  message_vision("$N̤�����ƣ�����������ɢ�ˡ�\n",me);
  me->move(YAOCHI);
  me->set_temp("pantao/is_busy",1);
  remove_call_out ("continue_feast");
  call_out ("continue_feast",10,me);
}

void continue_feast (object me)
{

  command ("sigh");

  message_vision ("$N˵������λϢŭ����ĸ�������ڴ�Ƣ���������硣\n",me);
  //message_vision ("$N������һ����˵������ѩ�����ˡ������ȫ��͵���ˣ�\n",me);

  remove_call_out ("give_gifts");
  call_out ("give_gifts",2,me);
  remove_call_out ("bring_girls");
  call_out ("bring_girls",5,me);
  remove_call_out ("auto_activities");
  call_out ("auto_activities",10,me);
  remove_call_out ("auto_gifts");
  call_out ("auto_gifts",20,me);
  remove_call_out ("auto_guests");
  call_out ("auto_guests",30,me);
  remove_call_out ("auto_signs");
  call_out ("auto_signs",40,me);
  remove_call_out ("end_feast");
  call_out ("end_feast",300,me);
  remove_call_out ("execute_auto_finish");
  call_out ("execute_auto_finish",600,me);
}

void give_gifts (object me)
{
  int i;
  object *list;

  list = all_inventory(environment(me));
  i = sizeof(list);
  while  (i--)
  {
    object ob = list[i];
    object xianyao = new ("/d/obj/food/xianyao");
    object xianzhi = new ("/d/obj/food/xianzhi");
    reset_eval_cost();
    if (!interactive(ob))
      continue;
    if (me == ob)
      continue;

    xianyao->move(ob);
    xianzhi->move(ob);
    message_vision("$N��$nһ����"+xianyao->query("name")+
                   "һ���"+xianzhi->query("name")+"��\n",me,ob);
  }
}

void bring_girls (object me)
{
  string *strs = ({
    "���˽���",
    "�߽���ʩ�˸���",
    "����ʩ��",
    "��������ʩ��",
    "����������ʩ�˸���",
  });
  object where = environment(me);
  int i;
  string room_dir;

/*
  room_dir = __DIR__;
  room_dir[strlen(room_dir)-4] = 0;
*/
  room_dir = "/d/pantao/";
  message_vision ("���溰����������Ů����\n",me);
  for (i = 1; i <= 7; i++)
  {
//    string room = room_dir+"ting"+sprintf("%d",i);
    string npc = room_dir+"npc/xiannu"+sprintf("%d",i);
    object ob;

    reset_eval_cost();;
//    me->move(room);
//    ob = present("xian nu",environment(me));

//    if (! ob)
      ob = new (npc);

//    message_vision ("$N���˳�ȥ��\n",ob);
//    ob->set("previous_location",room);
    if(ob->move(where))
      message_vision ("$N"+randomize(strs)+"\n",ob);
  }
//  me->move(where);
}

void auto_activities (object me)
{
  string *strs = ({
    "һ���ɶ��ڸ�������������",
    "��λ�������Ž������ᳪ�����",
    "һ�����������������",
    "�紵������������������",
    "�ƹ�����һЩ�ɾ�",
    "��Ů�˽�����������",
    "һλ���ӽ������������ɻ�",
    "�����ϵ�����Һɢ����һ�����",
    "��Ů�����������������",
    "��Ů�����������ɸ����س�",
    "��Ů��������Ц����Դ����",
    "��Ů�����������츮����ǿ",
    "��Ů���������ƽ��������",
    "��Ů������罺�������Ī˫",
    "��Ů��������������������",
    "��Ů��������Եʳ���Էǳ�",
  });

  if (me->query_temp("pantao/level") != LEVEL_FEAST)
    return;

  message_vision (randomize(strs)+"\n",me);
  remove_call_out ("auto_activities");
  call_out ("auto_activities",20+random(20),me);
}

void auto_gifts (object me)
{
  object where = environment(me);
  object ob, who, gift;
  object *list;
  int i;
  string room_dir;
  
/*
  room_dir = __DIR__;
  room_dir[strlen(room_dir)-4] = 0;
*/
  room_dir = "/d/pantao/";
  if (me->query_temp("pantao/level") != LEVEL_FEAST)
    return;

  list = all_inventory(environment(me));
  for (i = 0; i < 100; i++)
  {
    reset_eval_cost();
    ob = list[random(sizeof(list))];
    if (ob->query("id") == "xian nu")
      break;
    ob = 0;
  }
  if (! ob)
  {
    int j = random(7);
//    string room = room_dir+"ting"+sprintf("%d",j);
    string npc = __DIR__"xiannu"+sprintf("%d",j);

//    me->move(room);
//    ob = present("xian nu",environment(me));

//    if (! ob)

      ob = new (npc);
    if(ob->move(where))
      message_vision ("$N���˹�����\n",ob);
//    me->move(where);
  }
  for (i = 0; i < 100; i++)
  {
    who = list[random(sizeof(list))];
    if (interactive(who))
      break;
    who = 0;
  }
  if (who)
  {
    if (random(2))
      gift = new ("/d/obj/drug/xiantao");
    else
      gift = new ("/d/obj/drug/xianjiu");
    gift->move(who);
    message_vision ("$N��$nһ"+gift->query("unit")+
                    gift->query("name")+"\n",ob,who);
  }
  remove_call_out ("auto_gifts");
  call_out ("auto_gifts",30+random(30),me);
}

void auto_guests (object me)
{
  string name;
  int i;
  string *names = ({
    "������ʦ",
    "��������",
    "�϶�",
    "��������",
    "�ݰ�ʹ��",
    "�ز�������",
    "���޳�",
    "���޳�",
    "����",
    "������������",
    "�Ϻ���������",
    "����������˳",
    "������������",
    "̫���Ͼ�",
    "��Ŵ���",
    "����������",
    "��߸",
    "������",
    "�����",
    "��˽�",
  });

  if (me->query_temp("pantao/level") != LEVEL_FEAST)
    return;

  for (i = 0; i < 100; i++)
  {
    reset_eval_cost();
    name = randomize(names);
    if (! me->query_temp("pantao/invited_"+name))
      break;
    name = "none";
  }
  if (name == "none")
    return;

  me->set_temp("pantao/invited_"+name,1);
  message_vision ("ֻ����ԶԶһ����"+name+"ǰ�����磡"+"\n",me);
  remove_call_out ("continue_guests");
  call_out ("continue_guests",3+random(3),me,name);
  remove_call_out ("auto_guests");
  call_out ("auto_guests",40+random(40),me);
}

void continue_guests (object me, string name)
{
  string msg;
  int i;
  string *msgs = ({
    "�ŷ�������磬�������²������������",
    "ǰ��л�磬�ʹ˸�ǣ�",
    "ר��ǰ�����������������λ���룡",
    "����ǰ����л������ˣ�",
    "�����������������",
    "�ҴҸ���ֻΪл�磬���ܴ�����ʧ���ˣ�",
  });

  if (me->query_temp("pantao/level") != LEVEL_FEAST)
    return;

  message_vision (name+"���˽�����\n",me);
  message_vision (name+"˵����"+name+randomize(msgs)+"\n",me);
  message_vision (name+"���˳�ȥ��\n",me);
}

void auto_signs (object me)
{
  string str;
  string *strs = ({
    "���Զ������ԼԼϼ�����������������ʲôʢ����ᡭ��",
    "�����ƺ���������Ʈ������",
    "���㱿��������ã�������ʲô�ش���ա���",
    "һ����紵�����������Ϸ�����ܵ���������",
    "���ϴ����϶�����������������",
    "������������Ͻ�����������",
  });
  int i;
  object *list;

  if (me->query_temp("pantao/level") != LEVEL_FEAST)
    return;

  if (DEBUG)
    return;

  str = randomize(strs);
  list = users();
  i = sizeof(list);
  while  (i--)
  {
    string here, there;

    reset_eval_cost();
    if (!environment(list[i]))
      continue;
    if (!living(list[i]))
      continue;

    here = (string)environment(me);
    there = (string)environment(list[i]);
    if (here == there)
      continue;

    tell_object(list[i],str+"\n");
  }
  remove_call_out ("auto_signs");
  call_out ("auto_signs",60+random(60),me);
}

void end_feast (object me)
{
  me->set_temp("pantao/is_busy",0);
  message_vision ("$N˵������λ���ͣ�������ط��½�ʹback���ǣ��Ϸ����͡�"+
                  "�����⼯��л�繲���½磬������������ʹfinish"+
                  "����ĸ�����׼��\n",me);
}

int execute_back(object me, object who)
{
  object here = environment(me);
  object there, there1;

  if(!who) return 1;
  
  there = load_object("/d/city/kezhan");
  there1 = load_object("/d/city/kezhan");

  if (!there)
    there = there1;

  if (here == there)
    return 1;

  who->set_temp("accept",0);
  message_vision("ֻ������Ʈ��$N��$n�ڿն���������ȥ������\n",me,who);
  //me->move(there);
  if(!who->move(there1))
      who->move(there1);
  message_vision("ֻ��һ������Ʈ�£�̫�׽��Ǻ�$N�������߳���\n",who);
  message_vision("̫�׽��Ǹ����������ƻ������롣\n",who);
  //me->move(here);
  message_vision("�������Ʒɻأ�$N�������߳���\n",me);
  
  return 1;
}

int do_back(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N����$n������$N�ط���\n",who,me);
  if (me->query_temp("pantao/is_busy"))
  {
    message_vision ("$N��$nҡҡͷ��"+get_respect(who)+
                    "���Ϸ���æ��ʧ���ˡ�\n",me,who);
    return 1;
  }
  execute_back (me,who);
  
  return 1;
}

int do_finish ()
{
  object me = this_object();
  object who = this_player();

  message_vision("$N����$n������ĸл�缯��ط���\n",who,me);
  if (me->query_temp("pantao/is_busy"))
  {
    message_vision ("$N��$nҡҡͷ��"+get_respect(who)+
                    "���Ϸ���æ��ʧ���ˡ�\n",me,who);
    return 1;
  }

  if (me->query_temp("pantao/level") != LEVEL_FEAST)
  {
    message_vision ("$N˵������һ���δ��ʼ���Ϸ����Ҿ�����ĸ���\n",me);
    return 1;
  }
  if (! is_tian_shen(who))
  {
    message_vision ("$N˵����$n������Ҳ���ɷ�������������л�磿\n",me,who);
    return 1;
  }
  if (environment(me)->query("short")!="����")
  {
    message_vision ("$N���������˷����أ����л�磿\n",me);
    return 1;
  }
  message_vision ("$N��$n˵����"+get_respect(who)+
                  "���Ϸ���ͱ�������ĸ���\n",me,who);
  message_vision ("����Ʈ��$N��ȥ��\n",me);
  //me->set("env/invisibility",9);
  me->set_temp("pantao/reappear",environment(me));
  load_object("/obj/empty");
  me->move ("/obj/empty");
  remove_call_out ("make_finish");
  call_out ("make_finish",3,me,who);
  return 1;
}

void make_finish (object me, object who)
{
    if(!who) return;

  if (!environment(who) ||
      environment(who) != me->query_temp("pantao/reappear"))
  {
    me->move(me->query_temp("pantao/reappear"));
    message_vision ("����Ʈ�䣬$N����������\n",me);
    return;
  }

  announce (me,"��Ҵ��л�磬��ĸ�����Ϳͣ�\n\n");

  //me->set("env/invisibility",0);
  me->move(me->query_temp("pantao/reappear"));
  message_vision ("����Ʈ�䣬$N����������\n",me);

  me->delete_temp("pantao");
  me->delete_temp("invite");
  remove_call_out ("execute_finish");
  call_out ("execute_finish",1,me);
}

void execute_auto_finish (object me)
{
  if (me->query_temp("pantao/level") != LEVEL_FEAST)
  {
    return;
  }

  announce (me,"ʱ���ѵ�����Ҵ��л�磬��ĸ�����Ϳͣ�\n\n");

  me->delete_temp("pantao");
  me->delete_temp("invite");
  remove_call_out ("execute_finish");
  call_out ("execute_finish",1,me);
}

int execute_finish (object me)
{
  int i, j;
  object *list;

  if (me == 0)
    me = this_object();
 
  list = all_inventory(environment(me));
  i = sizeof(list);
  while  (i--)
  {
    reset_eval_cost();
    if (!interactive(list[i]))
      continue;
    if (me == list[i])
      continue;

    j = random(100)+1;
    list[i]->add("potential",j);
    tell_object(list[i],"���Ǳ��������"+chinese_number(j)+"�㣡\n"); 
    call_out ("execute_back",i*2,me,list[i]);
  }
  remove_call_out ("send_back_girls");
  call_out ("send_back_girls",1,me);
}

void send_back_girls (object me)
{
  int i;
  object where;
  object *list;

  list = all_inventory(environment(me));
  i = sizeof(list);
  while (i--)
  {
    reset_eval_cost();
    if (interactive(list[i]))
      continue;
    if (list[i]->query("id") != "xian nu")
      continue;
//    if (where = query("previous_location"))
//      list[i]->move(where);
//    else
      destruct (list[i]);
  }
}

int qualified(object me)
{
	if(!interactive(me))
		return 0;
	if(wizardp(me))
		return 0;
    if(me->query("daoxing") < 10000)
		return 0;
	return 1;
}

�
