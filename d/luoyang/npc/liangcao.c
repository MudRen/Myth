inherit NPC;

void create()
{
        set_name("���ݹ�", ({ "liangcao guan", "liangcao", "guan" }) );
        set("gender", "����" );
        set("age", 22);
        set("long", "һ���������ݵ�С�١�\n");
        set("shen_type", 1);
        set("combat_exp", 10000);
        set("str", 10);
        set("dex", 10);
        set("con", 10);
        set("int", 10);
        set("attitude", "peaceful");
        set_skill("dodge",20);
        set_skill("unarmed",20);

        setup();
        carry_object("/d/obj/cloth/jinpao")->wear();
        add_money("coin", 200);
}

