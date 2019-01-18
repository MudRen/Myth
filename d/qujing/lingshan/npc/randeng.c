//Cracked by Roath
// snowcat 12 14 1997

inherit NPC;

int give_book ();

void create()
{
  set_name("ȼ�ƹŷ�", ({ "randeng gufo", "randeng", "gufo" }));
  set("title", "��ɽ");
  set("gender", "����");
  set("age", 1000);
  set("attitude", "peaceful");
  set("str",40);
  set("per",40);
  set("max_kee", 3000);
  set("max_gin", 3000);
  set("max_sen", 3000);
  set("force", 3000);
  set("max_force", 3000);
  set("force_factor", 100);
  set("max_mana", 3000);
  set("mana", 3000);
  set("mana_factor", 100);
  set("combat_exp", 1500000);
  set("daoxing", 5000000);

  set_skill("literate", 120);
  set_skill("spells", 120);
  set_skill("buddhism", 120);
  set_skill("unarmed", 120);
  set_skill("jienan-zhi", 120);
  set_skill("dodge", 120);
  set_skill("lotusmove", 120);
  set_skill("parry", 120);
  set_skill("force", 120);
  set_skill("lotusforce", 120);
  set_skill("staff", 120);
  set_skill("lunhui-zhang", 120);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  map_skill("parry", "lunhui-zhang");
  map_skill("staff", "lunhui-zhang");
  set("chat_chance_combat", 80);
  set("chat_msg_combat", ({
   (: cast_spell, "bighammer" :),
  }) );
  set("inquiry", ([
    "book" : (: give_book :),
    "jing" : (: give_book :),
    "qujing" : (: give_book :),
    "��" : (: give_book :),
    "ȡ��" : (: give_book :),
    "����" : (: give_book :),
  ]) );

  setup();
  carry_object("/d/obj/cloth/jia_sha")->wear();
}

int give_book()
{
  object me = this_object();
  object who = this_player();
  object book;

  if (! who->query("obstacle/reward"))
  {
    message_vision ("$N��$nҡ��ҡͷ�����Ȼ�ȥ���úù���������ȡ����\n",me,who);
    return 1;
  }
  if (me->query_temp("given_book"))
  {
    message_vision ("$N��$nҡ��ҡͷ�������Ѹ����ˣ��ȵ������ɡ�\n",me,who);
    return 1;
  }
  book = new ("/d/obj/book/qujing");
  command ("nod");
  message_vision("$N��$nһ��"+book->query("name")+"��\n",me,who);
  if(!book->move(who)) {
      destruct(book);
  }
  command ("give "+who->query("id")+" book");
  me->set_temp("given_book",1);
  call_out("reset_give",180);
  return 1;
}

void reset_give ()
{
  object me = this_object();
  me->set_temp("given_book",0);
}


