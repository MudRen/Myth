inherit NPC;

void create()
{
        set_name("ũ��", ({ "farmer" }) );
        set("gender", "����" );
        set("age", 25+random(20));
        set("long", "�㿴��һλ��ɫ��ڵ�ũ��\n");
        set("combat_exp", 150+random(800));
        set("attitude", "friendly");
        set("env/wimpy", 60);
        set("chat_chance_combat", 50 );
        set("chat_msg_combat", ({
                "ũ��е���ɱ���ģ�ɱ���ģ�\n",
                "ũ��е����������ģ����컯���´���ģ�\n",
                (: command, "surrender" :),
        }) );
        setup();
        add_money("coin", 20);
}

