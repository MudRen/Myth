inherit F_VENDOR_SALE;

void create()
{
        set_name("³��", ({ "lu kai", "lu", "kai" }) );
        set("gender", "����" );
        set("age", 32);
        set("long", "�����ľ�����ϰ�³������һ�־�������������\n");
        set("shen_type", 1);
        set("combat_exp", 10000);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
        set("attitude", "peaceful");
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set("chat_chance", 20);
        set("vendor_goods", ([
                "zhuozi": "/d/qujing/baoxiang/obj/zhuozi", 
                "yizi": "/d/qujing/baoxiang/obj/yizi", 
        ]) );

        setup();
        carry_object("/d/obj/cloth/linen")->wear();
        add_money("coin", 100);
}

void init ()
{
  ::init();
  add_action ("do_vendor_list", "list");
}

