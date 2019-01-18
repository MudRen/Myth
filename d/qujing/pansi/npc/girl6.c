// created 11/20/1997 by snowcat

inherit NPC;

void create()
{
  set_name("����", ({ "jin lian", "jin", "lian" }));
  set("title", "�߽���");   
  set("long", "һλ��ϼ���촽��ü���޵���Ů�ӡ�\n");
  set("gender", "Ů��");
  set("age", 20);
  set("attitude", "heroism");
  set("per", 30);
  set("max_kee", 500);
  set("max_gin", 500);
  set("max_sen", 500);
  set("force", 500);
  set("max_force", 500);
  set("force_factor", 60);
  set("max_mana", 500);
  set("mana", 500);
  set("mana_factor", 60);
  set("combat_exp", 350000);
  set("daoxing", 400000);

  set_skill("spells", 40);
  set_skill("dao", 40);
  set_skill("unarmed", 60);
  set_skill("puti-zhi", 65);
  set_skill("dodge", 50);
  set_skill("jindouyun", 50);
  set_skill("qianjun-bang", 40);
  set_skill("parry", 55);
  set_skill("force", 60);
  set_skill("wuxiangforce", 40);
  set_skill("staff", 40);
  map_skill("spells", "dao");
  map_skill("unarmed", "puti-zhi");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  map_skill("parry", "qianjun-bang");
  setup();
  carry_object("/d/obj/cloth/nichang")->wear();
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  if (ob && 
      ! ob->query_temp("obstacle/pansi_killed_"+me->query("name")))
  {
    ob->set_temp("obstacle/pansi_killed_"+me->query("name"),1);
    ob->add_temp("obstacle/pansi_killed",1);
  }
  message_vision ("\n$N����һ������ͷ����֩�뾫��ԭ�Ρ�\n",me);
  me->set_name("֩�뾫", ({"zhizhu jing", "zhizhu", "jing"}));
  ::die();
}

void unconcious ()
{
  die ();
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  call_out ("hurting",random(5)+5,me,ob);  
  ::kill_ob(ob);
}

void hurting (object me, object ob)
{
  string *msgs = ({
    "$N����һ��¶����Ƥ��һ�ɴִֵİ�˿�罫������$nһ����\n",
    "$N�ǿ��·�����һֻͦ���ɹɰ�˿����$n��\n",
    "$N�����½ǣ������������һ�ɴְ�˿��$N��ȥ��\n",
  });
  string *strs = ({
    "( $N��ʱһ���ĵأ�ɲ�Ǽ�ˤ�����ذ��� )\n",
    "( $N����������ڵ��ϣ���ҡ�������������� )\n",
    "( $N�Ļ����̣������ŵ����ڵ��ϣ� )\n",
  });
  int damage;

  if (! me)
    return;

  if (! ob)
    return;

  if (environment(ob) != environment(me))
    return;
 
  message_vision ("\n"+msgs[random(sizeof(msgs))],me,ob);
  message_vision (strs[random(sizeof(strs))],ob);
  damage = ob->query("max_kee")/(8+random(4));
  ob->add("kee",-damage); 
  ob->add("sen",-damage); 

  call_out ("hurting",random(10)+10,me,ob);  
}
�