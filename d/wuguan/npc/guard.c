//Cracked by Roath

inherit NPC;

void create()
{
       set_name("����", ({"guard"}));
       set("long", "������ݵĿ����ˣ����ڴ��˯��\n");
       set("title", "�ŷ�");
       set("gender", "����");
        set("combat_exp", 2000);
	set("per", 18);
       set("age", 56);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set_skill("unarmed", 15);
        setup();
       add_money("silver", 5);
}

