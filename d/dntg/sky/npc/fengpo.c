//sgzl

inherit NPC;

int have_fu;

string give_fu(object who);
int do_yes(string arg);

void create()
{
set_name("����",({"feng po","feng shen","po"}));
set("gender", "Ů��");
set("age", 35);
set("long", "    \n�칬�и�������������Ҫ�η�����ʱ��û����\n�İ����ǲ��еġ�\n");

set("attitude", "heroism");
set("class", "xian");

    set("combat_exp", 60000);
  set("daoxing", 100000);


set("kee", 600);
set("max_kee", 600);
set("sen", 650);
set("max_sen", 650);
set("force", 800);
set("max_force", 800);
set("mana", 1000);
set("max_mana", 1000);
set("force_factor", 20);
set("mana_factor", 30);
set("per", 18);


set_skill("dodge", 80);
set_skill("moondance", 40);
set_skill("unarmed", 100);
set_skill("baihua-zhang", 70);
set_skill("parry", 120);


map_skill("dodge", "moondance");
map_skill("unarmed", "baihua-zhang");
set("inquiry", ([
  "����"   : "�����꣬����һ���˿ɲ�����",
  "rain"   : "�����꣬����һ���˿ɲ�����",
  "���"   : (: give_fu :),
  "�η�"   : (: give_fu :),
  "wind"   : (: give_fu :),
  "name"   : "�Ҿ��Ǹ������ķ���",
  "here"   : "������칬ѽ��",
]));


setup();

carry_object("/obj/loginload/skirt.c")->wear();
carry_object("/obj/loginload/shoes.c")->wear();
add_money("silver", 10);

}


void init()
{
  have_fu=1;
  add_action("do_yao", "yao");
}

string give_fu(object who)
{
  who=this_player();
  if ( (who->query("combat_exp")<10000) || (who->query("mana") < 500 ) )
    {
    return "�����㻹������ô���绽�꣬�ٺú����������ɡ�\n";
    }
  else
    {
    who->set_temp("need_fengfu", 1);
    return "���������������������磬����Ҫ��(yao)��\n";
    }
}

int do_yao(string arg)
{
  object me=this_object();
  object who=this_player();
  object fu;
   if(who->query_temp("need_fengfu")) 
   {
      message_vision("$N�������Ҫ��\n", who);

      if (have_fu==1)    
         {
         message_vision("����˵�����ðɣ��������Կ��������鲻�顣\n", who);
         fu = new ("/d/dntg/sky/obj/fenglingfu");
         fu ->move(who);
         message_vision ("$N����$nһ�ŷ������\n",me,who);
         have_fu=0;
         }
      else 
         {
         message_vision("����˵������ѽ��ʵ�ڲ�����˼���Ҹհ����������ˣ���Ȼ������Ҫ�ɡ�\n", who);
         }
      return 1;

  }
}
��
