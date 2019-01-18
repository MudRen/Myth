//Cracked by Roath
// shufang.c

//written by kittt



#include <ansi.h>



inherit ROOM; 

void init();

int do_zhengli(string arg);

int do_ca(string arg);

int do_fan(string arg);

int do_si(string arg);



void create() 

{

	set("short", "�鷿"); 

	set("long",@LONG

�����ǹ�������д�ֵĵط������Ϲ��ؾصذڷ����ķ�

�ı����Ա���һ������ܣ��������顣�㷭�˷���û������Ҫ

���ؼ�������һ��Сӡ(seal)�е���˼��ǽ�����ƣ�ѧ������ ��   

LONG);



	set("exits",([

		"east" : __DIR__"livingroom",

		])); 

	set("item_desc", ([

		"seal" : "�㷭����һ������������ŤŤ�ؿ��š��������衱\n", 

		]));

	set("book",([

		"qianzw":1,

		"quanpu":2,

		"strike_book":2,

		]));

	set("no_fight",1);

	

	setup(); 

} 



void init()

{

	add_action("do_zhengli","zhengli");

	add_action("do_ca","ca");

	add_action("do_fan","fan");

	add_action("do_si","si");

}



int do_zhengli(string arg)

{

	object ob=this_player();

	

	return JOB_OB("wuguan")->job_zhengli(ob,arg);	

}



int do_ca(string arg)

{

	object ob=this_player();

	

	return JOB_OB("wuguan")->job_cashujia(ob,arg);

}



int do_fan(string arg)

{

	object objBook;

	object ob=this_player();

	

	if(!arg || (arg!="���"))

		return notify_fail("�㷭ʲô��\n");

	if(!ob->query_temp("wuguan/kungfu"))

		return notify_fail("��������Ϲ��ʲô��Ū�����߰���ģ�\n");

	switch(random(4))

	{

		case 0:

			if(!query("book/quanpu"))

				return notify_fail("�����ҵ����Ѿ����������ˡ�\n");

			add("book/quanpu",-1);

			objBook=new(__DIR__"obj/quanpu");

			objBook->move(ob);

			message_vision("$N���˰��죬�����ҵ�һ"+objBook->query("unit")+objBook->name()+"��\n",ob);

			ob->receive_damage("jingli",50);

			ob->delete_temp("wuguan/kungfu");

			break;

		case 1:

			if(!query("book/strike_book"))

				return notify_fail("�����ҵ����Ѿ����������ˡ�\n");

			add("book/strike_book",-1);

			objBook=new(__DIR__"obj/strike_book");

			objBook->move(ob);

			message_vision("$N���˰��죬�����ҵ�һ"+objBook->query("unit")+objBook->name()+"��\n",ob);

			ob->receive_damage("jingli",50);

			ob->delete_temp("wuguan/kungfu");

			break;

		default:

			message_vision("$NϹ���˰��죬���ʲôҲû���ҵ���\n",ob);

			ob->receive_damage("jingli",80);

			break;

	}

	return 1;

}



int do_si(string arg)

{

	object objBook;

	object ob=this_player();

	

	if(!arg || (arg!="seal"))

		return notify_fail("��Ҫ˺ʲô��\n");

	if(!ob->query_temp("wuguan/zixue"))

	{

		message_vision(CYN"$N�����˺��Сӡ......\n"NOR,ob);

		message_vision(HIY"ͻȻ��һ�����������$N��������һ����У���\n"NOR,ob);

		ob->unconcious();

		return 1;

	}

	

	if(!query("book/qianzw"))

		return notify_fail("����Ҫ��ǰȥ˺��Сӡ�������ɥ�ķ��֣�Сӡ�Ѿ�����˺���ˡ�\n");

	message_vision(CYN"$N����������ǰȥ�������˺��Сӡ.....\n"NOR,ob);

	if(random(10))

	{

		tell_object(ob,HIR"����У����ƺ��е����д���һ����������ë�������ʲô����\n"NOR);

		message_vision(HIB"$N����һ���������ȥ����������ͷ��\n"NOR,ob);

		ob->delete_temp("wuguan/zixue");

		return 1;

	}

	add("book/qianzw",-1);

	objBook=new(__DIR__"obj/qianzw");

	objBook->move(environment(ob));

	ob->receive_damage("jingli",100);

	ob->delete_temp("wuguan/zixue");

	message_vision(HIW"ֻ����ž����һ��������һ��������\n"NOR,ob);

	return 1;

}

	
