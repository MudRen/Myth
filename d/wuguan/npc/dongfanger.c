//Cracked by Roath
inherit NPC;

void create()
{

        set_name("����С����", ({ "dongfang sister", "dongfang", "sister"}) );
        set("gender", "Ů��");
        set("age", 16);
	set("per", 28);
        set("long", "����С�����ǹ�����Զ��ֶŮ���������������档\n");
        set("combat_exp", 5000);
	set("max_kee", 300);
	set_skill("sword", 10);
	set_skill("parry", 10);
        set_skill("dodge", 30);
        set_skill("unarmed", 20);
	set_skill("force", 20);
set("chat_chance", 3);
set("chat_msg", ({
"С����˵�����Һ�ϲ�����ϣ�\n",
"С����˵��������Ļ��������ϣ�\n",
}) );

        setup();
        add_money("silver", 1+random(20));
        carry_object("/d/obj/cloth/pink_cloth")->wear();
	carry_object("/d/obj/cloth/bullboots")->wear();
}

int accept_object(object who,object ob)
{
        object m;
        if (ob->query("id")=="flower") {
                say("С����Ц������л"  + RANK_D->query_respect(who) + "������ĺ�ϲ���ϣ�\n");
		command("whisper " + who->query("id") + " �������о˹���һ���飬����ȥ���ɣ�\n");
        m=new("/d/obj/book/forcebook");
        m->move(who);
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

