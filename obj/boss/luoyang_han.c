
inherit F_VENDOR_SALE;

void create()
{
        set_name("����", ({ "han yun", "han", "yun" }) );
        set("gender", "����" );
        set("title", "�������ϰ�" );
        set("age", 32);
        set("long", "�����Ǵ�������ϰ壬���Ļ�����ֱ�Ӵ������ʽ��ġ�\n");
        set("shen_type", 1);
        set("combat_exp", 10000);
        set("daoxing", 10000);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
        set("attitude", "peaceful");
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set("chat_chance", 20);
        set("vendor_goods", ([
                "biyanhu"      : "/d/luoyang/obj/taoci",
                "cima"         : "/d/luoyang/obj/taoci2",
                "putishu"      : "/d/luoyang/obj/taoci3",
                "lianhuazuo"   : "/d/luoyang/obj/taoci4",
                "feitianpei"   : "/d/luoyang/obj/taoci5",
                "guanyinxiang" : "/d/luoyang/obj/taoci6",
                "moyundou"     : "/d/luoyang/obj/taoci7",
                "qingtianjue"  : "/d/luoyang/obj/taoci8",
        ]) );

        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        add_money("coin", 100);
}

void init()
{
        object ob;

        ::init();
        add_action("do_vendor_list", "list");

}

