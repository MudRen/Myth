
// qinbing.c
//�ױ�, used for jjf people.

#include <ansi.h>

inherit NPC;

void create()
{
    	object ob1, ob2;

	set_name("���", ({ "guibing" }) );
	set("long", "һ�������Բ����Ŀ�׶�ĵظ������\n");
	set("attitude", "heroism");
	set("class", "ghost");

	set("max_gin", 200);
	set("max_kee", 500);
	set("max_sen", 300);
	set("max_force", 300);
	
	set("str", 40);
	set("cor", 30);
	set("cps", 25);
	set("per", 10+random(15));

	set("combat_exp", 40000);
	set("daoxing", 40000);
	set_skill("parry", 50);
	set_skill("dodge", 40);
	set_skill("unarmed", 50);
	set_skill("jinghun-zhang", 50);
	set_skill("stick", 50);
	set_skill("kusang-bang", 50);
	map_skill("unarmed", "jinghun-zhang");
	map_skill("stick", "kusang-bang");

	setup();

	ob1=carry_object("/d/obj/armor/gujia");
	ob1->wear();
	ob1->set("no_sell", "�ƹ�����һ�۵����ⶫ��һ�������ӵ�Ʒ����Ҫ����Ҫ��\n");
	ob2=carry_object("/d/obj/weapon/stick/wuchangbang");
	ob2->wield();
	ob2->set("no_sell", "�ƹ�����һ�۵����ⶫ��һ�������ӵ�Ʒ����Ҫ����Ҫ��\n");
}

void leave()
{
	message("vision", name() + "����������һ�£�һ���̵����ˡ�\n", environment(), this_object() );
	destruct(this_object());
}

void show(object who)
{
	string *cname = ({"�����", "�����", "�����", "�����"});
	string *ename = ({"-jia", "-yi", "-bing", "-ding"});

	int current = 0;
	current = (int)who->query_temp("jjf_current_bing");

	if(current < 1 || current > 4 )
	{
		destruct(this_object());
		return;
	}

	this_object()->set_name(cname[current-1], ({ (string)who->query("id")+ename[current-1] }) );	
	message_vision("�����شӵ��¸���һλ�����վ��$N���\n", who);

	 //set the leader of this bing.
	set("owner_id", (string)who->query("id")); 
	set_leader(who);
}

void relay_whisper(object me, string msg)
{
	if (query("owner_id") != me->query("id"))
	{
		message_vision((string)this_object()->query("name") 
			+ "����$N�����һ����\n", me);
		return;
	}
	
	//note, do not allow the order contain "chat", "tell"...
	//may need disable more later...
	if( strsrch(msg, "chat") != -1 ||
	    strsrch(msg, "sldh") != -1 ||
	    strsrch(msg, "es") != -1 ||
	    strsrch(msg, "xyj") != -1 ||
	    strsrch(msg, "rumor") != -1 ||
	    strsrch(msg, "tell") != -1 ||
	    strsrch(msg, "apprentice") != -1 ||
	    strsrch(msg, "recruit") != -1 || 
            strsrch(msg, "mount") != -1 ||
            strsrch(msg, "vote") != -1 )

		return;

	message_vision((string)this_object()->query("name") + "����$N���˵�ͷ��\n", me);
	if (msg)
	{
		remove_call_out ("relaying");
		call_out ("relaying", 1+random(3), msg);
	}
}

void relaying (string msg)
{//execute the order.
	command (msg);
}

void init()
{       
	object me=this_player();
	object owner;

	::init();

	//make sure this bing always follow his owner.
	if ( (string)this_object()->query("owner_id") == (string)me->query("id") )
	{
		this_object()->set_leader(me);
	}

	//if owner leaves, let this bing have chance to disappear.
	if( this_object()->query("owner_id") != 0 )
	{
		owner = find_player( (string)this_object()->query("owner_id") );
		if( !owner ) owner=find_living( (string)this_object()->query("owner_id") );
		if( !owner )
		{
			remove_call_out ("leave");
			call_out ("leave", 1);
		}
	}
		
}

