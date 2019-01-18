#include <ansi.h>

inherit NPC;

void create()
{
  set_name("����", ({ "fu ling", "ling" }) );
  set("gender", "����");
  set("age", 50);
  set("combat_exp", 120000);
  set("attitude", "heroism");

  set("str", 30);
  set("max_kee", 600);
  set("max_gin", 600);
  set("force", 600);
  set("max_force", 600);
  set("force_factor", random(30)+15);
  set_skill("unarmed", 60);
  set_skill("parry", 60);
  set_skill("dodge", 60);
  setup();

  carry_object("/d/obj/cloth/changpao")->wear();
}

void announce_success (object who)
{//disabled announce and reward...
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/jinping") == "done")
    return;
  if (who->query_temp("obstacle/jinping_oil") < 10)
    return;
  if (! who->query_temp("obstacle/jinping_pi1_killed"))
    return;
  if (! who->query_temp("obstacle/jinping_pi2_killed"))
    return;
  if (! who->query_temp("obstacle/jinping_pi3_killed"))
    return;
  i = random(700);
  who->add("obstacle/number",1);
  who->set("obstacle/jinping","done");
  who->add("daoxing",i+4000);
  command("chat "+who->query("name")+"��ƽ���ƻ���ѣ�����ɽ��Ϭţ����");
  command("chat "+who->query("name")+"˳������������һ�أ�");
  tell_object (who,"��Ӯ����"+chinese_number(4)+"��"+
               chinese_number(i/4)+"��"+
               chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
 who->save();
}