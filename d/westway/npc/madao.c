// created by snowcat on 4/9/1997
// madao.c

inherit NPC;

void create()
{
  string dir;
  set_name("���", ({"ma dao", "madao", "ma", "dao"}) );
  set("gender", "����" );
  set("age", 22+random(10));
  set("per", 14);
  set("long","һ�������׺ݵ������ר��Ϯ����·����\n");

  set_temp("apply/attack", 30);
  set_temp("apply/defense", 30);
  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("stick", 30);
  set("combat_exp", 15000);
  set("str", 25);
  set("attitude","heroism");
  setup();
  /*
  dir = __DIR__;
  dir[strlen(dir)-4] = 0;
  */
  dir = "/d/westway/";
  carry_object(dir+"obj/mabang")->wield();
  add_money("silver", 2);
}

void init()
{
  object who;
  ::init();
  if (interactive(who = this_player()))
  {
     call_out("asking", 1, who);
  }
}

int accept_object (object who, object ob)
{
  object me;
  me = this_object();

  if ((! ob) ||
       ob->value() < 200) 
  {
    message_vision ("$Nһ���ۣ�����㶫����������ˣ�����\n", me);
    return 1;
  }  
  who->set_temp("has_paid", 2);
  me->remove_all_killer();
  message_vision ("$N�ٺٺټ�����Ц�������õ���\n",me);
  return 1;
}

void asking(object who)
{
  object me;
  me = this_object();

  if (! who || environment(who) != environment())
    return;
  if (! living (me))
    return;

  if ((who && who->query_temp("has_paid") <= 0) 
        && (string)who->query("family/family_name")!="��ׯ��" )
  {
    message_vision ("$N���������$n���һ����ҪǮ����Ҫ����\n",me,who);
    remove_call_out ("warning1");
    remove_call_out ("warning2");
    remove_call_out ("warning3");
    call_out("warning1", 5+random(5), who);
    call_out("warning2", 10+random(5), who);
    call_out("warning3", 15+random(5), who);
    call_out("killing", 25+random(5), who);
  }
  else
  { 
    message_vision ("$N��$nһ���֣������õ���\n",me,who);
    me->remove_all_killer();
  }
}

void warning1(object who)
{
  object me;
  me = this_object();

  if (who &&
      environment(who) == environment(me) &&
      living(me) &&
      who->query_temp("has_paid") <= 0)
  {
    message_vision ("$N�����ȵ������Ǯ��\n",me,who);
  }
}

void warning2(object who)
{
  object me;
  me = this_object();

  if (who &&
      environment(who) == environment(me) &&
      living(me) &&
      who->query_temp("has_paid") <= 0)
  {
    message_vision ("$N�ֺ��м�������Ǯ��������\n",me,who);
  }
}

void warning3(object who)
{
  object me;
  me = this_object();

  if (who &&
      environment(who) == environment(me) &&
      living(me) &&
      who->query_temp("has_paid") <= 0)
  {
    message_vision ("$N���ˣ��㵽�׸�����Ǯ��\n",me,who);
  }
}

void killing(object who)
{
  object me;
  me = this_object();

  if (who &&
      environment(who) == environment(me) &&
      living(me) &&
      who->query_temp("has_paid") <= 0)
  {
    //me->kill_ob(who);
    //use command here...
    command("kill " + who->query("id"));
  }
}

