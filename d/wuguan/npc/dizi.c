//Cracked by Roath
inherit NPC;

void create()
{
        int skill;

set_name("��ݵ���", ({"wuguan dizi", "dizi", "trainee" }) );
        set("gender", "����" );
        set("age", 18+random(10));
        set("long", "һλ��ĸߴ�ĺ��ӣ���������ز����š�\n");

        skill=random(30)+10;
        set("combat_exp", 600+skill*10);


        set_skill("dodge", 10);
        set_skill("unarmed", 10);

        setup();
	add_money("coin", 100+random(200));
        carry_object("/d/obj/cloth/linen")->wear();
}

