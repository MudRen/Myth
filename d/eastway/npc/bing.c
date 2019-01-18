inherit NPC;

void create()
{
        set_name("С��", ({ "xiao bing", "bing" }));
        set("age", 18+random(10));
        set("gender", "����");
        set("attitude", "peaceful");
	set("str", 20);
        set("combat_exp", 20000);
	set("max_kee", 400);
	set("max_sen", 400);
	set("max_force", 200);
	set("force", 200);
	set("force_factor", 10);
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("blade", 40);
        set_skill("force", 40);

        setup();
        carry_object("/d/obj/weapon/blade/blade")->wield();
        carry_object("/d/obj/armor/tiejia")->wear();
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
        message_vision("С����$N�ȵ����󵨵��񣬻�ò��ͷ��ˣ�\n", me);
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

