// girl.c
inherit NPC;
void create()
{
	set_name("Ů��", ({ "girl", "nu hai", "hai", "nu"}));
	set("gender", "Ů��" );
	set("age", 8+random(8));
	set("long",
		"Ů���ڼ����˷���ι�˼���Ҳ��ûʲô���ˡ�Ҳ�ܵ�ѧ�����������ʡ�\n");
	set("chat_chance", 2);
	set("chat_msg", ({
		"Ů��������ſ޵����������Ҹ����ң�\n",
		"Ů����������ע�⣬�ͳ�һ��С���������ĵؿ�һ��ľ���ӡ�\n",
		"Ů�����Ÿ�������������ȣ�ƨ�ɼ⣬Ҫ�Զ����Ը����壡\n",
        }));
         set("combat_exp", 50+random(50));
        set("attitude", "friendly");
        set_skill("dodge", random(5));
        set_skill("unarmed", random(5));
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin", 70+random(100));
}