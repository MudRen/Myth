// by snowcat 

inherit NPC;

#include <quest_ms.c>
#include <reporting.c>

int test_player();

void create()
{
  set_name("����", ({"xiang lan", "xiang", "lan"}));
  set("gender", "Ů��");
  set("age", 28);
  set("per", 28);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 5500);
  set_skill("unarmed", 45);
  set_skill("dodge", 45);
  set_skill("parry", 45);
  set_skill("force", 45);
  set_skill("spells", 45);
  set_skill("baihua-zhang", 45);
  set_skill("moondance", 45);
  set_skill("moonshentong", 45);
  map_skill("spells", "moonshentong");
  map_skill("unarmed", "baihua-zhang");
  map_skill("force", "moonforce");
  map_skill("spells", "moonshentong");
  set("max_gin",400);
  set("max_kee",400);
  set("max_sen",400);
  set("max_force",200);
  set("max_mana",200);
  set("force_factor",20);
  set("chat_chance",10);
  set("chat_msg",({
    "��������һЦ�������챦�ɲ��١�\n",
    "�������һЦ˵�����������˶�Ҳ��\n",
    "����˵�����۽磬��Ҳ��Ҳ��\n",
  }));
  set("inquiry", ([
        "here":   "���˸�����ͤ��Ҳ�������ڴ��ռ������챦��\n",
        "name":   "�߼�С������Ҳ��\n",
        "cloth":   (: test_player() :),
	"�챦":   (: test_player() :),
        "ļ��":   (: test_player() :),
        "��":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/obj/cloth/pinkskirt")->wear();
  carry_object("/d/obj/cloth/shoes")->wear();
}

void rewarding (object who, object ob);

void init ()
{
  call_out ("check_player",1,this_player());
}

int test_player()
{
  string *strs = ({
    "$N��$nһЦ����������������Ҫ",
    "$N��$n������Ц�����������ã�����ļ�裬��˵���˴����ܷ�Ѱ��",
    "$N��$n˵����Ŷ�����ˣ������������һ��ʲô",
    "$N��$n��ͷЦ��˵����лл����������������",
    "$N΢Ц�Ŷ�$nһ��ͷ˵���������������Ƿ���",
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
                    "����������������ƻ��ƣ��β�ȥ���ٸ������������ͣ�\n",me,who);
    return 1;
  }

  if (who->query("quest/pending/cloth"))
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "�����ﻹ��������"+who->query("quest/pending/cloth/name")+"�أ�\n",me,who);
    return 1;
  }

  quest_keys = me->query_temp("quest_keys");
  if (! quest_keys)
  {
    quest_keys = sort_quests (quests_misc);
    me->set_temp("quest_keys",quest_keys);
  }
  i = quest_accurate_index (quest_keys, who);
  i = quest_random_index (quest_keys, i, who, "quest/cache/cloth");
  if (i == -1)
  {
    message_vision ("$N��$n̾��˵������λ"+RANK_D->query_respect(who)+
                    "�����������˲��٣����￴�������Ժ������ɡ�\n",me,who);
    return 1;
  }
  delay = MAXDELAY * i / sizeof(quest_keys) + DELAY_CONST + uptime();
  quest = quests_misc[quest_keys[i]];
  who->set("quest/pending/cloth/index", i);
  who->set("quest/pending/cloth/daoxing", quest_keys[i]);
  who->set("quest/pending/cloth/name", quest[IDX_NAME]);
  who->set("quest/pending/cloth/id", quest[IDX_ID]);
  who->set("quest/pending/cloth/time", delay);
  str = strs[random(sizeof(strs))]+quest[IDX_NAME]+
        "��\n��λ"+RANK_D->query_respect(who)+
        "�ܷ����������취��\n";
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

  if (! who->query("quest/pending/cloth"))
    return;

  ob = present (who->query("quest/pending/cloth/id"),who);
  if (! ob || ! ob->query("no_give"))
    return;

  if (who->query("quest/pending/cloth/name") != ob->query("name"))
    return;

  message_vision ("$N��$n��������"+ob->query("name")+"��Ц����æ���˹�ȥ��\n",me,who);
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
                    "����������������ƻ��ƣ��β�ȥ���ٸ������������ͣ�\n",me,who);
    return 0;
  }

  if (! who->query("quest/pending/cloth"))
  {
    message_vision ("$N��$n˵����������ʱ����Ҫ�����\n",me,who);
    return 0;
  }

  if (ob->is_character()) return 0;
  
  if (who->query("quest/pending/cloth/name") != ob->query("name"))
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "������˵����Ҫ"+who->query("quest/pending/cloth/name")+
                    "������������"+ob->query("name")+"��������档\n",me,who);
    return 0;
  }

  if (who->query("quest/pending/cloth/id") != ob->query("id"))
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "����������Ҫ"+who->query("quest/pending/cloth/name")+
                    "��������ͦ�󣬵�����ͬһ����������Ҫ����("+
                    who->query("quest/pending/cloth/id")+")����������("+
                    ob->query("id")+")��\n",me,who);
    return 0;
  }

  t = who->query("quest/pending/cloth/time");

  if (t >= uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N��$nҡͷ������ô��ͻ����ˣ�������Ҫ���Ҳ��\n",me,who);
    message_vision ("$N�ַԸ��������ٻ���"+chinese_number((t-uptime())/60+1)+
                    "����ȥѰѰ��\n",me,who);
    if (! DEBUG)
      return 0;
    else
      tell_object (who,"NOW DEBUG MODE: �ù���Ҫ�¶�����\n");
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

  reason = "��"+me->query("name")+"Ѱ��"+ob->query("name")+"��";
  message_vision ("$N��$n˵������л��λ"+RANK_D->query_respect(who)+
                  reason+"����ø����ģ�\n",me,who);
  reward = quest_reward(who, quests_misc, "cloth");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/cloth/times",1);
  who->add("quest/cloth/reward",reward);
  reporting (who,reason, reward, "����");
  who->delete("quest/pending/cloth");
  quest_done(who);
}




