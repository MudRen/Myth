inherit F_VENDOR_SALE;
void create()
{
    reload("milin_shizhe");
       set_name("密林使者", ({"milin shizhe", "shizhe"}));
       set("long",
"这人看起来一副阴森样,看上去并不像是什么好人,
可能只是打着密林使者的旗号,招谣撞骗!\n");
       set("gender", "男性");
        set("title", "森林守卫");
        set("combat_exp", 10000);
       set("age", 28);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
       set("vendor_goods", ([
//                "qkl": "/d/calvin/obj/qkl",
//              "yao": "/d/obj/drug/后悔药",
//                "pifeng": "/d/obj/cloth/绣锦披风",
//              "jiezhi" : "/d/obj/其他/天绝戒指",
//        "dan": "/d/obj/drug/yundan", 
       ]) );
        setup();
       add_money("silver", 5);
        carry_object("/d/obj/cloth/linen")->wear(); 

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
        switch( random(1) ) {
                case 0:
                        say(name()+ "阴森森的走到你身后：这位" +
RANK_D->query_respect(ob)
                                + "，想要些好东西吗?\n");
                        break;
        }
}

void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("help!");

        ob=present("xunluo guanbing");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/city/npc/xunluobing");
                ob->move(environment());
        }

message_vision("\n忽然从远处跑过来个巡逻官兵，对$N大喊一声“干什么？想杀人谋财么！\n\n",me);  

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
}
int regenerate()
{
        set("called", 0);
        return 1;
}
