
inherit NPC;
void create()
{
       set_name("��ף", ({"miao zhu", "keeper"}));
	set("long", "�����������ף��\n");
       set("gender", "����");
       set("age", 46);
       set("attitude", "peaceful");
       set("shen_type", 1);
        set("combat_exp", 5000);
        set_skill("unarmed", 35);
        set_skill("dodge", 30);
        set_skill("parry", 15);
set("inquiry", ([
"����": "ʱ����Ҫһͷ��\n",
"here": "��������Ҳ������Ĺ������������ᱣ���㡣\n",
]) );

        setup();
       add_money("silver", 3+random(5));
        carry_object("/d/ourhome/obj/choupao")->wear();
}
void init()
{       
        object ob=this_player();

        ::init();

                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        switch( random(1) ) {
                case 0:
                message_vision("$N˵����ֻҪ���Ĺ������������ᱣ���㡣\n",
this_object());
                break;
        }
}

int accept_object(object who,object ob)
{
        object m;
        if (ob->query("id")=="old pig") {
                say("��ףЦ������л"  + RANK_D->query_respect(who) +
"������������ᱣ���㡣\n");
	who->set_temp("erlangpass", 1);
        call_out("destroy", 1, ob);
        return 1;
        }
        else return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}

