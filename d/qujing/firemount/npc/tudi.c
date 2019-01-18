// rewritten by snowcat on 4.12.1997

inherit NPC;

void create()
{
  set_name("����", ({"tudi","tu di"}));
  set("gender", "����");
  set("age", 100);
  set("long","ר�ܻ���ɽ��԰�˰����������үү��"+
      "�������Ͼ����ʹ��п�¯�ĵ�ʿ����ʧְ�������·��硣\n");
  set("attitude", "friendly");
  set("combat_exp", 250000);
  set("daoxing", 100000);
  set("no_nk_reward",1);

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

  carry_object("/d/gao/obj/changpao")->wear();
  add_money("coin", 100);

}

int allow_search()
{
  object me = this_object();
  object who = this_player();

  who->set_temp("know_palm_bone",1);
  message_vision("$N˵���Ž��Ǿ��ڴ���ɽ�����ȥ��(search)��\n",me,who);
  return 1;
}

void init()
{
  object ob;

  ::init();
  set("inquiry", ([
       "here": "����л���ɽ�����ȹ��������ȣ��Ž��ǡ�\n",
       "����ɽ": "����ɽ�˰����𣬷���ʵ�ǲ���ѷɡ�\n",
       "���ȹ���": "����ס�ڴ���ɽ�У�����һ��Ů������\n",
       "�Ž���": (: allow_search :),
      ]));

  if (interactive(ob = this_player()) && !is_fighting()&&       
     ob->query_temp("push_nixiang")>0)
  {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }       
}

void greeting(object ob)
{
  if (!ob || environment(ob) != environment())
    return;
  say ("����������Ҿ����֪"+RANK_D->query_respect(ob)+"���������кι�ɣ�\n");
}

�
