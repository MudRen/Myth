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
        set("str", 100);
        set("kar", 30);

        set("limbs", ({ "ͷ��", "����", "����", "β��" }) );

        set("verbs", ({ "bite" }) );

        set("combat_exp", 3000000);
        set("max_sen", 10000);
        
        set_temp("apply/attack", 45);
        set_temp("apply/damage", 200);
      set_skill("unarmed", 150); 
        set("force_factor", 100); 
        set_temp("armor", 53);
        setup();
}

void die()
{
        object ob;
        message_vision("$N�����³�һ��ҹ���飬��Ƥ����һ����$N���ˡ�\n", this_object());
      ob = new("/d/quest/weapon/tan/item/zhenzhu");
        ob->move(environment(this_object()));
        destruct(this_object());
}

