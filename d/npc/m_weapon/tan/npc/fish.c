// animal: eat_fish.c
// Jay 3/18/96

inherit NPC;

void create()
{
        set_name("������", ({ "fish", "yu" }) );
        set("race", "Ұ��");
        set("age", 3);
        set("long", "����һֻ���β����ܴ���㣬������Ѥ������Ƭ��\n"
            "һ�ڷ��������ݣ������ӵ����Ŀ�����\n");
        set("attitude", "aggressive");

        set("max_kee",10000);
        set("str", 26);
        set("kar", 30);

        set("limbs", ({ "ͷ��", "����", "����", "β��" }) );

        set("verbs", ({ "bite" }) );

        set("combat_exp", 3000000);
        set("max_sen", 6000);
        
        set_temp("apply/attack", 45);
        set_temp("apply/damage", 60);
        set_temp("armor", 53);
        setup();
}

void die()
{
        object ob;
        message_vision("$N�����³�һ��ҹ���飬��Ƥ����һ����$N���ˡ�\n", this_object());
      ob = new("m_weapon/tan/item/zhenzhu");
        ob->move(environment(this_object()));
        destruct(this_object());
}

