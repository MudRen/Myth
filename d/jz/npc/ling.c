//Cracked by Roath
inherit F_VENDOR_SALE;
void create()
{
    reload("ling");
        set_name("����Բ", ({"ling", "ling tangyuan", "tangyuan"}));
        set("title", "��Բ���ϰ�");
        set("gender", "����");
        set("age", 42);
        set("long", "һ���������ܾ��������ˡ�\n");
   set("str", 30);
   set("con", 30);
   set("spi", 30);
        set("combat_exp", 20000);
	set("daoxing",20000);	
        set_skill("force", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
   set("force", 200);
   set("max_force", 200);
   set("force_factor", 5);
        set("vendor_goods", ([
               "redty": "/d/jz/obj/ty1",
                 "greenty": "/d/jz/obj/ty2",
                "blackty": "/d/jz/obj/ty3",
                "yellowty": "/d/jz/obj/ty4",
        ]) );
        setup();
   add_money("silver", 20);
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
     call_out("greeting",1,ob);
        }
        add_action("do_vendor_list", "list");

}
void greeting(object ob)
{
    if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say( name()+"Ц������������Բ�ɣ�\n");
                        break;
        }
}
