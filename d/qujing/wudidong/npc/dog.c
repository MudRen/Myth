// wilddog.c
inherit NPC; 
void create()
{
        set_name("Ұ��", ({ "dog", "gou"}));
        set("race", "Ұ��");
        set("age", 4);
        set("long",
                "һ���������Ұ���������������������ʲô�Եĸ�����\n");
        set("attitude", "friendly");
	set("str", 26);
	set("cor", 30);
	set("chat_chance", 40);
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set_temp("apply/attack", 5);
        set_temp("apply/damage", 10);
        set_temp("apply/armor", 5);

	set("chat_msg", ({
                (: random_move :)
        }));
        setup();
}
