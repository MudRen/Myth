inherit NPC;

void create()
{
        set_name("��צ����", ({ "golden dragon", "dragon" }) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 100);
        set("long", "һֻ�����׵���צ������\n");
        set("attitude", "peaceful");
        set("looking", "�������ݣ����Ʊ��ˡ�");
        set("str", 40);
        set("con", 40);
        set("max_kee", 2000);
        set("max_sen", 2000);
	set("max_force", 1000);
	set("force", 1500);
	set("max_mana", 1000);
	set("mana", 1500);
	set("force_factor", 50);
	set("mana_factor", 50);
        set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "β��"}) );
        set("verbs", ({ "bite", "claw"}) );
        set("combat_exp", 1400000);
  set("daoxing", 1000000);

	set("eff_dx", -500000);
	set("nkgain", 500);
        set_skill("dodge", 179);
        set_skill("parry", 179);
        set_skill("force", 179);
	set_skill("spells", 179);
        set_skill("unarmed", 179);
        set_temp("apply/damage", 40);
	set_temp("apply/armor", 60);	
	set_weight(5000000);
        setup();
}
void init()
{
        object ob;

        ::init();
        set("chat_chance", 5);
        set("chat_msg", ({
	    "��צ�����ڰ���������˼�Ȧ��\n",
            "��צ��������һ��������\n",
        }) );
}


int heal_up()
{

        if( environment() && !is_fighting() ) {
                call_out("leave", 0);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{       object obj;
	this_object()->add("time", 1);
	if( (int)this_object()->query("time") < 6 )  return;

        message("vision",name() + "��������һ�䣬�ֱ������ģ����\n", environment(), this_object() );
                seteuid(getuid());
                obj=new("/d/qujing/bibotan/npc/longwang");
                obj->move(environment(this_object()));
        destruct(this_object());
}

�