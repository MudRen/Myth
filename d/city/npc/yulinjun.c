
inherit NPC;

void create()
{
        set_name("Уξ", ({ "xiao wei", "wei", "guard" }) );
        set("gender", "����");
        set("age", 25);
        set("long",

"����λ�ػ��ʳǵĽ����ʿ������ͭ�ף���ִ��ϡ�
��˫Ŀ���⾼���������Ѳ�������ܵ����Ρ�\n");
        set("combat_exp", 220000);
	set("title", "���־�");
        set("attitude", "heroism");
        set("str", 25);
        set("max_kee", 850);
        set("max_sen", 600);
        set("force", 400);
        set("max_force", 400);
        set("force_factor", 20);
        set_skill("hammer", 80);
        set_skill("unarmed", 80);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("force", 80);
        setup();

        carry_object("/d/obj/weapon/hammer/jingua")->wield();
        carry_object("/d/obj/armor/tongjia")->wear();
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
        message_vision("���־���ʿ��$N���һ�������ò��ͷ��ˣ��ʹ�ǰҲ�Һ��֣�\n", me);
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

