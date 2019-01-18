// blueice.c...weiqi, 970926
//this ice contains posion...

#include <ansi.h>

inherit ITEM;

int melted;
int do_make(string);
int do_add(string);
object owner; // who owned this ice. -- mon 9/23/98
object last_owner;

void create()
{
	seteuid(getuid());
	set_name(HIB "��ɫ����" NOR, ({ "lan bingkuai", "bingkuai", "bing", "ice" }) );
	set("long", "����һƬ�����ģ�����ģ����쬵ı��飬��͸�ŵ㵭��ɫ��\n");
	set("unit", "Ƭ" );
	set("value", 8000);
	set("material", "ice");
	melted = 0;
	if( clonep(this_object()) ) call_out("melt", 60, 1);
	set("is_monitored",1);
	setup();
}

void melt(int count)
{
	object env;

	melted = count;

	env=environment(this_object());

	if( env->is_character() )
	{//a player or a NPC.
		if( (int)env->query_skill("ningxie-force", 1) < 20 )
		{
			message_vision("$N�������������ģ�ʪʪ�ģ�ԭ���Ǳ��黯�ˡ�\n", env);
			env->apply_condition("ice_poison", 10);
			//note, �ж��ˡ�			
			
			//set who is the killer. -- mon
//			if(last_owner && last_owner!=env)
//			    env->set_temp("last_damage_from",last_owner);
//			else
			// unset previous damage info. -- mon
			    env->set_temp("last_damage_from",0);

			destruct(this_object());
			return;
		}
	}

	else if( (int)env->query_max_encumbrance() > 0 && !environment(env) )
	{//a room.
		if( (string)env->query("outdoors") != "xueshan" )
		{
			tell_object(env,"�������ڻ�����һ̲ˮ�����õ������ǡ�\n");		    
			destruct(this_object());
			return;
		}
	}

	call_out("melt", 60, count + 1);
}

void init()
{                                             
	add_action("do_make", "make");
	add_action("do_make", "zuo");
	add_action("do_chi", "chi");
	add_action("do_chi", "eat");
	add_action("do_add", "add");
	add_action("do_add", "put");
	if(userp(this_player())) {
	    if(owner) last_owner=owner;
	    owner=this_player();
	}
}

int do_make(string arg)
{
	object ob, me;

	me = this_player();

	if( !arg || (arg != "blade" && arg != "dao" && arg != "sword" && arg != "jian" ) )
		return notify_fail("��Ҫ��ʲô��\n");
	if( arg == "sword" || arg =="jian" )
		return notify_fail("��Ƭ������ģ������˽���\n");

	if( (int)me->query("force") < 200 || (int)me->query_skill("ningxie-force", 1) < 20 )
	{
		message_vision("$N�������������ȥ���������ܿ�ͻ����ˡ�\n", me);
		me->apply_condition("ice_poison", 10);
		//note, �ж��ˡ�
		destruct(this_object());
		return 1;
	}	

	ob=new("/d/obj/weapon/blade/handudao-blue");
	ob->move(me);
	me->add("force", -100);
	message_vision("$N�������������ȥ����Ȼ������һ������ı�����\n", me);
	destruct(this_object());

	return 1;
}

int do_chi(string arg)
{	
	if( !this_object()->id(arg) ) return 0;
	if( this_player()->is_busy() )
		return notify_fail("����һ��������û����ɡ�\n");

	if(!arg) return notify_fail("��Ҫ��ʲô��\n");

	message_vision( "$N�������ʹ��һҧ��ֻ�����գ�һ���������ˡ�\n" , this_player());

	if( (int)this_player()->query("kee") > 20 )
		this_player()->add("kee", -20);
	else this_player()->unconcious();

	if( (int)this_player()->query("force") < 200 || (int)this_player()->query_skill("ningxie-force", 1) < 20 )
		this_player()->apply_condition("ice_poison", 5);

	return 1;
}

int do_add(string arg)
{//allow this poison to be added to a jiudai...
	string target, item;
	object destination;
	object me = this_player();

	if(!arg) return notify_fail("��Ҫ��ʲô�����ӽ����\n");

	if( sscanf(arg, "%s in %s", item, target)!=2 )
		return notify_fail("�÷���add <> in <>��\n");

	if( !this_object()->id(item) ) return notify_fail("��Ҫ��ʲô��\n");

	destination = present(target, me);
	if( !destination ) destination = present(target, environment(me));
	if( !destination) return notify_fail("����û������������\n");

	if( !destination->query("liquid") ) return notify_fail("�������ֻ�мӵ�Һ���вŲ��źۼ���\n"); 
	
	//now, time to change it to poison...
	if( destination->query("liquid/type") != "double_ice_poison" )
		destination->set("liquid/type", "ice_poison");
	destination->set("liquid/type", "ice_poison");
	destination->set_temp("destroy_after_sell", 1);
	message_vision( "$N͵͵�����ذ�һ��"+ this_object()->query("name") +"�ӵ���"+ destination->query("name") +"�У��̲�ס����ؼ�Ц�˼�����\n" , me);
	destruct(this_object());
	return 1;
}
