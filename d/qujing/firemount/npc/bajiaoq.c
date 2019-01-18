// created 4/25/1997 by snowcat
#include <ansi.h>

inherit NPC;

void create()
{
  string dir;

  set_name("�Ž���", ({"bajiao guai", "qiannian guai", "guai"}));
  set("title", "ǧ��");
  set("gender", "����");
  set("age", 1200+random(600));
  set("con", 20);
  set("cor", 20);
  set("int", 20);
  set("per", 20);
  set("long", "ǧ��Ž��֡�\n");
  set("attitude", "peaceful");
  set("combat_exp", 1200000);
  set("daoxing", 500000);

  set_skill("dodge", 200);
  set_skill("parry", 200);
  set_skill("force", 200);
  set_skill("spells", 200);
  set_skill("unarmed", 200);
  set_skill("whip", 200);
  set("max_gin", 4500);
  set("max_kee", 4500);
  set("max_sen", 4500);
  set("force", 4500);
  set("max_force", 4500);
  set("mana", 4500);
  set("max_mana", 4500);
  //set_weight(300000);
  setup();
/*
  dir = __DIR__;
  dir[strlen(dir)-4] = 0;
*/
  dir = "/d/qujing/firemount/";
  carry_object(dir+"obj/bian")->wield();
  carry_object(dir+"obj/skirt")->wear();

}

void equalize_gifts (object ob, object me)
{
  // encourage players to have equalized gifts
  ob->set("con",(me->query("spi")+me->query("con"))*1/1);
  ob->set("cor",(me->query("kar")+me->query("cor"))*1/1);
  ob->set("cps",(me->query("per")+me->query("cps"))*1/1);
  ob->set("int",(me->query("str")+me->query("int"))*1/1);
}

int allow_split()
{
  object me = this_object();
  object who = this_player();

  me->set_temp("split",1);
  message_vision ("$Nһ㶣��漴���صس�$n��ͷһЦ��\n",me,who);
  return 1;
}

void init()
{
  object ob;

  ::init();
  /*
  set("inquiry", ([
       "������": (: allow_split :),
      ]));
      */
}

int accept_fight (object me)
{
  object ob = this_object();
  equalize_gifts (ob, me);
  ob->setup();
  if (! ob->query_temp("split"))
    return 1;
  if (! ob->query("triplicate"))
  {
    object ob0, ob1, ob2, ob3;
    //string str = file_name(ob);
    string str = __DIR__"bajiaoq";
    ob0 = present("guai 2",environment(me));
    if (ob0)
      destruct (ob0);
    ob0 = present("guai 2",environment(me));
    if (ob0)
      destruct (ob0);
    ob0 = present("guai 2",environment(me));
    if (ob0)
      destruct (ob0);
    ob1 = new(str);
    ob1->setup();
    ob1->move(environment(ob));
    ob2 = new(str);
    ob2->setup();
    ob2->move(environment(ob));
    //ob3 = new(str);
    //ob3->setup();
    //ob3->move(environment(ob));
    message_vision ("$N���һ���������ͻȻ��������$N��\n",ob);
    ob->set("kee",ob->query("max_kee")/10*12);
    ob->set("triplicate",1);
    ob1->set("triplicate",1);
    ob2->set("triplicate",1);
    //ob3->set("triplicate",1);
    ob1->fight_ob(me);
    ob2->fight_ob(me);
    //ob3->fight_ob(me);
  }
  return 1;
}

void unconcious()
{
  die();
}

�
