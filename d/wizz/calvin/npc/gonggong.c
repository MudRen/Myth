inherit F_VENDOR_SALE;
int random_go(object me, string* dirs);

// #include <norumor.c>
void create()
{
       set_name("����", ({"gonggong","gong"}));
       set("title","����԰");
       set("gender", "����");
        set("combat_exp", 100000);
       set("age", 45);
       set("per", 27);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
       set("max_price",20);
        set("vendor_goods", ([
        ]) );

        if( clonep() ) CHANNEL_D->register_relay_channel("rumor");
       setup();

       carry_object("/u/calvin/armor/jinlingpao")->wear();
       add_money("gold", 1);
}

int accept_object(object who, object ob)
{
    int value;

        if (ob->query("money_id") && (value=ob->value()) >= 1000000) 
        {
                tell_object(who, name()+
                        "һ����������С��˵��:ȥ��,����˷����ˡ�\n");
                who->set_temp("rent_paid",1);
                take_money(value, 100000);
                return 1;
        }
        return 0;
}
