inherit NPC;

void create()
{
       set_name("�ⱾǮ", ({"wu benqian","wu","nomoney"}));
       set("gender", "����");
        set("combat_exp", 8000);
       set("age", 36);
       set("per", 18);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_skill("dodge", 20);
        setup();
       add_money("gold", 1);
	carry_object("/d/obj/cloth/choupao")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say( "�ⱾǮЦ�����˵������λ" +
RANK_D->query_respect(ob)
                                + "��������㿴����\n");
                        break;
        }
}

