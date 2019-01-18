#include <ansi.h>

inherit NPC;

#include <greeting.h>

void create()
{
        set_name("�����ʿ", ({ "wei shi", "shi", "guard" }) );
        set("gender", "����");
        set("age", 35);
        set("long",
"����λ�ػ��ʳǵĽ����ʿ������ͭ�ף���ִ��ϡ�
��˫Ŀ���⾼���������Ѳ�������ܵ����Ρ�\n");
        set("combat_exp", 130000+random(40000));
        set("attitude", "heroism");

        set("str", 30);
        set("max_kee", 750);
        set("max_gin", 500);
        set("force", 400);
        set("max_force", 400);
        set("force_factor", 25);
        set_skill("hammer", 80);
        set_skill("unarmed", 80);
        set_skill("parry", 80);
        set_skill("dodge", 80);

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
        greeting1 (this_player());
}

int accept_fight(object me)
{
        message_vision("�����ʿ��$N���һ�������ò��ͷ��ˣ��ʹ�ǰҲ�Һ��֣�\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

