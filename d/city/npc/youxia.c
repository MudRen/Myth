#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������", ({ "youxia er","er","xia", "man"}) );
        set("gender", "����");
        set("age", 25);
	set("per", 20+random(5));
        set("long","ʱ������֮�����أ���������ͷҲ�ɿ�����װ�彣���ꡣ\n");
        set("combat_exp", 50000);
        set("attitude", "heroism");
        set("str", 23);
        set("max_kee", 650);
        set("max_gin", 400);
        set("force", 350);
        set("max_force", 350);
        set("force_factor", 15);
        set_skill("sword", 50);
	set_skill("xiaofeng-sword", 40);
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
	map_skill("sword", "xiaofeng-sword");
	map_skill("parry", "xiaofeng-sword");
        setup();
	add_money("silver", 15);
        carry_object("/d/obj/weapon/sword/xijian")->wield();
        carry_object("/d/obj/cloth/bai")->wear();
}
void init()
{
        object ob;

        ::init();
        set("chat_chance", 10);
        set("chat_msg", ({
            "������������Ц��Ц��\n",
            "�������������´������㼸�ۣ��������ǲ�м��\n",
            (: random_move :)
        }) );
}


int accept_fight(object me)
{
        message_vision("����������$NЦ��Ц�����¼��Ǵͽ̣�С�������ˣ�\n", me);
        return 1;
}

