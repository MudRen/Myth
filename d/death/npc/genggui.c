//puti.c
inherit NPC;

void create()
{
       set_name("�����", ({"dageng gui", "gui"}));
       set("gender", "����");
       set("age", 60);
	set("long", "�������൱���ϣ���������С�࣬���ڴ����\n");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 10);
       set("combat_exp", 400+random(100));
	set_skill("unarmed", 5);
	set_skill("dodge", 6);
	set_skill("parry", 4);

set("chat_chance", 8);
set("chat_msg", ({
"����ĺ�����ƽ������ඣ�\n",
"������������´������㼸�ۡ�\n",
(: random_move :)
}) );


setup();

        carry_object("/d/obj/weapon/hammer/gucui")->wield();
}

