inherit NPC;

void create()
{
  set_name("����", ({"tu di","tudi"}));
  set("gender", "����");
  set("age", 100);
  set("long","ר�����԰��������үү����ü��Ŀ��һ�ź�����\n");
  set("attitude", "friendly");
  
    set("combat_exp", 50000);
  set("daoxing", 250000);


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

void init()
{
  object ob;

  ::init();
  set("inquiry", ([
       "here": "��������ĸ��������԰��\n",
      ]));

  if (interactive(ob = this_player()) && !is_fighting())  {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }       
}

void greeting(object ob)
{
  if (!ob || environment(ob) != environment())
    return;
  if (ob->query_temp("dntg/pantao")=="doing") {
// need query_temp(dntg/pantao) and query(dntg/pantao)==doing
    command("bow "+ob->query("id"));
    command("say ��ӭ"+ob->query("name")+RANK_D->query_respect(ob)+
             "ִ�����԰���������������ˡ�");  
    return;
  }
  if (ob->query("dntg/pantao")=="done") {
     command("fear "+ob->query("id"));
     command("say ����"+RANK_D->query_rude(ob)+ 
           "�ϴ��ǳ�ټ���Ƿǣ�������Ҳ����ϴ��ǣ�������Ļ���ǰ����");
     return;
  } 
  command("hi "+ob->query("id"));
}
��
