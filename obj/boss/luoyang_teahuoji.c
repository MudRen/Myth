inherit F_VENDOR_SALE;

void create()
{
        set_name("���̻��", ({ "chapu huoji", "chapu", "huoji" }) );
        set("gender", "����" );
        set("age", 18);
        set("long",
                "һ���ڲ�������õĻ�ơ�\n");
        set("shen_type", 1);
        set("combat_exp", 10000);
        set("str", 10);
        set("dex", 10);
        set("con", 10);
        set("int", 10);
        set("attitude", "peaceful");
        set_skill("dodge",20);
        set_skill("unarmed",20);
        set("chat_chance", 2);
        set("chat_msg", ({
                "���̻�ƶ�����˵������λ�͹٣��Ȳ���\n",
        }) );       

        set("vendor_goods", ([
                "tea1" : "/d/luoyang/obj/tea1",
                "tea2" : "/d/luoyang/obj/tea2",
                "tea3" : "/d/luoyang/obj/tea3",
                "tea4" : "/d/luoyang/obj/tea4",
                "tea5" : "/d/luoyang/obj/tea5",
        ]) );
        setup();
        carry_object("/d/obj/cloth/linen")->wear();
        add_money("silver", 1);
}
void init()
{

        ::init();
        add_action("do_vendor_list", "list");
}

