inherit NPC;
void create()
{
       set_name("��˳", ({"zhang shun", "zhang"}));
	set("long", "һλǿ׳����򣬳�ü����������������ʲô���¡�\n");
       set("gender", "����");
       set("age", 36);
       set("title", "���");
       set("attitude", "peaceful");
       set("shen_type", 1);
        set("combat_exp", 10000);
        set_skill("unarmed", 35);
        set_skill("dodge", 30);
        set_skill("parry", 35);

        setup();
       add_money("coin", 3+random(5));
        carry_object("/obj/cloth")->wear();
}
int accept_object(object who,object ob)
{
        object m;

        int val;
        val = ob->value();
        if( !val )
                return notify_fail("��˳�ѹ���˵����ֻҪǮ��\n");
        else if( val >= 5000 ) {
		command("jump");
		say("��˳˵����" + RANK_D->query_respect(who) + "�ͰѰ���ǣ�߰ɣ�\n");
		say("��˳�ܵ���Ժǣ��ͷ��ĸ������\n");
		m=new("/d/meishan/npc/pigg");
		seteuid(getuid());
		m->move(environment(who));
	        call_out("destroy", 1, ob);
		call_out("leave", 1);
	        return 1;

        }
	say("��˳˵������л����л��\n");
	call_out("destroy", 1, ob);
        return 1;

}
void leave()
{
        message("vision",
               name() + "˵�����»�Ҫ���㣬�����ˡ�\n��˳���˳�ȥ��\n",environment(),
                this_object() );
        destruct(this_object());
}

void destroy(object ob)
{
        destruct(ob);
        return;
}

