// by snowcat

inherit NPC;

#include <quest_kl.c>
#include <reporting.c>

int test_player();

void create()
{
  set_name("������", ({"hu jingde", "hu", "jingde"}));
  set("long", "һλ����ս�ۣ�����ׯ����������ֶ�����\n");
  set("title", "��ʮ�����ֶ���");
  set("gender", "����");
  set("age", 60);
  set("per", 35);
  set("attitude", "peaceful");
  set("class", "fighter");
  set("shen_type", 1);
  set("combat_exp", 200000);
  set("daoxing", 400000);

  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set_skill("force", 100);
  set_skill("spells", 100);
  set("max_gin",800);
  set("max_kee",800);
  set("max_sen",800);
  set("max_force",1000);
  set("max_mana",1000);
  set("force_factor",100);
  set("chat_chance",10);
  set("chat_msg",({
    "��������ŭ����ڣ�������ľž��һ�ģ��ȵ���ɱ��\n",
    "��������ŭ����ɱ��������ħ��֣�\n",
    "�����������ž���ľ�����������\n",
    "��������ŭ���ɶ���ն��ɱ����\n",
    "�������˺���һ����ɱ��\n",
    "��������˵����Ҫɨ��һ��ţ������\n",
  }));
  set("inquiry", ([
        "here":   "��������̨Ҳ��ˮ½��Ὣ���ھ��У��������ڴ�Ԥ��������ɱ����ħ��֣�\n",
        "name":   "��ʮ�����ֶ���������Ҳ���ڴ���������ɱ����ħ��֣�\n",
        "kill":   (: test_player() :),
        "��ħ":   (: test_player() :),
        "����":   (: test_player() :),
        "���":   (: test_player() :),
        "ţ��":   (: test_player() :),
        "����":   (: test_player() :),
        "ɱ��":   (: test_player() :),
        "ɱ":   (: test_player() :),
        "ն":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/obj/cloth/zhanpao")->wear();
}

void rewarding (object who);

void init ()
{
  call_out ("check_player",1,this_player());
}

int test_player()
{
  string *strs = ({
    "$NѸ�ٵ�һռ�ԣ�������ľž��һ�Ķ�$n˵����ȥ��$w�����ˣ�\n",
    "$N����һ����$n˵�����Ϸ��ռ��һ�ԣ���֪$w�������Ѿ���ȥȥ����֮ն�ˣ�\n",
    "$N��ͷһ���ԣ���$n˵����$w�����������ȥһ�⽫������֮��\n",
    "$N�����Զ�$n˵�����Ϸ���ȱ��ȥ����$w�����ɷ���һ�ˣ�\n",
    "$Nŭ����ڣ���$n˵����$wΪ��������������ȥ��֮�˽����\n",
    "$N����һռ����ͷ��$n˵�����ã�����ʱ����ȥ��$w��������\n",
    "$Nռ����϶�$n˵����ȥȥ����$wɱ����\n",
  });  
  object me = this_object();
  object who = this_player();
  int *quest_keys;
  string *quest;
  string str;
  int delay;
  int i;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "���Ϸ�����������ƻ��ƣ��β�ȥ���ٸ������������ͣ�\n",me,who);
    return 1;
  }

  if (who->query("quest/pending/kill"))
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "���Ϸ�������ȥ����"+who->query("quest/pending/kill/name")+"��\n",me,who);
    return 1;
  }

  quest_keys = me->query_temp("quest_keys");
  if (! quest_keys)
  {
    quest_keys = sort_quests (quests_kill);
    me->set_temp("quest_keys",quest_keys);
  }
  i = quest_accurate_index (quest_keys, who);
  i = quest_random_index (quest_keys, i, who, "quest/cache/kill");
  if (i == -1)
  {
    message_vision ("$N��$n̾��˵������λ"+RANK_D->query_respect(who)+
                    "�����������˲��٣��Ϸ��������Ժ������ɡ�\n",me,who);
    return 1;
  }
  delay = MAXDELAY * i / sizeof(quest_keys) + DELAY_CONST + uptime();
  quest = quests_kill[quest_keys[i]];
  who->set("quest/pending/kill/index", i);
  who->set("quest/pending/kill/daoxing", quest_keys[i]);
  who->set("quest/pending/kill/name", quest[IDX_NAME]);
  who->set("quest/pending/kill/id", quest[IDX_ID]);
  who->set("quest/pending/kill/time", delay);
  str = strs[random(sizeof(strs))];
  str = replace_string (str, "$w", quest[IDX_NAME]);
  message_vision (str,me,who);
  informing (me,who,str);
  return 1;
}

void check_player (object who)
{
  object me = this_object();
  int t;

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

  if (! who->query("quest/pending/kill"))
    return;

  if (! who->query("quest/pending/kill/done"))
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "���Ϸ�������ȥ����"+who->query("quest/pending/kill/name")+"��\n",me,who);
    return 0;
  }

  t = who->query("quest/pending/kill/time");

  if (t >= uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N��$n��̾�������Ѿ������ˣ�������ô��ɡ�\n",me,who);
    message_vision ("$N�����ֿ���һ����˵����������"+chinese_number((t-uptime())/60+1)+
                    "���Ӻ������ɡ�\n",me,who);
    if (! DEBUG)
      return 0;
    else
      tell_object (who,"NOW DEBUG MODE: �ö�������ֱ���Ͽɡ�\n");
  }
  rewarding (who);
}

void rewarding (object who)
{
  object me = this_object();
  string reason;
  int reward;

  reason = "������֣�������"+who->query("quest/pending/kill/name")+"��";
  message_vision ("$N��$n˵������л��λ"+RANK_D->query_respect(who)+
                  reason+"����Ʒ�пɼ�Ҳ��\n",me,who);
  reward = quest_reward(who, quests_kill, "kill");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/kill/times",1);
  who->add("quest/kill/reward",reward);
  reporting (who,reason, reward, "����");
  who->delete("quest/pending/kill");
  quest_done(who);
}


�
