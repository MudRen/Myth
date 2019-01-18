// by snowcat 

inherit NPC;

#include <quest_ak.c>
#include <reporting.c>

string *strs = ({
    "$Nȼ��һ�������һ������$n˵�����������죬����ȥ�ݼ�$w��ѯ���й�$oһ�¡�\n",
    "$N���������ȼ��$n˵�����Ϸ�������ڣ���֪��$w֪��$o֮�£����ɷ�ȥ�����\n",
    "$N����������һ�ݣ�ת���$n˵�����ɷ�ȥ�ݼ�$w������֪$oһ�£�\n",
    "$N�����ȼ����$n˵������������������$oһ�°ݷ�$w���뾡�綯��Ҳ��\n",
    "$N��$n˵�����Ϸ�������ڣ���ȱ��ȥ�ݷ�$w����֪$o֮�¡�\n",
    "$Nȼ����ϣ���ͷ��$n˵������֪�ɷ�ȥ�ݼ�$w��̽��$oһ�¡�\n",
    "$N������л���������һ�ݣ��ٶ�$n˵����������������ȥ�ݼ�$w����֪$o֮�¡�\n",
  });  

// mon 3/22/99
string get_message(string str1, string str2)
{
    string str;
    string *msg1=({"$Nȼ��һ�������һ������$n˵�����������죬����ȥ"});
    string *msg2=({"�ݼ�","����","�ʺ�","�ݷ�","���","����","����","����",
	    "�ʺ�һ��","�ݷ�һ��","�ݼ�һ��","�ʺ�һ��","����һ��","���һ��",
	    "����һ��","����һ��","�ݷ�һ��","����һ��","�ݷ�һ��","����һ��",
	    "�ݼ��ݼ�","�ʺ��ʺ�","�ݷðݷ�","��������"});
    string *msg3=({"��˳·","����","������","��һ��","������",
	    "��","����",});
    string *msg4=({"̽��","����","����","����","̽��","��ѯ","֪̽","Ѱ��",
	           "̽��","����","��֪","̽��","����","����","��̽","����",
	    "̽��̽��","Ѱ��Ѱ��","��̽��̽","���̽��","һ��֪̽","�������",
	    "̽���й�","��̽�й�","�����й�","��ѯ�й�","֪̽�й�","̽���й�",
            "̽������","��̽����","��������","��ѯ����","֪̽����","̽�ʹ���",
	    "�����й�","���ʹ���","�����й�","�������","�����й�","���ʹ���",
	    "̽��̽��","��������","̽��̽��","�����й�","�����й�"});
    string *msg5=({"һ��","֮��","����Ϣ","�����","������",});
    string *msg6=({"��","��","������",});
    
    if(random(10)<3)
      str = strs[random(sizeof(strs))];
    else {
	str=msg1[random(sizeof(msg1))]+
	    msg2[random(sizeof(msg2))]+"$w"+
	    msg3[random(sizeof(msg3))]+
	    msg4[random(sizeof(msg4))]+"$o"+
	    msg5[random(sizeof(msg5))]+
	    msg6[random(sizeof(msg6))]+"\n";
    }
    str = replace_string (str, "$w", str1);
    str = replace_string (str, "$o", str2);
    return str;
}

void show_message(object who)
{
    string str;

    if(!who) return;
    if (! who->query("quest/pending/ask"))
	return;
    str=who->query("quest/pending/ask/message");
    if(!str) 
      message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
                    "���Ϸ�������ȥ��"+who->query("quest/pending/ask/name")+
                    "ѯ��"+who->query("quest/pending/ask/topic")+"һ����\n",
		    this_object(),who);
    else
      message_vision(str,this_object(),who);
}

int test_player();

void create()
{
  set_name("�¹���", ({"chen guangrui", "chen", "guangrui"}));
  set("long", "�¹���������֮�������������������״Ԫ��\n");
  set("title", "�������");
  set("gender", "����");
  set("age", 50);
  set("per", 35);
  set("attitude", "peaceful");
  set("class", "scholar");
  set("shen_type", 1);
  set("combat_exp", 40000);
  set("daoxing", 100000);

  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("literate", 180);
  set_skill("parry", 50);
  set_skill("force", 50);
  set_skill("spells", 50);
  set("max_gin",400);
  set("max_kee",400);
  set("max_sen",400);
  set("max_force",400);
  set("max_mana",400);
  set("force_factor",20);
  set("chat_chance",10);
  set("chat_msg",({
    "�����ʦ˵�������������ġ�\n",
    "�����ʦ��������������ˣ������Ӧ�ġ�\n",
    "�����ʦ˵�����������ͣ���ˮ½���ǰ֮����Ҳ��\n",
    "�����ʦ̾�Ե����������ͣ���������֮���Ҳ��\n",
    "�����ʦ˵�����˷�����Ҳ��\n",
    "�����ʦ˵����������棬������������ʿ��\n",
  }));
  set("inquiry", ([
        "here":   "��������̨Ҳ��ˮ½��Ὣ���ھ��У���״Ԫ�ڴ�Ԥ�������Լ������͡�\n",
        "name":   "����֮���¹���Ҳ���ڴ������������͡�\n",
        "ask":   (: test_player() :),
        "����":   (: test_player() :),
        "����":   (: test_player() :),
        "����":   (: test_player() :),
        "����":   (: test_player() :),
        "��ʿ":   (: test_player() :),
        "����":   (: test_player() :),
        "��":   (: test_player() :),
        "��":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/obj/cloth/changpao")->wear();
}

void rewarding (object who);

void init ()
{
  call_out ("check_player",1,this_player());
}

int test_player()
{
  string *acks = ({
    "֪���ˡ�\n",
    "����ͻᶯ�������Ȼذɡ�\n",
    "�õġ�\n",
    "��л���ã������ȥ�졣\n",
    "�ã������Ͼ�ȥ׼����\n",
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

  if (who->query("quest/pending/ask"))
  {
      call_out("show_message",1,who);

//    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
//                    "���Ϸ�������ȥ��"+who->query("quest/pending/ask/name")+
//                    "ѯ��"+who->query("quest/pending/ask/topic")+"һ����\n",me,who);
    return 1;
  }

  quest_keys = me->query_temp("quest_keys");
  if (! quest_keys)
  {
    quest_keys = sort_quests (quests_ask);
    me->set_temp("quest_keys",quest_keys);
  }
  i = quest_accurate_index (quest_keys, who);
  i = quest_random_index (quest_keys, i, who, "quest/cache/ask");
  if (i == -1)
  {
    message_vision ("$N��$n̾��˵������λ"+RANK_D->query_respect(who)+
                    "�����������˲��٣��Ϸ��������Ժ������ɡ�\n",me,who);
    return 1;
  }
  delay = MAXDELAY * i / sizeof(quest_keys) + DELAY_CONST + uptime();
  quest = quests_ask[quest_keys[i]];
  who->set("quest/pending/ask/index", i);
  who->set("quest/pending/ask/daoxing", quest_keys[i]);
  who->set("quest/pending/ask/name", quest[IDX_NAME]);
  who->set("quest/pending/ask/id", quest[IDX_ID]);
  who->set("quest/pending/ask/topic", quest[IDX_OBJ]);
  who->set("quest/pending/ask/acknowledge", acks[random(sizeof(acks))]);
  who->set("quest/pending/ask/time", delay);
  
  str=get_message(quest[IDX_NAME], quest[IDX_OBJ]);
  who->set("quest/pending/ask/message",str);

//  str = strs[random(sizeof(strs))];
//  str = replace_string (str, "$w", quest[IDX_NAME]);
//  str = replace_string (str, "$o", quest[IDX_OBJ]);
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

  if (! who->query("quest/pending/ask"))
    return;

  if (! who->query("quest/pending/ask/done"))
  {
      call_out("show_message",1,who);
//    message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)+
//                    "���Ϸ���˵����ȥ�ݼ�"+who->query("quest/pending/ask/name")+
//                    "����֮"+who->query("quest/pending/ask/topic")+"һ����\n",me,who);
    return;
  }

  t = who->query("quest/pending/ask/time");

  if (t >= uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N��$n��̾�������Ѿ������ˣ�������ô��ɡ�\n",me,who);
    message_vision ("$N����һ����˵�������㻹��"+chinese_number((t-uptime())/60+1)+
                    "���Ӳ�ȼ������ʱ�������ɡ�\n",me,who);
    if (! DEBUG)
      return 0;
    else
      tell_object (who,"NOW DEBUG MODE: �ó¹���ֱ���Ͽɡ�\n");
  }
  rewarding (who);
}

void rewarding (object who)
{
  object me = this_object();
  string reason;
  int reward;

  reason = "������ͣ���"+who->query("quest/pending/ask/topic")+
           "һ�°ݼ���"+who->query("quest/pending/ask/name")+"��";
  message_vision ("$N��$n˵������л��λ"+RANK_D->query_respect(who)+
                  reason+"����Ʒ�пɼ�Ҳ��\n",me,who);
  reward = quest_reward(who, quests_ask, "ask");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/ask/times",1);
  who->add("quest/ask/reward",reward);
  reporting (who,reason, reward, "����");
  who->delete("quest/pending/ask");
  quest_done(who);
}


�
