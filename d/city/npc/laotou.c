inherit NPC;

void create()
{
        set_name("��ͷ", ({"lao tou", "tou"}));
        set("gender", "����");
        set("age", 65);
	set("con", 30);
	set("spi", 30);
        set("long",
"һ����ͷ�����ﻹ����һ����ƿ�ӡ�\n");

        set("combat_exp", 200);

        setup();

        carry_object("/d/obj/cloth/linen")->wear();
        carry_object("/d/city/obj/youping")->wield();
        add_money("coin", 30);

}

