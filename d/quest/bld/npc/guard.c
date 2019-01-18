//npc--guard

inherit NPC;

#include <ansi.h>

void create()
{
        set_name(HIW"ɽ��"NOR, ({"shan shen", "shen"}));
        set("age", 100);
        set("attitude", "peaceful");
        set("gender", "����");
        set("title", HIC"һ�򵱹�"NOR);
        set("nickname", HIG"���Ī��"NOR);
        set("str", 40);
        set("int", 20);
        set("per", 30);
        set("con", 20);
        set("max_gin", 5000);
        set("max_kee",5000);
        set("max_sen", 5000);
        set("combat_exp", 10000000);
        set("daoxing", 10000000);


        set("force", 14000);
        set("max_force", 14000);
        set("force_factor", 500);
        set("mana",14000);
        set("max_mana", 14000);
        set("mana_factor", 400);
        set_skill("unarmed", 250);
        set_skill("force", 250);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        set_skill("spells", 250);
        set_skill("axe", 250);
        set_skill("sanban-axe",250);
        set_skill("lengquan-force",250);
        set_skill("baguazhou",250);
        set_skill("yanxing-steps",250);
        set_skill("changquan",250);
        map_skill("dodge","yanxing-steps");
        map_skill("unarmed","changquan");
        map_skill("force","lengquan-force");
        map_skill("spells","baguazhou");
        map_skill("axe","sanban-axe");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
        (: exert_function, "powerup" :),
        (: perform_action,"axe", "kai" :),
        (: perform_action,"axe", "sanban" :),
        (: perform_action,"unarmed", "zhiqi" :),         
        }) );


        create_family("������", 2, "��");

        setup();

        add_money("gold", 3);

        carry_object("/d/obj/weapon/axe/huafu")->wield();
        carry_object("/d/obj/armor/tongjia")->wear();

}

