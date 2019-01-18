// by snowcat 12/9/1997

inherit NPC;

int test_player ();

void create()
{
  set_name("����", ({"guo wang", "wang", "king"}));
  set("long", "���ù��������������ۣ���̬ׯ�ϡ�\n");
  set("title", "���ù�");
  set("gender", "����");
  set("age", 50);
  set("per", 25);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 200000);
  set("daoxing", 100000);

  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set("max_gin",800);
  set("max_kee",800);
  set("max_sen",800);
  set("max_force",1000);
  set("max_mana",1000);
  set("force_factor",120);
  set("eff_dx",15000);
  set("nkgain",90);
  set("inquiry", ([
    "name" : "��������һ��֮��Ҳ��������һ������",
    "here" : "���ù�Ҳ��",
    "����" : "���ù�Ҳ��",
    "���ù�" : "���ù�Ҳ��",
    "����" : (: test_player :),
    "����" : (: test_player :),
    "����" : (: test_player :),
    "princess" : (: test_player :),
  ]));
  setup();
  set_temp("no_return",1);
  carry_object("/d/obj/cloth/longpao")->wear();
  carry_object("/d/qujing/tianzhu/obj/zuanjie")->wear();
}

int test_player ()
{
  object me = this_object();
  object who = this_player();

  if (who->query("combat_exp") < 10000)
  {
    message_vision ("$N��$n˵������������в��㣬���Ի��������\n",me,who);
    message_vision ("\n$N�����ҷԸ��˼��䡣\n",me);
    message_vision ("��λ�����ټ�����ò�ض�$Nһ��ͷ��ӵ��$N�߳���\n",who);
    who->move("/d/qujing/tianzhu/zhaoyang");
    who->move("/d/qujing/tianzhu/wumen");
    message_vision ("�������߽����š�\n",who);
    return 1;
  }
  if (who->query("obstacle/tianzhu")=="done")
  {
    message_vision ("$N��$n˵����Ŷ�����������Ϊ�β�Ը����ȡ����\n",me,who);
    return 1;
  }
  if (! who->query_temp("obstacle/tianzhu_thrown"))
  {
    message_vision ("$N��$n˵����������Ҳ��Ȼ�������������\n",me,who);
    message_vision ("\n$N�����ҷԸ��˼��䡣\n",me);
    message_vision ("��λ��λ�ټ�����ò�ض�$Nһ��ͷ��ӵ��$N�߳���\n",who);
    who->move("/d/qujing/tianzhu/zhaoyang");
    who->move("/d/qujing/tianzhu/wumen");
    message_vision ("�������߽����š�\n",who);
    return 1;
  }
  if (who->query_temp("obstacle/tianzhu_killed"))
  {
    object junji = present ("jun ji",environment(me));

    message_vision ("$N��$n˵���������ͿҲ������������Ů��\n",me,who);
    if (! junji)
    {
      message_vision ("\n$N��ֵ��������󳼺��ڣ�\n",me);
      return 1;
    }
    message_vision ("\n$N��$n�Ը��˼��䡣\n",me,junji);
    remove_call_out ("following");
    call_out ("following",5,me,junji,who);
    return 1;
  }
  message_vision ("$N��$n˵��������β��󹬰ݼ�������\n",me,who);
  return 1;
}

void following (object me, object junji, object who)
{
  object taijian1 = present ("tai jian 1",environment(me));
  object taijian2 = present ("tai jian 2",environment(me));

  message_vision ("\n$N���˵�ͷ��\n",junji);
  message_vision ("$N��$n˵�����ɷ������ȥѰ������\n",junji,who);
  junji->command_function ("follow "+who->query("id"));
  me->command_function ("follow "+who->query("id"));
  me->set("my_saver",who);
  if (taijian1)
    taijian1->command_function ("follow "+who->query("id"));
  if (taijian2)
    taijian2->command_function ("follow "+who->query("id"));
}

void announce_success (object who)
{//disabled announce and reward...
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/tianzhu") == "done")
    return;
  i = random(600);
  who->add("obstacle/number",1);
  who->set("obstacle/tianzhu","done");
  who->add("daoxing",i+4000);
  command("chat "+who->query("name")+"���ù���ս�������Ȼ����ù�����");
  command("chat "+who->query("name")+"˳������������һ�أ�");
  tell_object (who,"��Ӯ����"+chinese_number(4)+"��"+
              chinese_number(i/4)+"��"+
              chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  who->save();
}

�
