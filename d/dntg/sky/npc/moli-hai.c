//modified by vikee for xlqy for NK_DX
//2000-11-23 16:21


inherit NPC;
void create()
{
        set_name("ħ��", ({ "moli hai", "duowen tianwang", "hai", "tianwang" }) );
        set("gender", "����" );
	set("long",
		"ħ���Ľ�֮һ��ʹһ��������������һ�����ã����������ң�Ҳ��\n"
                "�ء�ˮ���𡢷磬������������������������ƽ�һ�㡣\n"
	);
	set("age",50);
	set("title", "��������");
	set("attitude", "heroism");
	set("str",40);
	set("int",30);
	set("max_kee",3100);
	set("kee",3100);
	set("max_sen",3100);
	set("sen",3100);
	set("combat_exp",3000000);
        set("daoxing",3000000);
	set("force",2500);
	set("max_force",1500);
	set("mana",2500);
	set("max_mana",1600);
	set("force_factor", 120);
	set("mana_factor",120);

        set("eff_dx", 1500000);
        set("nkgain", 800);
	
	set_skill("unarmed",240);
	set_skill("yingzhaogong", 240);
	set_skill("parry",240);
	set_skill("dodge",240);
	set_skill("stick",240);
	set_skill("kusang-bang",240);
	set_skill("force",240);
	set_skill("spells", 240);
	set_skill("moshenbu", 240);
	map_skill("dodge", "moshenbu");
	map_skill("parry", "kusang-bang");
	map_skill("stick", "kusang-bang");
	map_skill("unarmed", "yingzhaogong");
	set("inquiry", ([
		"name" : "���¶�������ħ�񺣣���ʥ�Ͱ��ر����š�",
		"here" : "������Ǳ�����, ���ھ�������ˡ�",
	]) );

	setup();
	carry_object("/d/sea/obj/dragonstick")->wield();
	carry_object("/d/obj/armor/jinjia")->wear();
}


int accept_fight(object me)
{
        object ob=this_object();

    if( living(ob) )
      {
        message_vision("$N˵����ҲҪ��֪����������������\n", ob);
      }
        return 1;
}

void kill_ob (object me)
{
        object ob=this_object();

    if( living(ob) )
      {
        message_vision("$N˵�������������죡\n", ob);
      }

        ::kill_ob(me);

}

