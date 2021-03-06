/***************************************
MUDLIB：Biographies         〓悟空传〓  
Created Admin By Waiwai@2001/02/18
Admin Email：wkzstory@21cn.com         
****************************************/
// NPC  /d/city/npc/dipi.c
// Created by waiwai@2002/12/20
// 可异地留存类Npc，此类Npc一般是不该设有具体
// 地盘的，以免异地驻留后产生混乱

#include <allobj.h>
inherit KZZNPC;

#define FILE 		CITY_ROOM"nanan-xiaodao1"
#define DIPI		CITY_NPC"dipi"

string query_save_file() { return DATA_DIR + "npc/地痞"; }

void create()
{//	reload("city-dipi");
       set_name("地痞", ({"di pi","pi"}) );
       set("gender", "男性" );
       set("age", 19);
       set("long", "这是醉醺醺的地痞。。。\n");
       set("attitude","heroism");

       set("str", 35);
       set("kar", 20);
       set("con", 18);
       set("int", 15);

	set("combat_exp", 1100000);

	set_skill("unarmed", 200);
       set_skill("handuzhang", 200);
	set_skill("dodge", 200);
	set_skill("xiaoyaoyou", 200);
	set_skill("parry", 200);
	set_skill("force", 200);   
	set_skill("ningxie-force", 200);
	set_skill("literate", 200);
	set_skill("spells", 200);
	set_skill("dengxian-dafa", 200);

	map_skill("spells", "dengxian-dafa");
	map_skill("force", "ningxie-force");
	map_skill("unarmed", "handuzhang");
	map_skill("parry", "handuzhang");
	map_skill("dodge", "xiaoyaoyou");

        set("chat_chance", 3);
        set("chat_msg", ({
		"地痞朝你一阵奸笑。。。。\n",
		"地痞色迷迷的看着你。\n",
        }) );

	set("no_blade", 1);//不怕冰刀
	set("no_poison", 1);//不怕用毒
       set("lead_to", 3); // 可带领标志(帮会为3)
       set("lead_S", 1); // 可留存标志
	set("zombie",1);
       set("Sroom", FILE);
	set("Snpc", DIPI);
       set_temp("apply/attack", 15);
       set_temp("apply/defense", 15);
	set("area","野羊寨");

       setup();

       carry_object("/obj/cloth")->wear();
}
//#include <die.h>
/*
void die()
{
	new(this_object()->query("Snpc"))->move("/obj/empty"); 
	return ::die();
}
*/
void die()
{
	::die();
}

void init()
{
        object area,ob;
        area=new("/obj/area");
        area->create(query("area_name"));
        set("banghui",(string)area->query("banghui"));
        destruct(area);
	::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

// 不是同帮会的就Kill
void greeting(object ob)
{
	string banghui;
	object lp;

	if( !ob || environment(ob) != environment() ) return;
       if( ob->query("env/invisibility") ) return;

	banghui=(string)ob->query("banghui");
	lp=new("/obj/lingpai");
	lp->create(banghui);
       set("banghui",(string)lp->query("banghui"));
	destruct(lp);

	if(! banghui || query("banghui")!=banghui) {
		command("say 竟敢私闯私属帮会地盘，我看你是不想活了！\n");
		kill_ob(ob);
		ob->fight_ob(this_object());
		return;
	}
}

int heal_up()
{
	object me, room;
       string start_room;
	me = this_object();

	if( !living(me) ) return 0;
	if( !me->query_save_file("startroom") ) {
	 me->set("startroom",base_name(environment(me))); 
	}

	if (stringp(start_room = me->query("startroom")) &&
		(room = find_object(start_room)) != environment()) {
	message_vision(HIG"$N"HIG"大叫一声：“不好，我怎么跑到这儿来了？”说罢神色慌张地离开了。\n"NOR, me );

	me->move(room);
	me->set_leader(0);
	me->delete("leader");
	me->delete("leaderid");
	me->delete_temp("leader");
	me->save();
	message_vision("$N快步走了过来。。。\n", me);
	}
	me->save();

       return ::heal_up()+20;
}

void unconcious() { die (); }
