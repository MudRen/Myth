inherit NPC;

string *first_name = ({ "��","Ǯ","��","��","��","��","֣","��"});

void create()
{	string name;
	name=first_name[random(sizeof(first_name))];
	name += "���";
        set_name(name, ({"xiucai"}));
        set("age", 18+random(40));
        set("gender", "����");
        set("long","һ��������������Ƶ�����\n");
        set("attitude", "friendly");
        set("combat_exp", 3000);
        set_skill("unarmed", 10);
        set_skill("dodge", 20);
        set("chat_chance", 10);
        set("chat_msg", ({
		"���Ц��Ц��\n",
		"���������üͷ��\n",
                (: random_move :)
        }));

        setup();

        carry_object("/d/gao/obj/changpao")->wear();
}

