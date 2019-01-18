// guang.c

inherit NPC;
inherit F_MASTER;
int borrow_me(object ob);
int borr_me(object ob);
void create()
{
        set_name("������", ({"guang xizi", "guang"}));
        set("title", "�����ܹ�");
        set("gender", "����" );
        set("age", 53);
        set("long", "һ����������ü��Ŀ�ĵ�ʿ��������һ��������ţ�\n");
	set("class", "toaist");
        set("combat_exp", 180000);
	set("daoxing", 250000);

        set("attitude", "friendly");
	set("force", 400);
	set("max_force", 400);
	set("force_factor", 40);
	set("max_mana", 400);
	set("mana", 400);
	set("mana_factor", 30);
	set("max_kee", 800);
	set("max_sen", 800);

        set("eff_dx", 60000);
        set("nkgain", 250);

	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("puti-zhi", 80);
	set_skill("jindouyun", 80);
	set_skill("unarmed", 80);
	set_skill("jindouyun", 80);
	set_skill("literate", 100);
	map_skill("dodge", "jindouyun");
	map_skill("unarmed", "puti-zhi");
        set("per", 30);
	set("str", 25);
        create_family("����ɽ���Ƕ�", 2, "����");

	set("inquiry", ([
                "book": "�����������ǵ��̾��䣬Ҳ��Щƽ���鼮��",
		"ǧ����": (: borrow_me :),
		"���¾�": (: borr_me :),
        ]) );
	set("chat_msg", ({
		"������Ц��������������ɹ��ˣ�\n",
}));
	set("chat_chance", 5);
        setup();
        carry_object("/d/lingtai/obj/cloth")->wear();
	carry_object("/d/lingtai/obj/daoguan")->wear();
}
int borr_me(object ob)
{       object m;
        ob = this_player();
        if ((string)this_player()->query("family/family_name")=="����ɽ���Ƕ�") {
                if ( this_player()->query("pending/book")) {
			message_vision("$N��$n˵���ϴν�Ļ�û������ô���ٽ�����أ�\n", this_object(), ob);
                	return 1;
		}
		if( (int)this_player()->query_skill("literate", 1) < 10 ) {
			message_vision("$N��$n˵�������д��̫���������Ҳ����������\n", this_object(), ob);
			return 1;
		}
		if ( (int)this_object()->query("daode") ) {
			message_vision("$Nһ���֣�˵���ս��ȥ�����������ɣ�\n", this_object());
			return 1;
		}
                m=new("/d/obj/book/daode");
                m->move(ob);
                ob->set("pending/book", 1);
		this_object()->set("daode", 1);
		message_vision("$N�Ӽ������±������ݸ�$n��˵����סҪ��ࡣ�\n", this_object(), ob);
                return 1;
        }
	message_vision("$N˵������������鲻��裡\n", this_object());
	return 1;
}

int borrow_me(object ob)
{	object m;
	ob = this_player();
        if ((string)this_player()->query("family/family_name")=="����ɽ���Ƕ�") {
                if ( this_player()->query("pending/book")) {
                        message_vision("$N��$n˵���ϴν�Ļ�û������ô���ٽ�����أ�\n", this_object(), ob);
                        return 1;
                }
		if( (int)this_player()->query_skill("literate", 1) < 10 ) {
                        message_vision("$N��$n˵�������д��̫���������Ҳ����������\n", this_object(), ob);
                        return 1;
                }

                if ( (int)this_object()->query("qian") ) {
                        message_vision("$Nһ���֣�˵���ս��ȥ�����������ɣ�\n", this_object());
                        return 1;
                }
                m=new("/d/obj/book/qian");
                m->move(ob);
                ob->set("pending/book", 1);
                this_object()->set("qian", 1);
                message_vision("$N�Ӽ������±������ݸ�$n��˵����סҪ��ࡣ�\n", this_object(), ob);
                return 1;
        }
        message_vision("$N˵������������鲻��裡\n", this_object());
        return 1;

}

int accept_object(object who,object ob)
{
       	if (ob->query("id")=="qian") {
 		if ( this_player()->query("pending/book") ){
		say("�����ӹ���Ц�˼������ý�û����ٽ費�ѣ�\n");
		who->set("pending/book", 0);
		this_object()->delete("qian");
       		call_out("destroy", 1, ob);
        	return 1;
		}
		else 
		say("������Ц������л����л��\n");
	        call_out("destroy", 1, ob);
		return 1;
		}
	if (ob->query("id")=="daodejing") {
        	if ( this_player()->query("pending/book") ){
               	say("�����ӹ���Ц�˼������ý�û����ٽ費�ѣ�\n");
       		who->set("pending/book", 0); 
		this_object()->delete("daode");
        	call_out("destroy", 1, ob);
        	return 1;
		}
		else
		say("������Ц������л����л��\n");
                call_out("destroy", 1, ob);
                return 1;
		}
	if (ob->query("id")=="songguo") {
		say("������Ц������л����л��������ˣ�\n");
		who->set("pending/book", 0);
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

