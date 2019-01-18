// gao.c

inherit NPC;
int give_jade();
int show_king();

void create()
{
  set_name("����", ({"guo wang", "wang", "king"}));
  set("long", "ͷ��һ������ڣ�����һ�����������һ�������������ۡ�\n");
  set("title", "�ڼ���");
  set("gender", "����");
  set("age", 46);
  set("per", 30);
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

  setup();
  carry_object("/d/obj/cloth/longpao")->wear();
}

void announce_success()
{
  object me = this_object();
  object where = environment(me);
  string id = me->query("my_saver");
  object who;

  if (! id)
    return;

  who = present(id,where);
  if (! who)
    return;

  remove_call_out ("announce");
  call_out ("announce",8,me,who);
}

void announce(object me, object who)
{//disabled announce and reward...
  int i;

  if (who->query_temp("obstacle/wuji") != "saved")
    return;

  if (who->query("obstacle/wuji") == "done")
  {
    //tell_object (who,"���Ѿ�������һ�أ�ʲô���ò����ˣ�\n");
    return;
  }  

  i = random(600);
  who->add("obstacle/number",1);
  who->set("obstacle/wuji","done");
  //who->add("combat_exp",i+4000);
  command("thank "+who->query("id"));
  //command("chat "+who->query("name")+"�ڼ������һ�����������������Ǭ����");
  //command("chat "+who->query("name")+"˳������������һ�أ�");
  //tell_object (who,"��Ӯ����"+chinese_number(4)+"��"+
  //             chinese_number(i/4)+"��"+
  //             chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  who->save();
  command("follow none");
}

