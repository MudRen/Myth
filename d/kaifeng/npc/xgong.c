// by snowcat 

inherit NPC;

#include <quest_wp.c>
#include <reporting.c>

int test_player();

void create()
{
  set_name("�๫", ({"xiang gong", "xiang", "gong"}));
  set("gender", "����");
  set("title", "����");
  set("age", 80);
  set("per", 25);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 20000);
  set("daoxing", 100000);

  set_skill("unarmed", 20);
  set_skill("dodge", 20);
  set_skill("parry", 20);
  set("max_gin",400);
  set("max_kee",400);
  set("max_sen",400);
  set("max_force",100);
  set("max_mana",100);
  set("force_factor",10);
  set("chat_chance",10);
  set("chat_msg",({
    "�๫ϲ����ɫ��˵�������������������˲��٣��Ҹ�ʱ�������͵����ǡ�\n",
    "�๫�����������������Ʒ�����ڽ������ʹ���\n",
    "�๫���ŵ�˵�������������˴��ʿɷ�Ū��������Ʒ��\n",
    "�๫˵��ʲô������Ҫ�����Ը��������Ҳ��\n",
    "�๫����˵�����ռ��������÷��ദ�á�\n",
    "�๫���Ե����ã���·Ӣ�ۺ��ܶ��׷�ǰ���ױ���\n",
  }));
  set("inquiry", ([
        "here":   "���������ฮҲ���Ϸ���׼�ڴ��ռ�������\n",
        "name":   "��������Ҳ��\n",
        "weapon":   (: test_player() :),
        "����":   (: test_player() :),
        "����":   (: test_player() :),
        "����":   (: test_player() :),
        "�ռ�":   (: test_player() :),
        "����":   (: test_player() :),
        "��":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void rewarding (object who, object ob);

void init ()
{
  call_out ("check_player",1,this_player());
}

int test_player()
{
  string *strs = ({
    "$N������˼��Ȼ���$n˵�����Ϸ���������ȥ��",
    "$N����һ�£���$n˵�����Ϸ���˵������Ҫ",
    "$N��$n˵���������������˴�����˵�ǽ�����Ҫʲô",
    "$N��$n˵�����Ϸ򼴽�ǲ���ͱ���ȥ���ǣ���ȱ",
    "$N��$nһ��ͷ˵�����Ϸ������һ�±����⣬���ֻ���",
    "$N�����$n˵���������Щ�����������㣬����������",
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
                    "���Ϸ�����������ƻ��ƣ��β�ȥ���ٸ������������ͣ�\n",me,who);
    return 1;
  }

  if (who->query("quest/pending/weapon"))
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "���Ϸ���������"+who->query("quest/pending/weapon/name")+"�أ�\n",me,who);
    return 1;
  }

  quest_keys = me->query_temp("quest_keys");
  if (! quest_keys)
  {
    quest_keys = sort_quests (quests_weapon);
    me->set_temp("quest_keys",quest_keys);
  }
  i = quest_accurate_index (quest_keys, who);
  i = quest_random_index (quest_keys, i, who, "quest/cache/weapon");
  if (i == -1)
  {
    message_vision ("$N��$n̾��˵������λ"+RANK_D->query_respect(who)+
                    "�����������˲��٣��Ϸ��������Ժ������ɡ�\n",me,who);
    return 1;
  }
  delay = MAXDELAY * i / sizeof(quest_keys) + DELAY_CONST + uptime();
  quest = quests_weapon[quest_keys[i]];
  who->set("quest/pending/weapon/index", i);
  who->set("quest/pending/weapon/daoxing", quest_keys[i]);
  who->set("quest/pending/weapon/name", quest[IDX_NAME]);
  who->set("quest/pending/weapon/id", quest[IDX_ID]);
  who->set("quest/pending/weapon/time", delay);
  str = strs[random(sizeof(strs))]+quest[IDX_NAME]+
        "��\n��λ"+RANK_D->query_respect(who)+
        "�ܷ���Ϸ��æ��\n";
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

  if (! who->query("quest/pending/weapon"))
    return;

  ob = present (who->query("quest/pending/weapon/id"),who);
  if (! ob || ! ob->query("no_give"))
    return;

  if (who->query("quest/pending/weapon/name") != ob->query("name"))
    return;

  message_vision ("$N��$n��������"+ob->query("name")+"����æ˫�ֽӹ�ȥ��\n",me,who);
  rewarding (who, ob);
  destruct (ob);
}

int accept_object(object who, object ob)
{
  object me = this_object();
  int t;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "���Ϸ�����������ƻ��ƣ��β�ȥ���ٸ������������ͣ�\n",me,who);
    return 0;
  }

  if (! who->query("quest/pending/weapon"))
  {
    message_vision ("$N��$n˵�����Ϸ���Ҫ�����\n",me,who);
    return 0;
  }

  if (ob->is_character()) return 0;
  
  if (who->query("quest/pending/weapon/name") != ob->query("name"))
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "���Ϸ���������"+who->query("quest/pending/weapon/name")+
                    "������ȴ���Ϸ�"+ob->query("name")+"���ȿȡ�\n",me,who);
    return 0;
  }

  if (who->query("quest/pending/weapon/id") != ob->query("id"))
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "���Ϸ���������"+who->query("quest/pending/weapon/name")+
                    "��������ͦ�󣬵�����ͬһ�������Ϸ�Ҫ����("+
                    who->query("quest/pending/weapon/id")+")����������("+
                    ob->query("id")+")��\n",me,who);
    return 0;
  }

  t = who->query("quest/pending/weapon/time");

  if (t >= uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N��$nҡͷ������ô��ͻ����ˣ��Ϸ������м١�\n",me,who);
    message_vision ("$N�ַԸ��������ٻ���"+chinese_number((t-uptime())/60+1)+
                    "����ȥѰѰ��\n",me,who);
    if (! DEBUG)
      return 0;
    else
      tell_object (who,"NOW DEBUG MODE: ���๫Ҫ�¶�����\n");
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

  reason = "�����Ϳ�Ѱ��"+ob->query("name")+"��";
  message_vision ("$N��$n˵������л��λ"+RANK_D->query_respect(who)+
                  reason+"�Ϸ�м�������\n",me,who);
  reward = quest_reward(who, quests_weapon, "weapon");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/weapon/times",1);
  who->add("quest/weapon/reward",reward);
  reporting (who,reason, reward, "����");
  who->delete("quest/pending/weapon");
  quest_done(who);
}



�
