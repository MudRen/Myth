// created 4/5/1997 by snowcat
#define NAME "С����"
inherit NPC;

int test_player(object who);
int test_player_male (object me);
int test_player_female (object me);
int nuerguo();

void create()
{
  set_name(NAME, ({"xiliang princess", "princess"}));
  set("title", "�������潿��");
  set("gender", "Ů��");
  set("age", 23);
  set("long", "�����������������ɽ���С������\n");
  set("rank_info/respect", "������");
  set("max_kee", 3200);
  set("max_gin", 3200);
  set("max_sen", 2900);
  set("force", 2800);
  set("daoxing", 1000000);
  set("max_force", 1800);
  set("mana", 1800);
  set("max_mana", 1800);
  set("combat_exp", 2000000);
  set("force_factor", 150);
  set_skill("snowsword", 150);
  set_skill("sword", 175);
  set_skill("dragonfight", 175);
  set_skill("unarmed", 175);
  set_skill("dodge", 275);
  set_skill("parry", 275);
  set_skill("dragonstep", 300);
  map_skill("dodge", "dragonstep");
  map_skill("unarmed", "dragonfight");
  map_skill("sword", "snowsword");
  map_skill("parry", "snowsword");
  set("eff_dx",20000);
  set("nkgain",110);
  set("inquiry", ([
        "name": "���Ǽ�į�������������������ɽ���С������\n"+
                "���Ҹ��ɾ���Ҳ����һЩ���",
        "here": "��������ΪŮ������һ��Ҳ�б������׵Ĵ�ͳ��",
        "news": "û����˵������һֱ��Ѱ�����ӽ����",
        "����": "����Ҳֻ����ż����˵�ö��ҡ�",
        "��¶������": "�Ǹ����������е������׸��ˣ�Ҳ�����ں��ҵ�����",
        "�ɾ�": (: test_player_male :),
        "���": (: test_player_male :),
        "����": (: test_player_male :),
        "�и�": (: test_player_male :),
        "marriage": (: test_player_male :),
        "����": (: test_player_female :),
        "company": (: test_player_female :),
        "Ů����": (: nuerguo :),
      ]));
  set("chat_chance",1);
  set("chat_msg",({
         NAME+"˵�����������һֱ�ù������ģ��и���Ѱ�����\n",
         NAME+"̾һ�������Ǹ����į�����Ű���\n",
         NAME+"��˵�������������ǰ�ɸ����������Ρ�\n",
         NAME+"���������¶�������Ǹ����������ѵ�һ����\n",
         NAME+"˵����ǰ��������Ȭ�˸�ˮ��Ҳ�����˲��õĴ��¡�\n",
      }));

  setup();
  carry_object("/d/obj/cloth/pinkskirt")->wear();
  carry_object("/d/obj/cloth/huazheboots")->wear();
  carry_object("/d/obj/misc/necklace")->wear();
  carry_object("/d/obj/weapon/sword/qinghong")->wield();
}

void init()
{
  ::init();
  add_action("do_answer", "answer");
  add_action("do_fight", "fight");
  add_action("do_kill", "kill");
  add_action("do_steal", "steal");
  add_action("do_cast", "cast");
}

void throw (object who, string where)
{
  string dir;

/*
  dir = __DIR__;
  dir[strlen(dir)-4] = 0;  
*/
  dir = "/d/qujing/nuerguo/";
  who->move(dir+where+".c");
  switch (random(4))
  {
    case 0:
      message_vision("$N����������Ů���Ϲ���\n",who);
      break;
    case 1:
      message_vision("������Ů�����ְ˽ŵ�����$N�߹���\n",who);
      break;
    case 2:
      message_vision("һ��޺����У�$N�ü�����Ů�˵������߹���\n",who);
      break;
    case 3:
      message_vision("ֻ��$N���������ر�������Ů���Ϲ���\n",who);
      break;
  }
}

void throws (object who)
{
  message_vision("����δ�䣬���������ѳ����������Ů�ˣ���$N������ߣ�\n",who);
  throw(who,"fronthall");
  throw(who,"entry");
  throw(who,"towna2");
  throw(who,"towna3");
  throw(who,"townb3");
  throw(who,"townc3");
  throw(who,"sanchalu");
  throw(who,"westriver");
  throw(who,"eastriver3");
  message_vision("����һ��ˮ�죬$N�������ҵ��¹ڣ��Ӻ�����ǿ����������\n",who);
  who->interrupt_me();
}

void throw_player (object who)
{
  say(NAME+"���һ�������ˣ���������ʸ��������\n");
  call_out ("throws",1,who);
}

void reject_player (string msg, object who)
{
  say(msg, who);
  
  // mon 2/28/99
  // prevent player uses the rejection to remove the busy one has.
  if(who->is_busy()) return;

  who->start_busy(3,3);
  call_out ("throw_player",1,who);
}

void invite_player (object who)
{
  string dir;

/*
  dir = __DIR__;
  dir[strlen(dir)-4] = 0;  
*/
  dir = "/d/qujing/nuerguo/";
  message_vision("����ļ�������Ů���߽�����ʮ�������ش�ӵ��$N���ߣ�\n",who);
  who->move(dir+"greenyard.c");
  message_vision("����Ů���ǽ�$N�������ʲô��û˵�ʹҴҵ����ˡ�\n",who);
}

void ask_player (object who)
{
  string msg;
  msg = NAME+"��ϲ����"+RANK_D->query_respect(who);

  if (who->query("gender") != "Ů��")
    say(msg+"�����ҵ��ɾ���\n\n");
  else
    say(msg+"������ɢ�ƣ���һλ���\n\n");
  call_out ("ask_condition",1,who);
}

void ask_condition (object who)
{
  string msg;
  msg = NAME+"�����Ը�����";

  say(msg+"��������һ�����������������ڹ���Сס���գ������Ƿ���ʡ�\n");
  say("Ը��Ļ������������ȥ�󹬡�\n");
  say("��Ը��Ļ��������ھͿ���������ս��\n");
  if (who->query("gender") != "Ů��")
    say("������Ӯ���ҵĻ�����Ϳ�������Ȣ��Ϊ�ޣ�"+
        "���������˵Ļ���Ī�������飡\n");
  else
    say("������Ӯ���ҵĻ����㵱����������İ��"+
        "���������˵Ļ���Ī�������飡\n");
  who->set_temp("princess_answer",1);
  tell_object(who,"\n����answer�ش�\n");
}

int test_player(object who)
{
  object queen;
  string msg;
  msg = NAME+"˵������λ"+RANK_D->query_respect(who);

  if (who->query("combat_exp")<2000)
  {
    reject_player (msg+"����ȥ��û��ʲô���У������ʲô���֣�\n",who);
    return 1;
  }  

  if (who->query("obstacle/nuerguo") == "done")
  {
    queen = new (__DIR__"queen");
    queen->refuse_player (who);
    destruct (queen);
    return 1;
  }  

  if (who->query("obstacle/nuerguo") == "stomachache")
  {
    reject_player (msg+"����һˮ̥����Ȼͦ�Ŵ���������ң�\n",who);
    return 1;
  }  

  if (who->query("obstacle/nuerguo") == "marriage")
  {
    say(msg+"�����Ѿ�����������𣿻��ǻغ�Ժȥ�ɣ�\n");
    call_out ("invite_player",1,who);
    return 1;
  }  

  if (who->query("obstacle/nuerguo") == "company")
  {
    say(msg+"�����Ѿ���Ӧ���ҵİ������𣿻�����ȥ��Ժȥ�ɣ�\n");
    call_out ("invite_player",1,who);
    return 1;
  }
    
  call_out ("ask_player",1,who);
  return 1;
}

int test_player_male (object me)
{
  object who;
  string msg;
  who = this_player();
  msg = NAME+"˵������λ"+RANK_D->query_respect(who);

  if (who->query("gender") != "����")
  {
    reject_player (msg+"��������Ͳ����еģ���ʲô��Ц��\n",who);
    return 1;
  }
  return test_player(who);
} 

int test_player_female (object me)
{
  object who;
  string msg;
  who = this_player();
  msg = NAME+"˵������λ"+RANK_D->query_respect(who);

  if (who->query("gender") != "Ů��")
  {
    reject_player (msg+"��������Ͳ���Ů�ģ���ʲô��Ц��\n",who);
    return 1;
  }
  return test_player(who);
} 

void send_to_greenyard (object who)
{
  string msg;
  msg = NAME+"˵������λ"+RANK_D->query_respect(who);

  message_vision (msg+"��ȻԸ�⣬������ȥ��Ժ��Ϣ����ȥ�ɣ�\n",who);
  if (who->query("gender") != "Ů��")
    who->set("obstacle/nuerguo", "marriage");
  else
    who->set("obstacle/nuerguo", "company");
  who->save();
  call_out ("invite_player",1,who);
} 

void fight_player (object who)
{
  message_vision (NAME+"��$N���˵�һЦ���ðɣ����������Ա��ԣ����аգ�\n",who);
  message_vision (NAME+"�ӱ���������һ����ԾƮ��$N��ǰ��\n",who);
  who->set_temp ("princess_fight", 1);
} 

int do_answer(string arg)
{
  object who;

  who = this_player();

  if (! who->query_temp("princess_answer"))
    return notify_fail("ʲô��\n");

  if (!arg)
    return notify_fail("��Ҫ�ش�ʲô��\n");

  who->set_temp("princess_answer",0);
  message_vision("$N�����"+arg+"\n", who);
  if (arg == "Ը��")
    send_to_greenyard (who);
  else if (arg == "��Ը��")
    fight_player (who);
  else
    message_vision (NAME+"��$N����üͷ��\n",who);
  return 1;
}

int accept_fight(object who)
{
  object me;
  me = this_object();

  if (! who->query_temp("princess_fight"))
    return 0;

  who->set_temp("princess_fight",0);
  remove_call_out("check_fight");
  call_out("check_fight", 1, me, who);
  return 1;
}

void player_win (object me, object who)
{
  object queen;
  string msg;
  msg = RANK_D->query_respect(who);

  queen = new (__DIR__"queen");
  queen->announce_success (who,"����սʤС����");
  destruct (queen);
  say (NAME+"̾��һ���������������Ժ�ʤ��ǿ���������ݱ����������ˡ�\n");
  say (msg+"������ո�ǿ�������޷�������������"+msg+"������·���죬��ౣ�أ�\n"); 

}

void player_lose (object me, object who)
{
  string msg;
  msg = RANK_D->query_respect(who);

  say (NAME+"΢΢һЦ���������˸�����ˣ���Ȼ���У�\n");
  say (NAME+"���������������������ȡ����Ȼ��ȥ��������\n");
  call_out ("player_lose_info",2,who);
}

void player_lose_info (object who)
{
  string msg;
  msg = RANK_D->query_respect(who);

  if (random(5) == 0)
    say ("�Ա���С��Ů͵͵˵��������Ӵ������"+msg+
         "�β��Ҹ�����С���������飡\n"); 
}

void check_fight (object me, object who)
{
  int my_kee, whos_kee;
  int my_max_kee, whos_max_kee;

  my_kee = me->query("kee");
  whos_kee = who->query("kee");
  my_max_kee = me->query("max_kee");
  whos_max_kee = who->query("max_kee");

  if (me->is_fighting())
  {
    call_out ("check_fight",2,me,who);
    return;
  }

  if (!present(who, environment(me)))
    return;

// if ((my_kee*100/my_max_kee) <=(whos_kee*100/whos_max_kee))
if ((my_kee*100/my_max_kee) <=10) // xintai 2/8/2001
player_win (me, who);
else player_lose (me, who);

}

int do_fight(string arg)
{
  object who;
  object me;
  who = this_player();
  me = this_object();

  if (me->is_fighting())
  {
    message_vision (NAME+"��$Nҡҡͷ��һ��һ����������Ҫһӵ���ϣ�\n",who);
    return 1;
  }
  
  if (who->query_temp("princess_fight"))
  {
    me->set("kee", me->query("max_kee"));
    me->set("eff_kee", me->query("max_kee"));
    return 0; // can fight
  }

  message_vision (NAME+"��$Nҡҡͷ���������׿��ԣ���ܲ��У�\n",who);
  return 1;
}

int do_cast(string arg)
{
  object who;
  object me=this_object();
  who = this_player();

  if(!arg || present(arg,environment(me))!=me) return 0;

  if (who->query_temp("princess_fight"))
    return 0; // can fight

  message_vision (NAME+"��$N�ȵ���˭�����������ĵģ�\n",who);
  message_vision ("$N�ŵý��°���������˻�ȥ��\n",who);
  return 1;
}

int do_steal(string arg)
{
  object who;
  object me=this_object();
  who = this_player();

  if(!arg || present(arg,environment(me))!=me) return 0;

  message_vision (NAME+"ͻȻ��$N�ȵ����������С͵��ס�֣�\n",who);
  message_vision ("$N�ŵý������˻�ȥ��\n",who);
  return 1;
}

int do_kill(string arg)
{
  object who;
  object me=this_object();
  who = this_player();

  if(!arg || present(arg,environment(me))!=me) return 0;

  message_vision (NAME+"ͻȻ��$N�ȵ�����ı����������ô�ĵ���\n",who);
  message_vision ("$Nһ�����ŵ�̱���ڵء�\n",who);
  return 1;
}

int nuerguo()
{
object who=this_player();
message_vision (NAME+"��$N���˵�һЦ���������Ů������\n",who);
who->delete("obstacle/nuerguo");
return 1;
}
