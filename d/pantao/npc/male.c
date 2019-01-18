// by snowcat 5/29/1997

#include <ansi.h>

inherit NPC;

void create()
{
  string *names = ({ "�ɹ�", "�ɽ�", "����", });
  string name = names[random(sizeof(names))];

  set_name(name,({ "xian" }) );
  set("gender", "����" );
  set("long", "һλ��緽���ܽ�عڵ�"+name+"��\n");
  set("age", 100+random(100));
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 50);
  set("combat_exp",400000);
  set("force",500);
  set("max_force",500);
  set("force_factor", 100);
  set("max_gin", 4000);
  set("max_kee", 4000);
  set("max_sen", 4000);
  set("max_mana", 4000);
  set("mana", 400);
  set("mana_factor", 20);
  set_skill("unarmed",100);
  set_skill("dodge",100);
  set_skill("parry",100);
  set_skill("spear",100);
  set_skill("force",100);
  set("chat_chance",5);
  set("chat_msg",({(: random_move :)}));
  setup();
  carry_object("/d/obj/cloth/xianpao")->wear();
}
�