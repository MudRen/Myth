inherit NPC;

void create()
{
        set_name("½��Ԩ", ({"lu jiuyuan", "lu"}));
        set("gender", "����");
	set("title", "������");
        set("age", 55);
        set("str", 25);
        set("long", "½��Ԩ�ǳ�͢�����ɣ�ר������Ӵ���\n");
        set("combat_exp", 30000);
  set("daoxing", 50000);

        set("attitude", "friendly");
	set("force_factor", 10);
        set_skill("unarmed", 80);
        set_skill("dodge",80);
        set_skill("parry", 50);

        set("force", 500); 
        set("max_force", 500);

        setup();
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
                        say( "½��ԨЦ�����˵������λ" +
RANK_D->query_respect(ob)
                                + "����ӭ���Ҵ��ƣ�\n");
break;
        }
}

�
