inherit F_VENDOR_SALE;

void create()
{
        set_name("�У���", ({"pk wang", "wang", "boss"}));
        set("title", "ɱ�˿�");
        set("gender", "����");
        set("age", 37);
        set("long","ԭ����ɱ�˲�գ�۵�ɱ�˿񣬵����������������������ҩ�ġ�\n");
        set("kee", 900); 
        set("max_kee", 900);
        set("sen", 200);
        set("max_sen", 200);
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("env/wimpy", 50);

        set("vendor_goods", ([
                "yao": "/d/obj/drug/jinchuang",
                "dan": "/d/obj/drug/hunyuandan",
        ]) );


        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
        add_action("do_vendor_list", "list");
}
