// by snowcat 

inherit NPC;

#include <quest_fd.h>
#include <quest_gv.h>
#include <reporting.h>

int test_player();

void create()
{
  set_name("ʥ��", ({"sheng bei", "sheng", "bei"}));
  set("long", "һλ�������ۣ�����������ƵĴ�ʦ��\n");
  set("title", "��ʦ");
  set("gender", "����");
  set("age", 100);
  set("per", 35);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 200000);
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
    "ʥ����ʦ̾�������ֶ����ġ�\n",
    "ʥ����ʦ���������˵���������������֣����˳�ҹ����Ҳ��\n",
    "ʥ����ʦ˵��������ˮ�����֣�ʹ��Ҳ��\n",
    "ʥ����ʦ̾�Ե�������֮�£��ж��������Դ���ˮ�����֮��Ҳ��\n",
    "ʥ����ʦ˵��������֮��Ҳ��\n",
    "ʥ����ʦ˵�����޲����������������Խ�˷�֮��Ҳ��\n",
  }));
  set("inquiry", ([
        "here":   "��������̨Ҳ��ˮ½��Ὣ���ھ��У�����ʦ�ڴ�Ԥ����������������������\n",
        "name":   "ʥ����ʦ���ڴ���������������������\n",
        "give":   (: test_player() :),
        "����":   (: test_player() :),
        "����":   (: test_player() :),
        "����":   (: test_player() :),
        "����":   (: test_player() :),
        "����":   (: test_player() :),
        "����":   (: test_player() :),
        "��":   (: test_player() :),
        "��":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/obj/cloth/xianpao")->wear();
}

void rewarding (object who);

void init ()
{
  call_out ("check_player",1,this_player());
}

int test_player()
{
  string *strs = ({
    "$N����һ��ǩ����$n˵���������������֣���������ȥ��$w�͵�$o��\n",
    "$N��$n���ͷ˵�����Ϸ������һǩ��֪��$w���ѣ����͵�$oȥ��\n",
    "$N��$n˵�����������ã��Ϸ�ռǩ��֪$w�ּ���$o��\n",
    "$N����Ӻ���ž�س��һǩ�������ض�$n˵������$w��Ҫ$o��\n",
    "$N���ͷ��˳�ֽ����е�ǩ�򿪣���̾������$w������$oҲ��\n",
    "$N�Ӵ�ǩ��ȡ��һǩ��$n˵�����������ѣ���ȥ��$w�͵�$o��\n",
    "$N������ǩһ������$n˵����ǩԻ����$w����$o��\n",
    "$Nһ��ǩ��$n˵�����²��˳���ȥ��$w�͵�$o��\n",
  });  
  object me = this_object();
  object who = this_player();
  int *quest_keys;
  int *food_keys;
  string *quest;
  string *food;
  string objectname, objectid, str;
  int delay;
  int i, j;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "���Ϸ�����������ƻ��ƣ��β�ȥ���ٸ������������ͣ�\n",me,who);
    return 1;
  }

  if (who->query("quest/pending/give"))
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "���Ϸ�������ȥ��"+who->query("quest/pending/give/name")+
                    "��"+who->query("quest/pending/give/objectname")+"��\n",me,who);
    return 1;
  }

  quest_keys = me->query_temp("quest_keys");
  food_keys = me->query_temp("food_keys");
  if (! quest_keys)
  {
    quest_keys = sort_quests (quests_give);
    food_keys = sort_quests (quests_food);
    me->set_temp("quest_keys",quest_keys);
    me->set_temp("food_keys",food_keys);
  }
  i = quest_accurate_index (quest_keys, who->query("combat_exp"));
  i = quest_random_index (quest_keys, i, who, "quest/cache/give");
  if (i == -1)
  {
    message_vision ("$N��$n̾��˵������λ"+RANK_D->query_respect(who)+
                    "�����������˲��٣��Ϸ��������Ժ������ɡ�\n",me,who);
    return 1;
  }
  delay = MAXDELAY * i / sizeof(quest_keys) + 120 + uptime();
  quest = quests_give[quest_keys[i]];
  if (sscanf(quest[IDX_OBJ],"%s(%s)",objectname,objectid) != 2)
  {
    j = random(30);
    food = quests_food[food_keys[j]];
    objectname = food[IDX_NAME];
    objectid = food[IDX_ID];
  }
  who->set("quest/pending/give/index", i);
  who->set("quest/pending/give/daoxing", quest_keys[i]);
  who->set("quest/pending/give/name", quest[IDX_NAME]);
  who->set("quest/pending/give/id", quest[IDX_ID]);
  who->set("quest/pending/give/objectname", objectname);
  who->set("quest/pending/give/objectid", objectid);
  who->set("quest/pending/give/time", delay);
  str = strs[random(sizeof(strs))];
  str = replace_string (str, "$w", quest[IDX_NAME]);
  str = replace_string (str, "$o", objectname);
  message_vision (str,me,who);
  informing (me, who, str);
  return 1;
}

void check_player (object who)
{
  object me = this_object();
  int t;

  if (!visible(who))
    return;

  if (! who || environment(who)!=environment(me))
    return;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "�������ƻ��ƣ����ٸ������������ͣ�\n",me,who);
    return;
  }

  if (! who->query("quest/pending/give"))
    return;

  if (! who->query("quest/pending/give/done"))
  {
    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "���Ϸ���˵������ȥ��"+who->query("quest/pending/give/name")+
                    "��"+who->query("quest/pending/give/objectname")+"���²��˳�Ҳ��\n",me,who);
    return 0;
  }

  t = who->query("quest/pending/give/time");

  if (t > uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N��$n��̾�������Ѿ������ˣ�������ô��ɡ�\n",me,who);
    message_vision ("$N����ǩ�ֶ���һ�£�˵����ǩ��˵�����û���"+chinese_number((t-uptime())/60+1)+
                    "���ӡ�\n",me,who);
    if (! DEBUG)
      return 0;
    else
      tell_object (who,"NOW DEBUG MODE: ��ʥ��ֱ���Ͽɡ�\n");
  }
  rewarding (who);
}

void rewarding (object who)
{
  object me = this_object();
  string reason;
  int reward;

  reason = "����֮����Ϊ"+who->query("quest/pending/give/name")+
           "��ȥ"+who->query("quest/pending/give/objectname")+"��";
  message_vision ("$N��$n˵������л��λ"+RANK_D->query_respect(who)+
                  reason+"����Ʒ�пɼ�Ҳ��\n",me,who);
  reward = quest_reward(who, quests_give, "give");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/give/times",1);
  who->add("quest/give/reward",reward);
  reporting (who,reason, reward, "����");
  who->delete("quest/pending/give");
  call_out ("quest_done",1,who);
}


