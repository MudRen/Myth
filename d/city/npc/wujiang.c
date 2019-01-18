// wujiang.c �佫

inherit NPC;

#include <greeting.h>

void create()
{
        set_name("�س��佫", ({ "wu jiang", "wu", "jiang" }));
        set("gender", "����");
        set("age", random(10) + 30);
        set("str", 25);
        set("long", "���������ݣ�ɱ�����ڣ���Ȼֻ�Ǹ��س��ŵ�С�٣�����Ҳ�Ǵ�����̵ġ�\n");
        set("combat_exp", 80000);
        set("attitude", "peaceful");

        set_skill("unarmed", 70);
        set_skill("force", 70);
        set_skill("sword", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
	set("max_kee", 700);
	set("max_sen", 600);
        set("force", 400); 
        set("max_force", 400);
        set("force_factor", 15);
	set("max_mana", 100);
	set("mana", 100);
	set("mana_factor", 5);
        setup();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
        carry_object("/d/obj/armor/tiejia")->wear();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && 
                (int)ob->query_condition("killer")) {
//                remove_call_out("kill_ob");
//                call_out("kill_ob", 1, ob);
        }
        greeting2(this_player());
}
int accept_fight(object me)
{
        message_vision("�س��佫��$N����һ�ɣ��ȵ���߾���󵨣��������£�\n\n", me);
        return 0;
}

