// rewritten by snowcat on 4/12/1997

inherit NPC;

void create()
{
  set_name("����", ({"oldman","man"}));
  set("gender", "����");
  set("age", 60);
  set("long","����һλ��ס�˵ص����ˡ���ü���룬ͭ����ۣ���Ϊ�Ͱ���\n"); 
  set("attitude", "friendly");
  set("combat_exp", 5000);
  set("per", 25);
  set_skill("dodge", 10);
  setup();

  carry_object("/d/gao/obj/changpao")->wear();
  add_money("coin", 100);
}

int accept_fight(object me)
{
  say("���߲�ΣΣ��˵����"+RANK_D->query_respect(me)+"��������������ɡ�\n");
  return 0;
}

void init()
{
  object ob;

  ::init();
  set("inquiry", ([
        "here":   "����ǻ���ɽ���Թ����������󱦣����ȣ��Ž��ǡ�\n",
        "����ɽ": "����ɽ�˰����𣬷���ʵ�ǲ���ѷɣ�Ҫ�����Ȳ������\n",
        "����":   "�����ȹ����ɣ���˵����Ҳ�У����ͰŽ���Ҳ�С�\n",
        "�Ž���": "ȥ���������أ�ֻ����ָ�����ȥ�ҰŽ��ǡ�\n",
        "���ȹ���": "����ס�ڴ���ɽ�У�����һ��Ů������\n",
      ]));

  if (interactive(ob = this_player()) && !is_fighting())
  {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
}

void greeting(object ob)
{
  if (!ob || environment(ob) != environment())
    return;

  switch (random(1))
  {
    case 0:
    {
      say( "����ӭ��ǰ����"+RANK_D->query_respect(ob)+"���Ķ���ѽ��\n");
      break;
    }
  }
}

