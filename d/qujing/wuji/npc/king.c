// gao.c

inherit NPC;
int give_jade();
int show_king();

void create()
{
  set_name("����", ({"ghost guo wang", "guo wang", "wang", "king"}));
  set("long", "ͷ��һ������ڣ�����һ�����������һ�������������ۡ�\n");
  set("title", "�ڼ���");
  set("gender", "����");
  set("age", 46);
  set("per", 30);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 1);
  set_skill("unarmed", 1);
  set_skill("dodge", 1);
  set_skill("parry", 1);
  set("max_gin", 1);
  set("max_kee", 1);
  set("max_sen", 1);
  
  set("inquiry", ([
      "name": "�Ϸ������ڼ�������������ǰ��һ������������������԰��������\n",
      "here": "���˱�����Ҳ",
      "����":"����ǰ���������������˾����Լ������޵�ģ������ռ���޵Ľ�ɽ��\n",
      "����":(:give_jade :),
  ]) );

  setup();
  carry_object("/d/obj/cloth/longpao")->wear();
  call_out("show_king", 1);
}

int show_king()
{
  object king = this_object();
  message_vision("ֻ������һʱ�������������ֳ�һ��ˮ���ܵ���Ӱ��\n", king);
  call_out("talk_king", 5+random(5));
  return 1;
}

int talk_king(){

  object king = this_object();
  string *msgs = ({
    "�ڼ��������д��ᣬ���ﲻס��ֻ�У�ʦ����Ҫ���ұ���!\n",
    "�ڼ�����̾��������������ȥ���꣬�Ǹ��侮�����ԩ��֮��!\n",
    "�ڼ���������˵��ʦ�����б���ȥ����ȡ�������ܰ��ұ���\n",
    "�ڼ���������˵��ʦ�����ܳ�ȥ����������Ȼ������������!\n",
    "�ڼ�����̾�����ɺ������������޵�ģ������ռ���޵Ľ�ɽ���������ҵĹ�����\n",
    "�ڼ�����̾�����ɺ���������ͨ��󣬵ظ����þ�������ԩ֮����\n",
    "�ڼ���������˵������ҹ�����Ҵ����˼䣬˵ʦ������԰��ޡ�\n",
    "�ڼ���������˵��ʦ����������ס������������а�����޵�����λ�����ʦ����\n", 
   });

  if (random(7) == 0)
  {
    call_out("king_disappear",5);
    return 1;
  }
  message_vision (msgs[random(sizeof(msgs))],king);
  call_out("talk_king",5+random(15));
  return 1;
}

int give_jade()
{
  object king = this_object(); 
  object who = this_player();
  string id = who->query("id");
  object where = environment(king);
  object jade;

  if (who->query("combat_exp")<50000)
  {
    command("?");
    return 1;
  }
/*
  if (who->query("obstacle/wuji") == "done")
  {
    command("hmm");
    return 1;
  }
*/
  if (present("yu gui",who))
  {
    command("hmm "+id);
    return 1;
  }
  if (where->query("short")!="���᷿")
  {
    command("ah "+id);
    return 1;
  }
  if (where->query("has_given"))
  {
    command("shake "+id);
    return 1;
  }
  where->set_given();
  message_vision ("$N��$n˵��ʦ��������һ���������ɡ�\n",king,who);
  message_vision ("˵��$N��$nһ��������\n",king,who);
  jade = new("/d/qujing/wuji/obj/jade.c");
  jade->move(who);
  return 1;
}

int king_disappear()
{
  object king = this_object(); 
  message_vision ("���һ������������Ȼ���ѣ��ڼ������Ѿ������ˡ�\n",king);
  destruct (king);
  return 1;
}

void die ()
{
  object king = this_object(); 
  message_vision ("$N��ʧɫ�����һ����Ϊһ�����̷�ȥ��\n",king);
  destruct (king);
}

void unconcious()
{
  die();
}

void kill_ob (object ob)
{
  die();
}

int accept_fight (object ob)
{
  command ("ah");
  return 0;
}
