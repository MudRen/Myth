inherit NPC;
string *first_name = ({ "������", "�����", "������", "����ʥĸ", "����ʥĸ", "�౦����"});

void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];

        set_name(name, ({ "mo" }) );
        set("race", "����");
        set("age", 3000);
        set("long", "��ħ����������Ž�����(xiang)��\n");
        set("str", 20);
        set("cor", 30);
        set("max_force", 3000);
        set("mana", 4000);
        set("force", 4000);
        set("max_mana", 3000);
        set("force_factor", 100);
        set("mana_factor", 150);
        set("max_kee", 2000);
        set("max_sen", 2000);
        set("verbs", ({ "bite", "claw"}) );

        set("combat_exp", 1000000+random(1000000));
  set("daoxing", 5000000);

    set_skill("dodge", 160);
	set_skill("unarmed", 100);
    set_skill("parry", 160);
    set_skill("moshenbu", 160);
    set_skill("force", 160);
    set_skill("wuxiangforce", 160);
    set_skill("sword", 200);
    set_skill("sanqing-jian", 200);
    set_skill("dao", 200);
    set_skill("spells", 200);
       map_skill("force", "wuxiangforce");
       map_skill("parry", "sanqing-jian");
       map_skill("sword", "sanqing-jian");
       map_skill("dodge", "moshenbu");
       map_skill("spells", "dao");
         set("chat_chance_combat", 30);
         set("chat_msg_combat", ({
	(: cast_spell, "light" :),
	(: cast_spell, "thunder" :),
	(: cast_spell, "dingshen" :)
       }));
        set_temp("apply/armor", 80);
        setup();
        carry_object("/d/zhuxian/obj/jia")->wear();

        carry_object("/d/zhuxian/obj/sword")->wield();
}


void init()
{
        ::init();
        add_action("do_dou", "xiang");
}

int do_dou()
{
        object me,who;
        me =this_object();
        who=this_player();

        if(me->is_fighting())
                return notify_fail("����������Ҫ����\n");
        message_vision("$N��$n��һ�������У�\n\n", who,me);
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
                owner_ob->add_temp("mark/��", 10);
                owner_ob->add_temp("mark/��", 10);
        message_vision("$N�ȵ����ݵò��񣬴��һؼ�ȡ���������㡣\n",this_object());
		destruct(this_object());
		return;
        }
        ::die();
}

��
