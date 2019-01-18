// xiaocao.c...weiqi, 970926
//used to make ice_poison.

#include <ansi.h>
inherit ITEM;

void init();

void create()
{
	set_name(HIB "��ɫС��" NOR,({"xiao cao", "xiaocao", "cao"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "���ֲ�Ҷ��Բ��ɫ����������ȷ�ÿ��� \n");
		set("unit", "��");
		set("value", 300);
	}
	
	setup();
}

void init()
{
	add_action("do_chi", "eat");
	add_action("do_mix", "mix");
}


int do_chi(string arg)
{	
	if( !this_object()->id(arg) ) return 0;

	if(!arg) return notify_fail("��Ҫ��ʲô��\n");

	return notify_fail("������...\n");
}

int do_mix(string arg)
{	
	object mixob, ice, me;
	int type;

	me=this_player();

	if(!arg || !(mixob=present(arg, me)) ) 
		return notify_fail("��Ҫ��ʲô��ϣ�\n");

	if( arg == "xue lian" ) type = 1;
	else if( arg == "qiong cao" ) type = 2;
	else return notify_fail("���ǲ����ܻ�ϵ����ӡ�\n");

	//now I have a xue lian...
	if( (int)me->query("force") < 100 )
		return notify_fail("������㹻���������ܰ������ں�������\n");
	me->add("force", -100);

	message_vision("$N��"+mixob->query("name")+"��"+this_object()->query("name")+"�ŵ�һ�飬����ʹ��һ��...\n", me);

	if( !(ice=present("bing kuai", me)) )
	{
		message_vision("����������ֶ���֭��\n", me);
		destruct(mixob);
		destruct(this_object());
		return 1;	
	}
	
	//if I have an ice...
	message_vision("Ȼ��֭ˮ�ε��˱����ϣ����֭ˮ�ܿ챻�������˽�ȥ��\n", me);

	destruct(ice);
	if ( type == 1 ) ice=new("/d/obj/misc/blueice");
	else if( type == 2 ) ice=new("/d/obj/misc/redblueice");
	else ice=new("/d/obj/misc/ice");
        	ice->move(me);
	//now ice becomes blueice...
	//anyone who has >100 force can make blueice, however those who have
	//no ningxie-force > 20 will �ж� if this blueice melts...hehe:)

  	destruct(mixob);
	destruct(this_object());

	return 1;
}

