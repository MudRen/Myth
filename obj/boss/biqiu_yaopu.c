
inherit F_VENDOR_SALE;

void create()
{
  reload("biqiu_yaopu_langzhong");
  set_name("������", ({"ma langzhong", "ma", "langzhong"}));
  set("shop_id", ({"langzhong", "hou"}));
  set("shop_title", "����ҩׯҩ����");
  set("gender", "����");
  set("combat_exp", 50000);
  set("daoxing", 30000);

  set("age", 70);
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

