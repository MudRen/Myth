inherit NPC;

void create()
{
        set_name("�����", ({ "xiu cai", "xiu", "cai" }) );
        set("gender", "����" );
        set("age", 28);
        set("long",
                "һ�����ݵ���ţ�ûʲôѧ��ȴ����ѧʿԨ����\n");
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
        carry_object("/d/obj/cloth/linen")->wear();
        add_money("coin", 200);
}

