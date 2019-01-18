// created by smile 12/08/1998
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("�׹Ǿ�", ({"baigu jing", "jing"}));
  set("title", "�׹Ƿ���");
  set("long",@LONG
    �׹Ƿ�������ǧ��׹Ǿ��������Σ�ǰ����Թ����겻
�ó������������κ�Թ�����࣬���Ƿ���Ҫ�Ծ������ˡ�
LONG);
 set("gender", "Ů��");
  set("age", 40);
  set("attitude", "friendly");
  set("combat_exp", 1000000);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set_skill("force", 100);
  set_skill("spells", 100);
  set_skill("unarmed", 100);
  set_skill("stick", 120);
  set_skill("gouhunshu", 100);
  set_skill("tonsillit", 100);
  set_skill("ghost-steps", 100);
  set_skill("jinghun-zhang", 100);
  set_skill("kusang-bang", 100);
  map_skill("dodge","ghost-steps");
  map_skill("unarmed", "jinghun-zhang");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  map_skill("stick", "kusang-bang");
  map_skill("parry", "kusang-bang");
  set("eff_dx",-90000);
  set("nkgain",400);

  set("max_gin", 1100);
  set("max_kee", 1100);
  set("max_sen", 1100);
  set("force", 1200);
  set("max_force", 1200);
  set("mana", 1500);
  set("max_mana", 1500);
  set("force_factor", 100);
  set("mana_factor", 80);
  set("chat_chance_combat",35);
  set("chat_msg_combat", ({
		(: cast_spell, "gouhun" :),
                          }) );
  setup();
  carry_object("/d/qujing/baigudong/obj/renpipifeng")->wear();
  carry_object("/d/qujing/baigudong/obj/baigugun")->wield();
}

void init ()
{
  object ob = this_player();
  object me = this_object();
  call_out("greeting", 1, ob);
} 

void greeting(object ob)
{
  int bool_var;
  if( !ob || environment(ob) != environment() ) return;
  
  if (ob && interactive(ob))
  {
    bool_var=0;
    if(ob->query("obstacle/baigudong")=="done") return;
    if(ob->query_temp("obstacle/baigudong_nuzi_killed")!=0) bool_var=1;
    if(ob->query_temp("obstacle/baigudong_furen_killed")!=0) bool_var=1;
    if(ob->query_temp("obstacle/baigudong_gonggong_killed")!=0) bool_var=1;
    if(bool_var==1)
     {
      command("consider "+ob->query("id"));
      message_vision ("$N��ŭ�����������"+RANK_D->query_rude(ob)+"��\n",this_object());
      this_object()->kill_ob(ob);
     }
  }
}

int accept_fight (object ob)
{
  ob->apply_condition ("killer",100);
  kill_ob (ob);
  return 1;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}

void unconcious()
{
  object ob = query_temp("my_killer");
  object me = this_object();
  object gutou = new("/d/qujing/baigudong/obj/fenkulou");
  object where;
  where =environment(me);
  if (ob)
  {
    ob->set_temp("obstacle/baigudong_baigujing_killed",1);
    call_out ("shanshen_appearing",1,ob);
  }
  message_vision ("\n$N�ҽ�һ��������һ�����ã�ɢ���ڵ��ϡ�\n",me);
  gutou->move(where);
    command("drop pifeng");
  message_vision (HIY "����ɽ�������Ц������������ɽ���У�\n\n" NOR,me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void shanshen_appearing (object who)
{
  object shanshen = new ("/d/qujing/baigudong/npc/shanshen");

  shanshen->announce_success (who);
  destruct (shanshen); 
}

void destruct_me(object me)
{
  destruct(me);
}

void die()
{
  unconcious();
}

