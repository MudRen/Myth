// created by snowcat on 4/9/1997
// laoren.c

int give_it ();

inherit NPC;

void create()
{
  set_name("��������", ({"lao ren", "lao"}) );
  set("gender", "����" );
  set("age", 81);
  set("long","һλ��Ŀ������������ˡ�\n");

  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set("combat_exp", 10000+random(5000));
  set("str", 35);
  set("per", 45);
  set("attitude","peaceful");
  set("inquiry", ([
        "book" : (: give_it :),
        "guide": (: give_it :),
        "story": (: give_it :),
        "��"   : (: give_it :),
        "��˵" : (: give_it :),
      ]));
  setup();
}

void init()
{
  object who;
  ::init();
  if (interactive(who = this_player()))
  {
     call_out("looking", 2, who);
  }
}

void looking(object who)
{
  object me;
  me = this_object();

  if (! who || environment(who) != environment())
    return;

  message_vision ("$N΢΢�����ۣ�����$nһ�ۡ�\n",me,who);
}

int give_it()
{
  string dir;
  object me;
  object who;
  object story;
  me = this_object();
  who = this_player();

  if (who->query_temp("laoren_has_given"))
  {
    message_vision ("$N������$nҡ��ҡͷ���Ѿ��������ˡ�\n",me,who);
  }
  else
  {
    story = new ("/d/obj/books-nonskill/book-qujing");
    story->move(who);
    message_vision ("$N�ڶ��ڽ����ó�һ�������ݸ�$n��Ȼ�����������ۡ�\n",me,who);
    who->set_temp("laoren_has_given",1);
  }
  return 1;
}


