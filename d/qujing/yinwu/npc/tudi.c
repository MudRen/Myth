// rewritten by snowcat on 4.12.1997

inherit NPC;

int give_fajian();

void create()
{
  set_name("��������", ({"tu di", "tu", "di"}));
  set("gender", "����");
  set("age", 100);
  set("attitude", "friendly");
  set("combat_exp", 250000);
  set("daoxing", 300000);

  set("per", 25);
  set_skill("dodge", 60);
  set("max_sen",600);
  set("max_gee",600);
  set("max_gin",600);
  set("force",800);
  set("max_force",800);
  set("max_mana",800);
  set("force_factor",25);
  set_skill("spells",60);
  set_skill("stick",60);
  setup();

  set("inquiry", ([
       "here": "���������ɽ�������������ڴˡ�\n",
       "����ɽ": "����ɽ����������֮ȥ�������С��Ϊ�ǡ�\n",
       "������": "������������ɽ���������Σ����������Ҳ��\n",
       "name": "����ɽ����Ҳ���Ϸ�������ֻ��һ����\n",
       "��": "�Ϸ���һ������һ��һ��ʦ������\n",
       "����": (: give_fajian :),
       "fajian": (: give_fajian :),
      ]));
  carry_object("/d/obj/cloth/choupao")->wear();

}

int give_fajian()
{
  object me = this_object();
  object who = this_player();
  object fajian;

  if (who->query("combat_exp") < 10000 ||
      present("fa jian",who))
  {
    command ("shake");
    return 1;
  }

  fajian = new ("/d/qujing/yinwu/obj/fajian");
  fajian->move(me);
  command("hmm");
  command("give "+who->query("id")+" fa jian"); 
  who->set_temp("obstacle/yinwu_fajian",1);
  return 1;
}

void init()
{
  object ob;

  ::init();
}

void call_out_announce_success (object who)
{
  call_out ("say_hi",1,who);
  call_out ("announce_success",2,who);
  call_out ("destruct_me",3,this_object());
}

void say_hi (object who)
{
  message_vision ("\n����������$N����һ��ȭ��\n",who);
}

void destruct_me (object me)
{
  message_vision ("$N������һ�����ʧ�ˡ�\n",me);
  destruct (me);
}

void announce_success (object who)
{//disabled announce and reward...
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/yinwu") == "done")
    return;
  if (! who->query_temp("obstacle/yinwu_fajian"))
    return;
  if (! who->query_temp("obstacle/yinwu_yaowang"))
    return;
  i = random(800);
  who->add("obstacle/number",1);
  who->set("obstacle/yinwu","done");
  who->add("daoxing",i+3000);
  command("chat "+who->query("name")+"����ɽʩ��������������а��");
  command("chat "+who->query("name")+"˳������������һ�أ�");
  tell_object (who,"��Ӯ����"+chinese_number(3)+"��"+
               chinese_number(i/4)+"��"+
               chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  who->save();
}
�
