// created 4/4/1997 by snowcat


inherit F_VENDOR_SALE;

void create()
{
  string dir;
  reload("nuerguo_old_woman");
  set_name("������", ({"old woman", "woman"}));
  set("shop_id", ({"popo", "woman"}));
  set("gender", "Ů��" );
  set("age", 65);
  set("long", "һλ�׷��Բԣ������˪�������š�\n");
  set("combat_exp", 100);
  set("attitude", "peaceful");
  set("per", 15);
/*
  dir = __DIR__;
  dir[strlen(dir)-4] = 0;
*/
  dir = "/d/qujing/nuerguo/";
  set("vendor_goods", ([
        "doufu"    : dir+"obj/qiongyao",
        "huasheng"    : dir+"obj/huasheng",
        "hulu"     : "/d/obj/food/hulu",
      ]));
  setup();
  carry_object("/d/qujing/nuerguo/obj/skirt")->wear();
  add_money ("silver", 2);  
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

