inherit NPC;

void create()
{
  set_name("̫���Ͼ�",({"taishang laojun","laojun","dao"}));
  set("gender", "����");
  set("age", 55);
  set("long", "    \n̫���Ͼ���\n");

  set("attitude", "peaceful");
  set("class", "taoist");
  set("combat_exp", 2000000);
  set("daoxing", 4000000);
  set("kee", 400);
  set("max_kee", 400);
  set("sen", 400);
  set("max_sen", 400);
  set("force", 400);
  set("max_force", 400);
  set("mana", 400);
  set("max_mana", 400);
  set("force_factor", 5);
  set("mana_factor", 10);


  set_skill("spells", 30);
  set_skill("dao", 30);
  set_skill("dodge", 60);
  set_skill("parry", 40);
  set_skill("unarmed", 30);


  set("inquiry", ([
  "here"   : "������Ƕ��ʹ������������ʲô��",
]));


setup();

carry_object("/d/lingtai/obj/cloth")->wear();

}


void init()
{
  object who;

  ::init();
  if( interactive(who = this_player()) && !is_fighting() ) 
    {
     remove_call_out("greeting");
     call_out("greeting", 1, who);
    }
}


void greeting(object who)
{
  object me = this_object();
//  object who = this_player();
  if (who->query("dntg/laojunlu")=="allow")
    {
    me->command("kick");
	who->set("dntg/laojunlu","allow");
    me->command("chat ���²��ã�"+who->query("name")+"�Ӱ���¯���ӳ����ˣ�");
    remove_call_out("leave_laojunlu");
    call_out("leave_laojunlu", 1, who);  
    } 
}

int leave_laojunlu(object who)
{
    message_vision("$Nŭ����ײ��һ���߷��Ͼ�¯���Ϻ�һ��������ɱ����ͥ�������ǻ���ı�������\n", who);
    who->move("/d/dntg/sky/tongmingdian");
}
