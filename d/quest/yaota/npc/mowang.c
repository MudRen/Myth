// modified by kuku for yaota task  2002/12

inherit NPC;

void create()
{
  set_name("Сħ��", ({ "xiaomo wang", "wang","moguai" }));
  set("title", "�޶���");   
  set("long", "һλ��Ŀ�ΰ�����ޱȵ�ħ�����������ɷ�ĵ����㡣\n");
  set("gender", "����");
  set("age", 70);
  set("attitude", "peaceful"); 
  set("class", "yaomo");
  set("str",100);
  set("per", 20);
  set("cor", 40); 
  set("con", 40); 
  set("int", 40); 
  set("spi", 40); 
  set("cps", 40); 
  set("kar", 40); 
  set("max_kee", 7700);
  set("max_gin", 7700);
  set("max_sen", 7700);
  set("force", 10000);
  set("max_force", 10000);
  set("force_factor", 300);
  set("max_mana", 10000);
  set("mana", 10000);
  set("mana_factor", 500);
  set("combat_exp", 125000000);
  set("daoxing", 150000000);
  set_skill("spells", 680);
  set_skill("spear",700);
  set_skill("wuyue-spear",700);
  set_skill("stick", 660);
  set_skill("dali-bang", 660);
  set_skill("unarmed", 660);
  set_skill("moyun-shou", 660);
  set_skill("dodge", 620);
  set_skill("moshenbu", 620);
  set_skill("parry", 660);
  set_skill("force", 680);
  set_skill("huomoforce", 660);
  set_skill("pingtian-dafa", 680);
  map_skill("force", "huomoforce");
  map_skill("spells", "pingtian-dafa");
  map_skill("stick", "dali-bang");
  map_skill("spear","wuyue-spear");
  map_skill("parry", "wuyue-spear");
  map_skill("unarmed", "moyun-shou");
  map_skill("dodge", "moshenbu");

  set("nb_heads",30);
  create_family("���ƶ�", 2, "��");
  set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        (: perform_action,"spear", "fengchan" :),
        (: cast_spell, "sanmei" :), 
        }) ); 

  setup();
        carry_object("/d/9ct/zb/tianjia")->wear();
        carry_object("/d/longzhu/weapon/spear")->wield();
}

void destruct_me (object me)
{
  destruct (me);
}

int check_heads (object me, object ob)
{
  int nb_heads = query("nb_heads")-1;
    object head;

  me->set("nb_heads",nb_heads);
  if (! ob)
    return nb_heads;
  if (nb_heads <= 0)
    return nb_heads;
  
        head = new ("/d/quest/yaota/obj/head"); 
  head->move(environment(me));
  return nb_heads;
}

void die ()
{
  object me = this_object();
  object ob = query_temp("last_damage_from");  
  set_temp("last_killed_by",ob);

  if (check_heads (me, ob) > 0)
  {
    set("kee", 7700);
    set("gin", 7700);
    set("sen", 7700);
    set("eff_kee", 7700);
    set("eff_gin", 7700);
    set("eff_sen", 7700);
    set("force", 10000);
    set("mana", 10000);
    message_vision ("\nֻ��Сħ�����˴�һ��ҡҡ�λ������һ��ͷ����\n",me);
    if (ob)
      message_vision ("\n$N�����ӵ�����$n���𹥻���\n",me,ob);
    return;
  }

  message_vision ("�������ˣ�$N��һ���������Ҳ��\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",1,me);
}

void unconcious ()
{
  die ();
}

int accept_fight(object ob)
{
  ob->apply_condition("killer", 100);
  kill_ob(ob);
  ob->kill_ob(this_object());
  return 1;
}

void kill_ob (object ob)
{
  object me = this_object();
  object where = environment (me);
  
  set_temp("my_killer",ob);
  call_out ("checking",1,me,ob);  
  ::kill_ob(ob);
}

void checking (object me, object ob)
{
  if (me->is_fighting())
  {
    remove_call_out ("checking");  
    call_out ("checking",1,me,ob);  
  }
  else
  {
    int i = 50 - ob->query("kar");

    if (i < 10)
      i = 10;
    me->set("nb_heads",i+random(10));
  }
}
