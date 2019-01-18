inherit F_VENDOR_SALE;

void create()
{
  reload("tongtian_doctor");
  set_name("��ɽҩ", ({"chen shanyao", "chen", "shanyao"}));
  set("shop_id", ({"shanyao", "chen"}));
  set("shop_title", "ҩũ");
  set("gender", "����");
  set("combat_exp", 50000);
  set("daoxing", 30000);

  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set_skill("dodge", 30);
  set_skill("parry", 30);
  set("vendor_goods", ([
        "yao": "/d/obj/drug/jinchuang",
        "dan": "/d/obj/drug/hunyuandan",
        ]) );

  setup();
  carry_object("/d/qujing/tianzhu/obj/baipao")->wear();
  carry_object("/d/qujing/tianzhu/obj/simao")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}
