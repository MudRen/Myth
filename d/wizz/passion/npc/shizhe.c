#include <ansi.h>
inherit NPC;
void create()
{
set_name(""HIR"ӭ��ʹ"NOR"", ({"sjskwiz"}));
set("gender", "Ů��");
set("age", 20);
set("per", 30);
 set("combat_exp", 5000);
  set_skill("force", 50);
  set_skill("spells", 50);
  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set("gin", 500);
  set("max_gin", 500);
  set("kee", 500);
  set("max_kee", 500);
  set("sen", 500);
  set("max_sen", 500);
  set("force", 150);
  set("max_force", 150);
  set("mana", 150);
  set("max_mana", 150);
  set("force_factor", 10);
  setup();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting()
        && !ob->query("env/invisibility") ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
say( "ʹ��˵������λ" + RANK_D->query_respect(ob) + "����ӭ������������\n");
}



