// boy.c
inherit NPC;
void create()
{
	set_name("�к�", ({ "boy", "nan hai", "hai", "nan"}));
	set("gender", "����" );
	set("age", 10+random(8));
	set("long",
		"���˵ĺ����統�ҡ����к���Ȼ���󣬵���ˮĥĥ�ģ���Ҳ��ǿ��׳��\n");
	set("chat_chance", 2);
	set("chat_msg", ({
		"�к��������������淳���������Ǳȼ���������ݺ���Щ��\n",
		"�к���������ע�⣬���������֦�����������˹�ȥ��\n",
		"�к����ֳ����������ȣ�ƨ�ɼ⣬Ҫ�Զ����Ը����壡\n",
        }));
        set("combat_exp", 100+random(100));
        set("attitude", "friendly");
        set_skill("dodge", random(10));
        set_skill("unarmed", random(10));
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin", 70+random(100));
}