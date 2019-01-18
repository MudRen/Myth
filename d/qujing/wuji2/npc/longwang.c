//Changed 
#include <skill.h>

inherit NPC;

string show_king (object who);

void create()
{
  set_name("������", ({"jing longwang","longwang","wang"}));
  set("long","������������ƹ��ž��׵����硣\n");
  set("gender", "����");
  set("age", 55);
  set("class","dragon");
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 550000);
  set("rank_info/respect", "����");
  set("per", 24);
  set("str", 30);
  set("max_kee", 1000);
  set("max_gin", 800);
  set("max_sen", 800);
  set("force", 1000);
  set("max_force", 1000);
  set("force_factor", 90);
  set("max_mana", 800);
  set("mana", 1200);
  set("mana_factor", 40);
  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("force", 80);
  set_skill("parry", 80);
  set_skill("fork", 80);
  set_skill("spells", 80);
  set_skill("seashentong", 80);
  set_skill("dragonfight", 80);
  set_skill("dragonforce", 80);
  set_skill("fengbo-cha", 80);
  set_skill("dragonstep", 80);
  map_skill("spells", "seashentong");
  map_skill("unarmed", "dragonfight");
  map_skill("force", "dragonforce");
  map_skill("fork", "fengbo-cha");
  map_skill("parry", "fengbo-cha");
  map_skill("dodge", "dragonstep");

  set("inquiry", ([ "����": (: show_king :),
                    "����": (: show_king :),
                    "king": (: show_king :),
                 ]) );

  setup();

  carry_object("/d/obj/cloth/longpao")->wear();
}

string show_king (object who)
{  
  object me = this_object();
  object where = environment(me);
  object king;

  who = this_player();
  if (present ("guo wang",where))
    return ("�����ڴˣ�\n");
  if (where->query("short") != "ˮ����")
    return ("Ī�ᣬĪ�ᣡ\n");
  if (! present("wuji jing",who))
    return ("��������ι�Ҳ��\n");
  if (where->query("has_given"))
    return ("����������Ҳ��\n");
  where->set_given();
  command("sigh");
  message_vision ("$Nһ���֣�ˮ�¸�����ҹ�棬��ʲô����̧��������\n\n",me);
  king = new ("/d/qujing/wuji/obj/kingbody");
  king->move(where);
  return ("��������Ҳ��\n");
}

