//Cracked by Roath

inherit F_VENDOR_SALE;
void create()
{
  reload("wang");
  set_name("����ɩ", ({"wang dasao", "sao", "dasao"}));
  set("title","�Ǻ�«���ϰ���");
  set("gender", "Ů��");
  set("age", 32);
  set("long","һλ���ú��ʴȵ����긾Ů��\n");
  set("attitude", "peaceful");
  set("combat_exp", 15000);
	set("daoxing",15000);	
  set_skill("dodge", 30);
  set("vendor_goods", ([
            "tang" : "/d/jz/obj/tang",
            "hai wan"  : "/d/jz/obj/wan",
                      ]));
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
  add_money("coin", 100);
}
void init()
{
  object ob;
  ::init();
  add_action("do_vendor_list", "list");

}
