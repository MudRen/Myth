// by snowcat 

inherit NPC;

#include <quest_am.c>
#include <reporting.c>

int test_player();

void create()
{
  set_name("����", ({"xiang po", "xiang", "po"}));
  set("gender", "Ů��");
  set("title", "����");
  set("age", 75);
  set("per", 28);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 15000);
  set("daoxing", 50000);

  set_skill("unarmed", 10);
  set_skill("dodge", 25);
  set_skill("parry", 25);
  set("max_gin",300);
  set("max_kee",300);
  set("max_sen",300);
  set("max_force",100);
  set("max_mana",100);
  set("force_factor",10);
  set("chat_msg",({
    "���Ÿ��˵�˵���๫Ҳ˵������������˲��٣��ɽ������˽����׻����͵����ǡ�\n",
    "����˵�����ʹ�����˵�����ฮ�ռ��˲��ٺÿ��׻��ߡ�\n",
    "������˵����κ����Ҳ˵�ϴ��͵Ŀ��׻����ﲻ���ϳ�Ʒ��\n",
    "����˵����Щ���׻��߿��Լ��Ը�����\n",
    "����˵�����ฮ�������׻��ߣ��������˺���Ҳ��\n",
    "�������Ե������������Ŀ��ײ�ȱ��ȫ������Ŭ��������\n",
  }));
  set("inquiry", ([
        "here":   "���������ฮҲ������ڴ�ר���ռ����ס�\n",
        "name":   "����֮��Ҳ��\n",
        "armor":   (: test_player() :),
        "���׻���":   (: test_player() :),
        "����":   (: test_player() :),
        "����":   (: test_player() :),
        "�ռ�":   (: test_player() :),
        "����":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
}

void rewarding (object who, object ob);

void init ()
{
  call_out ("check_player",1,this_player());
}

int test_player()
{
  string *strs = ({
    "$N�����$n˵�������������׼������ȥ��",
    "$Nϸ����һ�¶�$n˵����κ�����л���˵�Ǿ���������Ҫʲô",
    "$N��$n˵������˵�����б������߷���Ҫ",
    "$N��$n��ͷ˵�����๫��˵�ˣ����������ʲô",
    "$N��$nһ��ͷ˵����������ȱЩ",
    "$N�����$n˵�����ɷ���ฮѰ��",
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

  if (who->query("quest/pending/armor"))
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "�������������"+who->query("quest/pending/armor/name")+"�أ�\n",me,who);
    return 1;
  }

  quest_keys = me->query_temp("quest_keys");
  if (! quest_keys)
  {
    quest_keys = sort_quests (quests_armor);
    me->set_temp("quest_keys",quest_keys);
  }
  i = quest_accurate_index (quest_keys, who);
  i = quest_random_index (quest_keys, i, who, "quest/cache/armor");
  if (i == -1)
  {
    message_vision ("$N��$n̾��˵������λ"+RANK_D->query_respect(who)+
                    "�����������˲��٣�����������Ժ������ɡ�\n",me,who);
    return 1;
  }
  delay = MAXDELAY * i / sizeof(quest_keys) + DELAY_CONST + uptime();
  quest = quests_armor[quest_keys[i]];
  who->set("quest/pending/armor/index", i);
  who->set("quest/pending/armor/daoxing", quest_keys[i]);
  who->set("quest/pending/armor/name", quest[IDX_NAME]);
  who->set("quest/pending/armor/id", quest[IDX_ID]);
  who->set("quest/pending/armor/time", delay);
  str = strs[random(sizeof(strs))]+quest[IDX_NAME]+
        "��\n��λ"+RANK_D->query_respect(who)+
        "�ܷ���ฮ��æ��\n";
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

  if (! who->query("quest/pending/armor"))
    return;

  ob = present (who->query("quest/pending/armor/id"),who);
  if (! ob || ! ob->query("no_give"))
    return;

  if (who->query("quest/pending/armor/name") != ob->query("name"))
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
                    "���������������ƻ��ƣ��β�ȥ���ٸ������������ͣ�\n",me,who);
    return 0;
  }

  if (! who->query("quest/pending/armor"))
  {
    message_vision ("$N��$n˵�����ฮ����Ҫ�����\n",me,who);
    return 0;
  }

  if (ob->is_character()) return 0;

  if (who->query("quest/pending/armor/name") != ob->query("name"))
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "�������������"+who->query("quest/pending/armor/name")+
                    "������ȴ�����"+ob->query("name")+"����ѽѽ��\n",me,who);
    return 0;
  }

  if (who->query("quest/pending/armor/id") != ob->query("id"))
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "�������������"+who->query("quest/pending/armor/name")+
                    "��������ͦ�󣬵�����ͬһ���������Ҫ����("+
                    who->query("quest/pending/armor/id")+")����������("+
                    ob->query("id")+")��\n",me,who);
    return 0;
  }

  t = who->query("quest/pending/armor/time");

  if (t >= uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N��$nҡͷ������ô��ͻ����ˣ���������м١�\n",me,who);
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

  reason = "�����Ϳ�Ѱ��"+ob->query("name")+"��";
  message_vision ("$N��$n˵������л��λ"+RANK_D->query_respect(who)+
                  reason+"���м�������\n",me,who);
  reward = quest_reward(who, quests_armor, "armor");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/armor/times",1);
  who->add("quest/armor/reward",reward);
  reporting (who,reason, reward, "����");
  who->delete("quest/pending/armor");
  quest_done(who);
}




�
