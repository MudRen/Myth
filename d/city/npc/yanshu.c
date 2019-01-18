//Created by waiwai@2001/01/03

#include <ansi.h>
inherit NPC;
int clean_trash();
int dest_trash();
void create()
{
      int i,amun;
       set_name("����", ({ "yan shu", "shu", "mouse", "yanshu" }) );
       set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
       set("verbs", ({ "bite", "claw" }) );
       set("race", "Ұ��");
       set("age", 2);
       set("env/wimpy",90);
       set("vendetta_mark", "authority");
       set("str", 99);
       set("spi", 40);
       set("kar", 40);
       set("per", 40);
       set("cps", 40);
       set("max_sen", 9000);
       set("max_kee", 9000);
       set("food", 9000);
       set("water", 9000);
       set("max_food", 9000);
       set("max_water", 9000);
       set("long", "һֻ�ɰ��ģ��������С����\n");
        set("chat_chance", 90);
        set("chat_msg", ({
              (: clean_trash :),
		(: dest_trash :)
        }) );
        set_temp("apply/attack", 500);
        set_temp("apply/damage", 500);
        set_temp("apply/dodge", 500);
        set_temp("apply/armor", 500);

	set("attitude", "friendly");
	set("combat_exp", 600000);
       set("no_give", 1);//By waiwai@2001/06/22 task bug fix

	setup();
//        carry_object("/d/city/obj/mojing")->wear();
}

void init()
{
	object room;
	int i;
	object *inv;
	dest_trash();
	room = environment(this_object());
	if(room) {
	inv = all_inventory(room);
        for(i=0; i<sizeof(inv); i++) {

	if( userp( inv[i]) && ! wizardp( inv[i]) ) {
	if ( !random(5))
	set_leader(inv[i]);
	continue;
	}
	if( inv[i]->query("no_shown")) continue;
	if( inv[i]->query("no_get")) continue;
//	if( inv[i]->query("keep_this")) continue;
	if( inv[i]->query("task_give")) continue;
	if( inv[i]->is_character()) continue;
	if( inv[i]->is_corpse()) continue;
	command("get "+ inv[i]->query("id"));
	}
	}

}

int randommove()
{
       mapping exits;
       string *dirs;
	string thisdir;
       if( !mapp(exits = environment()->query("exits")) ) {
	destruct(this_object());
	return 0;
	}
	if(exits) {
       dirs = keys(exits);
	thisdir = dirs[random(sizeof(dirs))];
	this_object()->set("last_dir",thisdir);
       command("go " + thisdir);
	} else {
	destruct(this_object());
	return 0;
	}
}

int clean_trash()
{
	mapping exits;
	string *dirs;
	string last_dir;
	if( last_dir = this_object()->query("last_dir")) {
        if( !mapp(exits = environment()->query("exits")) ) {
	destruct(this_object());
	return 0;
	}
        dirs = keys(exits);
	if( member_array(last_dir, dirs) != -1) {
	if( random(2) )
		command("go "+ last_dir);
	else
		randommove();
	} else
		randommove();
	} else
		randommove();
}

int dest_trash()
{
	object *inv;
	int i,j;
	inv = all_inventory(this_object());
	j = sizeof(inv);
       for(i=0; i<j; i++) 
	destruct(inv[i]);
}

