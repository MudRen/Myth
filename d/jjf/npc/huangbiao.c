
inherit NPC;

void create()
{
        set_name("������", ({"huangbiao ma", "ma"}));
        set("race", "Ұ��");
        set("age", 20);
        set("long", "һֻ���ò��ܾ���һ���ë�Ĵ���\n");

	set("combat_exp", 10000);
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite"}));

        set("chat_chance", 1);
        set("chat_msg", ({
                "������ߺߵĽ��˼�����\n"
}));

	set("ride/msg", "��");
        set("ride/dodge", 18);
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 20);

        setup();
}

