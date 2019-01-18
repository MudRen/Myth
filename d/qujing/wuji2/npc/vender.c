
inherit NPC;
inherit F_VENDOR;

void create()
{
  set_name("Ҷ��ɩ", ({"ye dasao", "ye", "dasao", "fruit vendor"}));
  set("gender", "Ů��");
  set("combat_exp", 1000);
  set("age", 26);
  set("per", 20);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 10);
  set("vendor_goods", ([
    "grape": "/d/obj/food/grape",
    "pear": "/d/obj/food/xueli",
    "strawberry": "/d/obj/food/strawberry",
    "apple": "/d/obj/food/apple",
    "mellon": "/d/obj/food/mellon",
   ]) );

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
  add_money("silver", 1);
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
  switch( random(3) ) {  // 1/3 chance to greet.
    case 0:
      say ("Ҷ��ɩЦ�����˵������λ" + RANK_D->query_respect(ob)
           + "����ӭ�ݹ��ļ��Ϲ��꣡\n");
      break;
  }
}


