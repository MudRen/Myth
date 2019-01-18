// rewritten by snowcat on 4/12/1997

inherit F_VENDOR_SALE;

void create()
{
  reload("firemount_vendor");
  set_name("С��", ({"vendor"}));
  set("shop_id", ({"xiaofan", "vendor"}));
  set("gender", "����");
  set("age", 18);
  set("long","һλ�������ӣ�������һ���쳵����\n");
  set("attitude", "peaceful");
  set("combat_exp", 15000);
  set_skill("dodge", 30);
  set("vendor_goods", ([
         "watermelon" : "/d/obj/food/watermelon",
         "kaoji"       : "/d/obj/food/kaoji",
         "putaogan"    : "/d/obj/food/putaogan",
         "hulu"        : "/d/obj/food/hulu",
         "jiudai"      : "/d/obj/food/niupi-jiudai",
       ]) );
  set("chat_chance",40);
  set("chat_msg",({ 
        "�����ϣ�����\n",
        "������������\n",
        "�����Ѹɣ�����\n",
        "����«������\n",
        "���ƴ�������\n",
        (:random_move:)
      }));
  setup();

  carry_object("/d/obj/cloth/linen")->wear();
  add_money("coin", 500);

}

void init()
{
  object ob;

  ::init();
  add_action("do_vendor_list", "list");
}

