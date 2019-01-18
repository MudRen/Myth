// NPC  /d/city/npc/wangsao.c
// Last Modified by waiwai@2003/01/18

#include <allobj.h>
//#include <quest.h>
//inherit KNOWER;
inherit NPC;

inherit F_VENDOR;
string give_renwu(object ob);

void create()
{
	set_name("��ɩ", ({"wang sao", "wang", "sao"}));
	set("title", "��������");
	set("changed", "����");
	set("gender", "Ů��");
	set("combat_exp", 10000);
	set("age", 26);
	set("per", 20);
	set("attitude", "friendly");
	set("shen_type", 1);
	set_skill("unarmed", 10);

        set("vendor_goods", ([
		"1": "/d/city/obj/miantiao",
//		"/d/obj/drug/jinchuang":100,
        ]) );

	set("inquiry", ([
//	       "rumor" : (: give_renwu :),
	]) );

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
}
void init()
{
  object ob;

  ::init();
  if( interactive(ob = this_player()) && !is_fighting() ) {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
  add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || !visible(ob) || environment(ob) != environment() ) return;
       if( ob->query("env/invisibility") ) return;

  switch( random(3) ) {  // 1/3 chance to greet.
    case 0:
      say ("��ɩЦ�����˵������λ" + RANK_D->query_respect(ob)
           + "�������Ⱥ�����������\n");
      break;
  }
}
