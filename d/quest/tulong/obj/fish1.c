inherit NPC;

void create()
{
        set_name("���", ({ "fish monster", "fish" }) );
        set("race", "Ұ��");
        set("age", 300);
        set("long", "����һֻ���κܴ��ѳɾ��ֵ��㣬������Ѥ������Ƭ��\n"
            "һ�ڷ��������ݣ������ӵ����Ŀ�����\n");
        set("attitude", "aggressive");

        set("max_kee",10000); 
        set("max_sen",10000);
        set("max_force",10000);
        set("str", 26);
        set("cor", 30); 
        set("dex", 30);
        set("limbs", ({ "ͷ��", "����", "����", "β��" }) );

        set("verbs", ({ "bite" }) );

        set("combat_exp", 500000);
        
        set_temp("apply/attack", 300);
        set_temp("apply/damage", 300);
        set_temp("armor", 800);
        setup();
}

void die()
{
        object ob;
        message_vision("$N�����³�һ���ڵ�����Ƥ����һ����$N���ˡ�\n", this_object());
        ob = new("/d/quest/tulong/obj/neidan");
        ob->move(environment(this_object()));
        destruct(this_object());
}


