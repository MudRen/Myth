#include <ansi.h>

inherit NPC;

int reset_status();

void init()
{
	::init();
	add_action("do_train", "train");
}

int do_train(string arg)
{
	object me, where;
	me=this_player();
	where=environment(me);
/*
	if( where->query("no_fight") )
		return notify_fail("��ȫ���ڲ���ѵ�ޣ�\n");
*/
	if( !arg )
		return notify_fail("��Ҫѱ��ʲô��\n");
	if( arg != (string)this_object()->query("id") )
		return notify_fail("��Ҫѱ��ʲô��\n");
	if( this_object()->query_temp("rider") )
		return notify_fail("��ƥ�������Ѿ������ˡ�\n");
	if( (string)this_object()->query("owner")==(string)me->query("id") )
		return notify_fail("��ƥ�����Ѿ�������ˡ�\n");
	if( this_object()->is_fighting() )
		return notify_fail("��ƥ�����Ѿ�����Ͼ�ˡ�\n");
	if( !living(this_object()) )
		return notify_fail("����ˣʲô���磿\n");
	if( where->query("no_fight") ) {
		random_move();
		return 1;
	}


	message_vision(HIM"$N����ǰȥ��$nŤ���һ�š�\n"NOR, me, this_object());

       	this_object()->set_temp("owner",me->query("id"));
	reset_status();
	this_object()->kill_ob(me);
	me->fight_ob(this_object());

	return 1;
}

void unconcious()
{
        string owner;
        object owner_ob;
        owner = query_temp("owner");	
	if( owner ) {
	
	owner_ob= find_player(owner);
	
	if( objectp(owner_ob = find_player(owner)) ) {
	        if( (object)query_temp("last_damage_from") == owner_ob ) {
			set("owner", owner_ob->query("id"));
			delete_temp("owner");
			reset_status();
			this_object()->remove_all_killer();
			this_object()->set("attitude", "heroism");
			message_vision(HIY"\n$N��ͷ��β����ʾ������\n"NOR, this_object());
			return;
        	}
	}
	}
//	message_vision(HIY"$N run away!\n"NOR, this_object());
	die();
//	::unconcious();
}


int reset_status()
{
	object me=this_object();
	me->set("eff_kee", (int)me->query("max_kee"));
	me->set("kee", (int)me->query("max_kee"));
	me->set("eff_sen", (int)me->query("max_sen"));
	me->set("sen", (int)me->query("max_sen"));

	return 1;
}
