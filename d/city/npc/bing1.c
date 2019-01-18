inherit NPC;

void create()
{
        set_name("С��", ({ "bing" }));
        set("age", 22);
        set("gender", "����");
        set("long",
"��Щ��ʿ�������屦����ҧ��ȴӲ������������ľ���\n");
        set("attitude", "peaceful");

        set("combat_exp", 10000);

        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("blade", 20);
        set_skill("force", 20);

        setup();
        carry_object(__DIR__"obj/blade")->wield();
        carry_object("/d/obj/cloth/bingfu")->wear();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && 
                (int)ob->query_condition("killer")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}

int accept_fight(object me)
{
        command("say ���ò��ͷ��ˣ�\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

