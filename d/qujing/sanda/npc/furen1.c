//Cracked by Roath
// ����֮��  ������
//  happ@YSZZ 2000.4.13

#include <ansi.h>

inherit NPC;

void create()
{
  set_name("�ϸ���", ({"fu ren", "fu", "ren"}));
  set("gender", "Ů��");
  set("age", 80);
  set("con", 20);
  set("cor", 20);
  set("int", 20);
  set("per", 30);
  set("attitude", "peaceful");
  set("combat_exp", 400000);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("force", 50);
  set_skill("spells", 50);
  set_skill("unarmed", 50);
  set_skill("gouhunshu", 50);
  set_skill("tonsillit", 50);
  set_skill("ghost-steps", 50);
  set_skill("jinghun-zhang", 50);
  map_skill("unarmed", "jinghun-zhang");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  set("max_gin", 700);
  set("max_kee", 700);
  set("max_sen", 700);
  set("force", 800);
  set("max_force", 800);
  set("mana", 800);
  set("max_mana", 800);
  set("force_factor", 60);
  set("mana_factor", 60);
  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/qujing/baoxiang/obj/zhuzhang");
}


void unconcious()
{
  die();
}

void die()
{
  object me = this_object();
  object where = environment(me);
  object ob = query_temp("my_killer");
  object corpse;

  if ( ob) {

  if (ob->query_temp("obstacle/sanda_nuzi_killed"))
{
  command("say �Ҳ�����������");
  tell_object(ob,"��������������ߵ���˺��޹�����ĵ��м���һ�꣡\n");
        ob->add("daoxing", -1000);
  ::die();
  return;
}

  message_vision ("\n$Nһ���ҽУ��˷��ڵ����ˡ�\n",me);
  command ("drop zhu zhang");
  corpse = CHAR_D->make_corpse(me,ob);
  corpse->move(where);
  destruct(me);
  return;
  }
::die();
}
void kill_ob (object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
 
