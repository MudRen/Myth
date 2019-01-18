// created 11/6/1997 by snowcat

inherit NPC;

void create()
{
  string dir;
  set_name("������", ({"pilan po", "po", "daogu"}));
  set("title", "����");
  set("gender", "Ů��");
  set("age", 58);
  set("per", 26);
  set("rank_info/respect", "����");
  set("combat_exp", 1000000);
  set("daoxing", 1500000);

  set_skill("snowsword", 90);
  set_skill("sword", 90);
  set_skill("dragonfight", 90);
  set_skill("unarmed", 90);
  set_skill("dodge", 90);
  set_skill("parry", 90);
  set_skill("spells", 90);
  set_skill("dragonstep", 90);
  map_skill("dodge", "dragonstep");
  map_skill("unarmed", "dragonfight");
  map_skill("sword", "snowsword");
  map_skill("parry", "snowsword");
  set("max_gin", 900);
  set("max_kee", 900);
  set("max_sen", 900);
  set("force", 900);
  set("max_force", 900);
  set("mana", 900);
  set("max_mana", 900);
  set("force_factor", 90);

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
}

void announce_success (object who)
{
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/pansi") == "done")
    return;
  if (who->query_temp("obstacle/pansi_killed") < 15)
    return;
  i = random(600);
  who->add("obstacle/number",1);
  who->set("obstacle/pansi","done");
  who->add("daoxing",i+4000);
  command("chat "+who->query("name")+"��˿�뾡��֩�뾫�ƻ��۽�����򼾫��");
  command("chat "+who->query("name")+"˳������������һ�أ�");
  tell_object (who,"��Ӯ����"+chinese_number(4)+"��"+
               chinese_number(i/4)+"��"+
               chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  who->save();
}
�
