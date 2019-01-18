// by snowcat

inherit NPC;

void create()
{
  set_name("κ��", ({ "wei zheng", "wei", "zheng" }));
  set("title", "ة��");
  set("gender", "����");
  set("age", 60);
  set("per", 30);
  set("combat_exp", 300000);
  set("daoxing", 800000);

  set_skill("force", 80);
  set_skill("spells", 80);
  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set("gin", 3000);
  set("max_gin", 3000);
  set("kee", 3000);
  set("max_kee", 3000);
  set("sen", 3000);
  set("max_sen", 3000);
  set("force", 1000);
  set("max_force", 1000);
  set("mana", 1000);
  set("max_mana", 1000);
  set("force_factor", 80);
  setup();
  carry_object("/d/obj/cloth/jinpao")->wear();
  carry_object("/d/kaifeng/obj/sijuan")->wear();
}

void init ()
{
  object me = this_object();
  object who = this_player();

  if (! wizardp(who) &&
      interactive(who))
  {
    object where = environment(me);
    
    if (! where->valid_player(who))
      message_vision ("$N��$n˵����������������"+RANK_D->query_respect(who)+
                      "��������Ҵ�Ҳ��\n",me,who);
    else 
      command ("hi "+who->query("id")); 
    if (who->query("env/wimpy") > 0)
    {
      who->set("env/wimpy",0);
      message_vision ("$N��$n˵����������ɱ���˽�ǣ��Ϸ����㽫����ϵ��(wimpy)�����ˡ�\n",me,who);

    }
  }
}

void die ()
{
  object me = this_object();

  message_vision ("\n���´������йٵ�������$N����δ����\n",me);
  message_vision ("\n$N��ΡΡ�شӵ���˦������������\n",me);
  set("kee", 3000);
  set("sen", 3000);
}

void unconcious()
{
  die();
}

void accept_fight (object ob)
{
  object me = this_object();

  message_vision ("$N��æ����˵���Ϸ������࣬���򣬲���Ҳ��\n",me);
}

void kill_ob (object ob)
{
  object me = this_object();

  message_vision ("$N��æ����˵���Ϸ������࣬���򣬲���Ҳ��\n",me);
  me->remove_all_killer();
  all_inventory(environment(me))->remove_killer(me);
}
�