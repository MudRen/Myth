// created 4/4/1997 by snowcat

inherit NPC;

void create()
{
  switch (random(3))
  {
    case 0:
    case 1:
    {
      set_name("�ٸ�", ({"woman"}));
      set("age", 27);
      break;
    }
    case 2:
    {
      set_name("���긾Ů", ({"woman"}));
      set("age", 38);
      break;
    }
  }
  set("gender", "Ů��");
  set("combat_exp", 5000);
  set_skill("unarmed", 10);
  set_skill("dodge", 10);
  set_skill("parry", 10);
  set("chat_chance",30);
  set("chat_msg",({(: random_move :)}));

  setup();
  carry_object("/d/qujing/nuerguo/obj/skirt")->wear();
  add_money ("coin", 10+random(200));  
}

void init()
{
  object ob;

  ::init();
  if (interactive(ob = this_player()) && !is_fighting())
  {
    remove_call_out("greeting");
    call_out("greeting",1,ob);
  }
}

void classified_greeting(object me)
{
  string name = query("name");

  if (me->query("obstacle/nuerguo") == "done")
    return;

  if (me->query("obstacle/nuerguo") == "marriage")
  {
    message_vision (name+"��$N˵����Ҷ���������Ļ���������ȥ��������\n",me);
      return;
  }  

  if (me->query("obstacle/nuerguo") == "company")
  {
    message_vision (name+"�ϳ���$N��˵����Ӵ���������ڵ��������ء�\n",me);
      return;
  }  

  if (me->query("obstacle/nuerguo") == "stomachache")
  {
    message_vision (name+"����$N���̲�ס˵�������ƣ������е��\n",me);
      return;
  }
  
  if (me->query("gender") == "Ů��")
    message_vision (name+"����$Nһ�ۣ��ԳԵ�Ц��������\n",me);
  else
    message_vision (name+"ָ��$NЦ������������һ������Ҫȥ�������ġ�\n",me);
}

void greeting(object ob)
{
  if (!ob || environment(ob) != environment())
    return;
  switch (random(6))
  {
     case 0:
       classified_greeting (ob);
       break;
  }
}

