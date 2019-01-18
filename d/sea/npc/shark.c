inherit NPC;
string *first_name = ({ "��Ƥ", "�̱�", "˫ͷ", "����"});
string *name_words = ({ "��"});

void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];

        set_name(name, ({ "shark" }) );
        set("race", "Ұ��");
        set("age", 20);
        set("long", "һֻģ���׶�Ĵ����㡣\n");
        set("str", 20);
        set("cor", 30);
        set("max_kee", 800);
        set("max_sen", 800);
        set("limbs", ({ "ͷ��", "����", "ǰ��", "β��", "��Ƥ"}) );
        set("verbs", ({ "bite"}) );

        set("combat_exp", 100000+random(10000));
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 20);
	set_weight(500000);
        setup();
}


void init()
{
        ::init();
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
        COMBAT_D->do_attack(me, who, query_temp("weapon"));
        me->set("owner",who->query("id"));
        return 1;
}
void die()
{
        string owner;
        object owner_ob;

        owner = query("owner");

	if(!owner) {
          ::die(); // added by mon.
          return;
        }

        owner_ob= find_player(owner);

        if( owner_ob && (object)query_temp("last_damage_from") == owner_ob ) {
                owner_ob->add_temp("dragonforce_practice",
owner_ob->query("spi")*2+random(30));
		message_vision("$N��ͷ��β����ʾ������\n",this_object());
		message_vision("$N������������ˡ�\n",this_object());
		destruct(this_object());
		return;
        }
        ::die();
}

