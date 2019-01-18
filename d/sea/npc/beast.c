
inherit NPC;
string *first_name = ({ "��Ƥ", "����", "��צ���", "��β���"});
string *name_words = ({ "��"});


void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];


        set_name(name,({"dragon"}));


	set("race", "Ұ��");
        set("long", "һֻģ���ߴ󣬼������Ƶ�����\n");
        set("str", 40);
        set("cor", 30);
        set("con", 30);
        set("cps", 30);
        set("spi", 30);
        set("int", 30);
        set_temp("apply/damage", 25);
        set_temp("apply/armor", 50);
        set("max_kee", 800);
        set("max_sen", 800);
        set("force", 1000);
        set("max_force", 500);
        set("force_factor", 25);
        set("mana", 1000);
        set("max_mana", 500);
        set("mana_factor", 25);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("dragonfight", 50);
        set_skill("dragonstep", 50);
        map_skill("unarmed", "dragonfight");
        map_skill("dodge", "dragonstep");
        set("combat_exp", 100000);
  set("daoxing", 150000);

        set("limbs", ({ "ͷ��", "����", "ǰצ", "β��", "��Ƥ", "��צ"}) );
        set("verbs", ({ "bite", "claw"}) );
        set_weight(500000);
	set("bellicosity",1000);

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
		return notify_fail("��ֻ������ս����\n");
	if((string)who->query("family/family_name")!="��������")
		return notify_fail("ʲô��\n");
	
	call_out("reset_skill",1,who);

	message_vision("$N��$n��һ�������󣬿�����񵽼�ʱ��\n\n", who,me);
	message_vision("$Nһ����������������$nŤ��һ��\n",me,who);
	me->kill_ob(who);
	who->kill_ob(me);
        COMBAT_D->do_attack(me, who, query_temp("weapon"));
	me->set("owner",who->query("id"));
	return 1;
}

int reset_skill(object who)
{
	object me=this_object();
	int exp,i;
	exp=(int)who->query("combat_exp");


        if( exp > 1000000) {  
                i=190;
        }else if( exp >900000){
                i=180;
        }else if( exp >800000){
                i=170;
        }else if( exp >700000){
                i=160;
        }else if( exp >600000){
                i=150;
        }else if( exp >500000){
                i=140;   
        }else if( exp >400000){
                i=130;
        }else if( exp >300000){
                i=120;
        }else if( exp >200000){
                i=110;
        }else if( exp >100000){
                i=100;
        }else if( exp >90000){
                i=90;
        }else if( exp >80000){
                i=80;
        }else if( exp >70000){ 
                i=70;
        }else if( exp >60000){
                i=60;
        }else if( exp >50000){
                i=50;
        }else{
	 	i=50;
	}
	me->set("combat_exp", (int)who->query("combat_exp")*12/10);
	me->set_skill("dodge", i+random(10));
        me->set_skill("parry", i+random(10));
        me->set_skill("unarmed", i+random(10));
        me->set_skill("dragonfight", i+random(10));
        me->set_skill("dragonstep", i+random(10));
	me->set("force_factor", i/3);
  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("sen", (int)me->query("max_sen"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("gin", (int)me->query("max_gin"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("kee", (int)me->query("max_kee"));



	return 1;
}

void die()
{
	string owner;
	object owner_ob;

	owner = query("owner");
	if(owner) owner_ob= find_player(owner);

	if(owner_ob &&  (object)query_temp("last_damage_from") == owner_ob ) {
		if( (int)owner_ob->query_skill("seashentong",1) <=200 
		&& (int)owner_ob->query_skill("spells",1) <=200 ) {
		tell_object(owner_ob, "\n��ѱ���˶��������Ҵ�������һЩ�����ĵ���\n");
		owner_ob->improve_skill("spells", random(owner_ob->query("spi"))+1);
		owner_ob->improve_skill("seashentong", random(owner_ob->query("spi"))+1);
		owner_ob->set_temp("dragonforce_practice",
owner_ob->query("spi")*3+random(30));
		message_vision("$N��ͷ��β����ʾ������\n",this_object());
		destruct(this_object());
		return;
		}
	}
	::die();
}
�