/***************************************
MUDLIB：Biographies         〓悟空传〓  
Created Admin By Waiwai@2001/02/18
Admin Email：wkzstory@21cn.com         
****************************************/
// Update by waiwai@2001/04/17

inherit NPC;
#include <ansi.h>
int msg();

void create()
{
	mapping name;
	
	name=NAME2_D->random_name("male");
	set_name(name["name"], name["id"]);
	set("title", name["title"]);
	set("age", 20+random(30));
	set("per", 15+random(10));
	set("str", 15+random(10));
	set("gender", "男性");
	set("long", "长安府在外面巡逻的捕快，你最好不要去惹他们。\n");
	
        set("combat_exp", 9000000+random(1000000));
        set_skill("unarmed", 900+random(100));
        set_skill("dodge", 900+random(100));
        set_skill("parry", 900+random(100));
        set_skill("stick", 900+random(100));
        set("max_kee", 8000+random(1000));
        set("max_sen", 8000+random(1000));
        set("food", 8000+random(1000));
        set("water", 8000+random(1000));
        set("force", 5000);
        set("max_force", 5000+random(500));
        set("force_factor", 100);
        set("mana_factor", 100);
        set("max_mana", 5000+random(500));
        set("mana", 5000);

	set("chat_chance", 90);
	set("chat_msg", ({
		(: random_move :),
		(: msg :),
	}));

	
	setup();
        carry_object("/d/obj/cloth/yayifu")->wear();
        carry_object("/d/obj/weapon/stick/shawei")->wield();
}

int msg()
{
	string *msg=({
		"快给大爷让路！\n",
		"那贼到底哪里去了？\n",
		"你见过那个菜花贼没有？\n",
		"拦老子的路，不想混了！\n",
	});		
	command("say "+msg[random(sizeof(msg))]);
	return 1;
}