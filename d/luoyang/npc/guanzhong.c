inherit NPC;

void create()
{
        set_name("����", ({ "guan zhong", "guan", "zhong" }) );
        set("gender", "����" );
        set("age", 32);
        set("long",
              "һ����ϷԺ�￴Ϸ�Ĺ��ڡ�\n");
        set("shen_type", 1);
        set("combat_exp", 10000);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
        set("attitude", "peaceful");
        set_skill("dodge",20);
        set_skill("unarmed",20);
        set("chat_chance", 1);
        set("chat_msg", ({
                "���ڴ������Ƴƺá�\n",
        }) );       

        setup();
        carry_object("/d/gao/obj/changpao")->wear();
        add_money("coin", 30);
}


