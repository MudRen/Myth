a
inherit NPC;
void create()
{
        set_name("����",({"fu shang","fu","shang"}));
        set("gender", "����");
        set("age", 35);
        set("long", "���������ı�������\n");
        set("combat_exp", 3600);
        
        set_skill("unarmed", 20);
        set_skill("dodge", 40);
        set_skill("parry", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 30);
        set_temp("apply/armor", 15);
        set_temp("apply/damage", 5);
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        add_money("silver", 80);
}

