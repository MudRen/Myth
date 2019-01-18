// by snowcat 11/6/1997

inherit NPC;
int test_player (object who);

void create()
{
  set_name("�Ϲٿ���", ({"shangguan junzhu", "junzhu", "zhu"}));
  set("title", "���ɿ�");
  set("long", "���ù����ɿ���һ��֮�\n");
  set("gender", "����");
  set("age", 50);
  set("per", 25);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 200000);
  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set("max_gin",800);
  set("max_kee",800);
  set("max_sen",800);
  set("max_force",1000);
  set("max_mana",1000);
  set("force_factor",120);
  set("eff_dx",15000);
  set("nkgain",90);
  set("inquiry", ([
    "name" : "�Ϸ��˷��ɿ���Ϲ��˱���֮���ա�",
    "�Ϲ�" : "�Ϸ��˷��ɿ���Ϲ��˱���֮���ա�",
    "here" : "�������ù����ɿ�����ú����꼱Ѱ��ʦ�Լ�����������������Ҳ��",
    "rain" : (: test_player :),
    "��" : (: test_player :),
    "����"   : (: test_player :),
    "����" : (: test_player :),
    "����" : (: test_player :),
  ]));
  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
  carry_object("/d/obj/weapon/blade/fengdao")->wield();
}

int test_player (object who)
{
  object me = this_object();
  who = this_player();

  if (who->query("obstacle/fengxian")=="done")
  {
    message_vision ("$N��æ��$n����һ�ݣ���л��\n",me,who);  
    return 1;
  }

  message_vision ("$N˵�������ٴ�ʦǰ�����ɿ��ȼ�����"+
                  "ȥ�������������̳������δ�й���\n",me);
  message_vision ("$N��̾��һ������\n",me);
  return 1;
}

void init ()
{
  object who = this_player();

  call_out ("check_player",3,who);
}

void check_player (object who)
{
  object me = this_object();
  if (!who)
    return;
  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/fengxian") == "done")
    return;
  if (who->query_temp("obstacle/fengxian_donated") < 1)
    return;
  if (who->query_temp("obstacle/fengxian_ketou") < 9)
    return;
  if (who->query_temp("obstacle/fengxian_zhanbai") < 9)
    return;
  if (who->query_temp("obstacle/fengxian_nianxiang") < 9)
    return;
  if (environment(who) != environment(this_object()))
    return;
  message_vision ("��������һ���ˣ�����$Nһ�ۡ�\n",who);
  message_vision ("���˶�$Nһ��˵�����������Ͽ�����������������"+
                  "��Ȼһ�����ꡣ\n",me);
  message_vision ("\n�������¡�\n",me);
  command ("ah");
  command ("thank "+who->query("id"));
  call_out ("announce_success",3,who);
}

void announce_success (object who)
{
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/fengxian") == "done")
    return;
  i = random(600);
  who->add("obstacle/number",1);
  who->set("obstacle/fengxian","done");
  who->add("daoxing",i+3000);
  command("chat "+who->query("name")+"���ɿ�Ȱ��ʩ�أ��ȵü���ǧǧ����");
  command("chat "+who->query("name")+"˳������������һ�أ�");
  tell_object (who,"��Ӯ����"+chinese_number(3)+"��"+
               chinese_number(i/4)+"��"+
               chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  who->save();
}
