//Cracked by Roath

#include <ansi.h>
inherit NPC;
void create()
{

        set_name("��ˮ����", ({ "jingshui longwang", "long wang", "long", "dragon" }) );
        set("gender", "����" );
	set("long",
		"��ˮ��֮��������Υ�����ּ�⣬�������ʱ����Ϊ��������\n"
		"ة��κ����ն��������ǹ»�Ұ��\n"
         	);
	set("age",55);
	set("title", "���");
	set("class", "dragon");
	set("attitude", "heroism");
	set("max_kee",2100);
	set("kee",2100);
	set("max_sen",2100);
	set("sen",2100);
	set("combat_exp",800000);
        set("daoxing",1200000);
	set("force",2000);
	set("max_force",1500);
	set("mana",2000);
	set("max_mana",1600);
	set("force_factor", 120);
	set("mana_factor",120);
	


	set_skill("unarmed",180);
	set_skill("dragonfight", 180);
	set_skill("parry",180);
	set_skill("dodge",180);
	set_skill("sword",180);
	set_skill("dragonforce",180);
	set_skill("qixiu-jian",180);
	set_skill("force",180);
	set_skill("spells", 180);
	set_skill("seashentong", 180);
	set_skill("dragonstep", 180);
	map_skill("dodge", "dragonstep");
	map_skill("spells", "seashentong");
	map_skill("force", "dragonforce");
	map_skill("parry", "dragonfight");
	map_skill("sword","qixiu-jian");
	map_skill("unarmed", "dragonfight");


        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed", "sheshen" :),
        }) );

	setup();

	carry_object("/d/sea/obj/longpao")->wear();
}




