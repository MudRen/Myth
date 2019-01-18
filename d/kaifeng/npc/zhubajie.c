inherit NPC;

#include <quest_fd.c>
#include <reporting.c>

int test_player();

void create()
{
  set_name("��˽�", ({ "zhu bajie", "zhu", "bajie" }));
  set("age", 600);
  set("gender", "����");
  set("long", "�ٺ٣�����������ʶ����\n");
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 10);
  set("combat_exp", 1200000);
  set("daoxing", 2000000);

  set("max_kee", 1500);
  set("max_sen", 1500);
  set("max_force", 1500);
  set("force", 1500);
  set("force_factor", 150);
  set("mana_factor", 150);
  set_skill("unarmed", 90);
  set_skill("dodge", 60);
  set_skill("parry", 60);
  set_skill("rake", 150);
  set_skill("force", 80);
  set_skill("spells", 80);
  set_skill("baguazhou", 80);
  set_skill("yanxing-steps", 70);
  set_skill("skyriver-rake", 180);
  map_skill("force", "lengquan-force");
  map_skill("spells", "baguazhou");
  map_skill("rake", "skyriver-rake");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "yanxing-steps");
  set("chat_chance",5);
  set("chat_msg",({
    "��˽��ֺǺǵ�˵��������������������������ʳ��Ҳ��\n",
    "��˽�����˵�����·���ˮ���ˣ�����õ��ȼü���\n",
    "��˽�˵��������ҪѰ���������Ƽ��ȣ�������������˧��Ʒ��Ʒ����\n",
    "��˽�˵������������̰�죬��������ո����磬��ƽ�����Ҳ�ܳ������ʡ�\n",
    "��˽����������˵����������Ϊ�Լ����������ռ�������ʳ���ô����˶�����������\n",
    "��˽�Ť����ȥ���������Ľ����ર�઴����������\n",
    "��˽���������ˮͰ������ƺ����˹��˵ع�����ȥ��\n",
  }));
  set("inquiry", ([
        "here":   "��������˧��Ҳ�����������������̫�������ڴ˿�����ר����ʳ����ҵ��\n",
        "name":   "��˽䣬˭�˲�֪Ҳ��\n",
        "food":   (: test_player() :),
        "��ʳ":   (: test_player() :),
        "����":   (: test_player() :),
        "����":   (: test_player() :),
        "����":   (: test_player() :),
        "ʳ��":   (: test_player() :),
        "��ˮ":   (: test_player() :),
        "��":   (: test_player() :),
        "��":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/kaifeng/obj/jiuchipa")->wield();
  carry_object("/d/obj/armor/tongjia")->wear();
}

void rewarding (object who, object ob);

void init ()
{
  call_out ("check_player",1,this_player());
}

int test_player()
{
  string *strs = ({
    "$N������˼�ص��ͷ��$n˵������������������˴ո����磬��ȱ",
    "$N��$n˵�����������Ĵ�Ѱ��������ζ���ȣ���Ҫ��",
    "$N��$n˵�����������·���ˮ�֣��м���������Ҫʲô",
    "$N��$n˵�������ǿ͵����ڿ��⸮�ϣ�������һ�����������Ҵ�Ѱʲô",
    "$N��$n��ͷ˵����ˮ½��ἴ���������·��ʦ���ᣬ��˵�з�ʦ��Ҫʲô",
    "$N��$nһ��ͷ˵����������ȼü�����˵����Ҫ",
    "$N����˵�����˵������ð�������Ҹ�ʲôʲô",
  });  
  string str;
  object me = this_object();
  object who = this_player();
  int *quest_keys;
  string *quest;
  int delay;
  int i;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "���������������ƻ��ƣ��β�ȥ���ٸ������������ͣ�\n",me,who);
    return 1;
  }

  if (who->query("quest/pending/food"))
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "����������������æ�ҵ�"+
		    who->query("quest/pending/food/name")+"�أ�\n",me,who);
    return 1;
  }

  quest_keys = me->query_temp("quest_keys");
  if (! quest_keys)
  {
    quest_keys = sort_quests (quests_food);
    me->set_temp("quest_keys",quest_keys);
  }
  i = quest_accurate_index (quest_keys, who);
  i = quest_random_index (quest_keys, i, who, "quest/cache/food");
  if (i == -1)
  {
    message_vision ("$N��$n̾��˵������λ"+RANK_D->query_respect(who)+
                    "�����������˲��٣������������Ժ������ɡ�\n",me,who);
    return 1;
  }
  delay = MAXDELAY * i / sizeof(quest_keys) + DELAY_CONST + uptime();
  quest = quests_food[quest_keys[i]];
  who->set("quest/pending/food/index", i);
  who->set("quest/pending/food/daoxing", quest_keys[i]);
  who->set("quest/pending/food/name", quest[IDX_NAME]);
  who->set("quest/pending/food/id", quest[IDX_ID]);
  who->set("quest/pending/food/time", delay);
  str = strs[random(sizeof(strs))]+quest[IDX_NAME]+
        "��\n��λ"+RANK_D->query_respect(who)+
        "�ɷ�������������跨��ȥ��Ū����\n";
  message_vision (str,me,who);
  informing (me,who,str);
  return 1;
}

void check_player (object who)
{
  object me = this_object();
  object ob;

  if (!who || !visible(who))
      return;

  if (! who || environment(who)!=environment(me))
    return;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "�������ƻ��ƣ����ٸ������������ͣ�\n",me,who);
    return;
  }

  if (! who->query("quest/pending/food"))
    return;

  ob = present (who->query("quest/pending/food/id"),who);
  if (! ob)
    return;
  if (! ob->query("no_give"))
    return;

  if (who->query("quest/pending/food/name") != ob->query("name"))
    return;

  message_vision ("$N��$n��������"+ob->query("name")+"����Ͻ����ֽӹ�ȥ��\n",me,who);
  rewarding (who, ob);
  destruct (ob);
}

int accept_object(object who, object ob)
{
  object me = this_object();
  int t;

/*
  if (! ob->query("food_remaining") &&
      ! ob->query("liquid/remaining"))
  {
     message_vision ("$Nҡҡͷ������������ֻ��Ҫ�Եĺȵġ�\n",me);
     return 0;
  }
*/

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "���������������ƻ��ƣ��β�ȥ���ٸ������������ͣ�\n",me,who);
    return 0;
  }

  if (! who->query("quest/pending/food"))
  {
    message_vision ("$N��$n˵���������������ʲô����������̰��Ҳ���ܲ���֮��Ҳ��\n",me,who);
    return 0;
  }

  if(ob->is_character()) return 0;

  if (who->query("quest/pending/food/name") != ob->query("name"))
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "��������������æ�ҵ�"+
		    who->query("quest/pending/food/name")+
                    "����ȴ����"+ob->query("name")+"���⡭��\n",me,who);
    return 0;
  }

  if (who->query("quest/pending/food/id") != ob->query("id"))
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "������������"+who->query("quest/pending/food/name")+
                    "��������ͦ�󣬵�����ͬһ��������Ҫ����("+
                    who->query("quest/pending/food/id")+")����������("+
                    ob->query("id")+")��\n",me,who);
    return 0;
  }

  t = who->query("quest/pending/food/time");

  if (t >= uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N��$nҡͷ������ô��ͻ����ˣ�������Ҫ�ٻ���\n",me,who);
    message_vision ("$N�ַԸ��������ٻ���"+chinese_number((t-uptime())/60+1)+
                    "����ȥѰѰ��\n",me,who);
    if (! DEBUG)
      return 0;
    else
      tell_object (who,"NOW DEBUG MODE: ������Ҫ�¶�����\n");
  }
  rewarding (who, ob);
  call_out ("destruct_ob",1,ob);
  return 1;
}

void destruct_ob (object ob)
{
  destruct (ob);
}

void rewarding (object who, object ob)
{
  object me = this_object();
  string reason;
  int reward;

  reason = "Ϊ��������Ѱ��"+ob->query("name")+"��";
  message_vision ("$N��$n˵������л��λ"+RANK_D->query_respect(who)+
                  reason+"����Ϊ�������������츣�ۣ�\n",me,who);
  reward = quest_reward(who, quests_food, "food");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/food/times",1);
  who->add("quest/food/reward",reward);
  reporting (who,reason, reward, "����");
  who->delete("quest/pending/food");
  quest_done(who);
}


�
