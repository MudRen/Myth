// by snowcat oct 22 1997

inherit NPC;

void create()
{
  set_name("������ʿ", ({"wei shi", "shi"}));
  set("gender", "����");
  set("combat_exp", 200000);
  set("age", 30);
  set("per", 25);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",60);
  set("max_gin",600);
  set("max_kee",600);
  set("max_sen",600);
  set("max_force",800);
  set("max_mana",800);
  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set_skill("force", 80);
  set_skill("spells", 80);
  setup();
  carry_object("/d/obj/armor/tongjia")->wear();
  carry_object("/d/obj/weapon/spear/tieqiang")->wield();
}

void init ()
{
  object ob = this_player();
  object me = this_object();

  call_out("greeting", 1, ob);
}

void greeting(object ob)
{
  if( !ob || environment(ob) != environment() ) return;
  if (ob && interactive(ob))
  {
    if (! ob->query_temp("weishi_kill"))
      message_vision ("$N�ȵ��������޷����죬�ô����أ�\n",this_object());
    this_object()->kill_ob(ob);
    ob->set_temp("weishi_kill",1);
  }
}

