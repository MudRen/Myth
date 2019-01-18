/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
// NPC  /d/city/npc/dipi.c
// Created by waiwai@2002/12/20
// �����������Npc������Npcһ���ǲ������о���
// ���̵ģ��������פ�����������

#include <allobj.h>
inherit KZZNPC;

#define FILE 		CITY_ROOM"nanan-xiaodao1"
#define DIPI		CITY_NPC"dipi"

string query_save_file() { return DATA_DIR + "npc/��Ʀ"; }

void create()
{//	reload("city-dipi");
       set_name("��Ʀ", ({"di pi","pi"}) );
       set("gender", "����" );
       set("age", 19);
       set("long", "�����������ĵ�Ʀ������\n");
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
		"��Ʀ����һ���Ц��������\n",
		"��Ʀɫ���ԵĿ����㡣\n",
        }) );

	set("no_blade", 1);//���±���
	set("no_poison", 1);//�����ö�
       set("lead_to", 3); // �ɴ����־(���Ϊ3)
       set("lead_S", 1); // �������־
	set("zombie",1);
       set("Sroom", FILE);
	set("Snpc", DIPI);
       set_temp("apply/attack", 15);
       set_temp("apply/defense", 15);
	set("area","Ұ��կ");

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

// ����ͬ���ľ�Kill
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
		command("say ����˽��˽�������̣��ҿ����ǲ�����ˣ�\n");
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
	message_vision(HIG"$N"HIG"���һ���������ã�����ô�ܵ�������ˣ���˵����ɫ���ŵ��뿪�ˡ�\n"NOR, me );

	me->move(room);
	me->set_leader(0);
	me->delete("leader");
	me->delete("leaderid");
	me->delete_temp("leader");
	me->save();
	message_vision("$N�첽���˹���������\n", me);
	}
	me->save();

       return ::heal_up()+20;
}

void unconcious() { die (); }
