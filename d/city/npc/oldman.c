inherit NPC;

void create()
{
        set_name("������", ({"bai shiqin", "bai", "shiqin"}));
        set("gender", "����");
        set("age", 65);
        set("long",
"һ�����ľ��������ˣ��������ѧ�ʵ����ӡ�\n");
	set("attitude", "friendly");
        set("combat_exp", 1000);
	set("per", 25);
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        setup();

        carry_object("/d/gao/obj/changpao")->wear();
        add_money("coin", 100);

}
int accept_fight(object me)
{
        command("say �Բ�ס��С�϶��Ϲ�ͷ������ѽ��");
        return 0;
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
                        say( "�ϰ�ͷЦ�����˵������λ" +
RANK_D->query_respect(ob)
                                + "����д�Ż���д״��ѽ��\n");
                        break;
        }
}

