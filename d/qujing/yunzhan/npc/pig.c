//Cracked by Roath
 
inherit NPC;
#include <ansi.h>

void create()
{
  set_name("���", ({ "zhu guai","pig" }));
  set("age", 600);
  set("gender", "����");
  set("long", "һ��Ұ��֡�\n");
  set("attitude", "peaceful");
  set("str", 70);
  set("per", 10);
  set("combat_exp",2500000);
  set("daoxing",1500000);
  set("max_kee", 4000);
  set("max_sen", 4000);
  set("max_force", 4000);
  set("force", 4000);
  set("force_factor", 200);
  set("mana_factor", 50);
  set_skill("unarmed", 190);
  set_skill("dodge", 250);
  set_skill("parry", 60);
  set_skill("rake", 250);
  set_skill("force", 80);
  set_skill("spells", 80);
  set_skill("baguazhou", 80);
  set_skill("yanxing-steps", 200);
  set_skill("skyriver-rake", 250);
  map_skill("force", "lengquan-force");
  map_skill("spells", "baguazhou");
  map_skill("rake", "skyriver-rake");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "yanxing-steps");
  setup();
  carry_object("/d/kaifeng/obj/jiuchipa")->wield();
  carry_object("/d/obj/armor/tongjia")->wear();
}
void init()
{
          object ob = this_player();

        if ( ob->query_temp("apply/name")&&
            ob->query_temp("apply/name")[0] == "����" )
        {
        command("hug cui lan");
        command("kiss cui lan");
        return;
        }
        return ;
}

int accept_fight (object ob)
{
  ob->apply_condition ("killer",100);
  kill_ob (ob);
}
void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
 call_out ("move_to_cave",1,this_object());

}

void move_to_cave (object me)
{
  object where = environment(me);
//  string place;
  //place = "/d/qujing/yunzhan/shulin1";
 // place[strlen(place)-1] = '0'+random(10); 
  if (! where ||
    where->query("short") == "[33m����[m")
    return;
  message_vision ("\n$N����һ�������ʧ�ˣ�\n",me);
  me->move("/d/qujing/yunzhan/shulin7");
}
void die()
{
  object me = this_object();
  object ob = query_temp("my_killer");

  if (ob)
  {
  message_vision(HIR"ֻ��$N��ɵ������ֱ��������\n"NOR,me);
  message_vision(HIR"ԭ��$N�Ǹ�����·���Ͷ����̥��\n"NOR,me);
  ob->set_temp("pig_killed",1);
  destruct(me) ;
   }
}
