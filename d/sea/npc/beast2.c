inherit NPC;
string *first_name = ({ "��ͷ", "��β"});
string *name_words = ({ "��"});

void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];

        set_name(name, ({ "yuan" }) );
        set("race", "Ұ��");
        set("age", 20);
	set("attitude", "aggressive");
        set("long", "һֻ��ģ������������\n");
        set("str", 20);
        set("cor", 30);
        set("max_kee", 1200);
        set("max_sen", 1200);
        set("limbs", ({ "ͷ��", "����", "���", "β��", "��Ƥ"}) );
        set("verbs", ({ "bite", "claw"}) );

        set("combat_exp", 170000+random(100000));
  set("daoxing", 200000);

	set_skill("dodge", 140);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
        set_temp("apply/damage", 25);
        set_temp("apply/armor", 80);
	set_weight(500000);
        setup();
}


void init()
{
        ::init();
        set("chat_chance", 5);
        set("chat_msg", ({
            (: random_move :)
        }) );

        add_action("do_train", "train");
}

int do_train()
{
        object me,who;
        me =this_object();
        who=this_player();

        if(me->is_fighting())
                return notify_fail("��ֻ��������ս����\n");
        if((string)who->query("family/family_name")!="��������")
                return notify_fail("ʲô��\n");
        message_vision("$N��$n��һ�������󣬿�����񵽼�ʱ��\n\n", who,me);
        message_vision("$N��������$nŤ��һ��\n",me,who);
        me->kill_ob(who);
        who->kill_ob(me);
//        COMBAT_D->do_attack(me, who, query_temp("weapon"));
        me->set("owner",who->query("id"));
        return 1;
}
void die()
{
        string owner;
        object owner_ob;

        owner = query("owner");

	if(!owner) return ::die(); // added by mon.

        owner_ob= find_player(owner);

        if( owner_ob && (object)query_temp("last_damage_from") == owner_ob ) {
                owner_ob->add_temp("dragonforce_practice", owner_ob->query("spi")*2);
		message_vision("$N��ͷ��β����ʾ������\n",this_object());
		destruct(this_object());
		return;
        }
        ::die();
}

�