
inherit NPC;
inherit F_VENDOR;

void create()
{
       set_name("��С��", ({"xiao er","xiaoer","xiao","waiter","wang"}));
       set("gender", "����");
        set("combat_exp", 3000);
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
        set("vendor_goods", ([
                "jiuping": "/d/obj/food/baijiu",
                "jitui": "/d/ourhome/obj/jitui",
                "huasheng": "/d/ourhome/obj/huasheng",
        ]) );

       setup();
       carry_object("/d/obj/cloth/linen")->wear();
       add_money("silver", 1);
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {  // 1/3 chance to greet.
                case 0:
                        say( "��С��Ц�����˵������λ" +
RANK_D->query_respect(ob)
                                + "������ЪЪ�ţ�������ůů���ӣ�\n");
                        break;
        }
}

