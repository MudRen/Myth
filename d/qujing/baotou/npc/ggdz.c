// rewritten by snowcat on 4.12.1997

inherit NPC;

int move_player();

void create()
{
  set_name("�Źֵ���", ({"guguai diaozuan", "diaozuan", "zuan"}));
  set("gender", "����");
  set("age", 20);
  set("attitude", "friendly");
  set("combat_exp", 150000);
  set("daoxing", 200000);

  set("per", 25);
  set_skill("dodge", 60);
  set("max_sen",600);
  set("max_gee",600);
  set("max_gin",600);
  set("force",800);
  set("max_force",800);
  set("max_mana",800);
  set("force_factor",25);
  set_skill("unarmed",60);
  set_skill("parry",60);
  set_skill("dodge",60);
  setup();

  set("inquiry", ([
       "here": "����Ǳ�ͷɽ�������ǻ��ڶ�Ҳ��\n",
       "��ͷɽ": "��ͷɽ��������ǻ��ڶ���\n",
       "���ڶ�": (: move_player :),
       "dong": (: move_player :),
       "name": "�Źֵ��ꡣ\n",
      ]));
  carry_object("/d/qujing/baotou/obj/cloth1")->wear();
  carry_object("/d/qujing/baotou/obj/weapon1")->wield();

}

int move_player()
{
  object me = this_object();
  object who = this_player();

  message_vision ("$N����$nһ�ۡ�\n",me,who);
  if (who->query("combat_exp") < 10000)
  {
    message_vision ("$Nҡҡͷ�����в�����ȥ����ȥ���á�\n",me);
    return 1;
  }

  if (! who->query_temp("apply/name") ||
      who->query_temp("apply/name")[0] != "����Ź�")
  {
    message_vision ("$Nҡҡͷ�����ϵ��㣬���ϵ��㡣\n",me);
    return 1;
  }
 
  message_vision ("$N˵��$n�����Ϳ��Ҳ���ֵ���һ�žͰ����߽����\n",me,who);
  message_vision ("˵��$N����һ�ţ�$n˳������һԾ��\n",me,who);
  who->move("/d/qujing/baotou/dongwai");
  message_vision ("����һ���ȷ紵����$N�е�һ��ͻ��������ͷ�Ρ�\n",who);
  who->set("mana",0);
  return 1;
}

�