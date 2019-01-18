// Created by waiwai@2001/05/21
// �̸�����ϴ�񣬼��������������֮ΨһNPC

inherit NPC;
#include <ansi.h>
string ask_for_xili();

void create()
{
       set_name("�̸�", ({ "priest", "jiaofu", "jiao", "fu" }) );
       set("gender", "����" );
       set("age", 74);
       set("long","������˽𷢱��ۣ��������߳߶�ߡ�\n");
       set("combat_exp", 30000000);
       set("attitude", "friendly");
	set("chat_chance", 13);
	set("chat_msg", ({
       	"�̸�����ÿ���˶��޷�ѡ���Լ��ĳ����ģ��������⣡\n",
		"�̸�������Ǯ���������һ�У�ȴ�򲻵�����ģ�\n",
		"�̸��������������ʱ����Χ������Ц������ȴ�ڿޣ�\n",
		"�̸�����������ȥ��ʱ����Χ�����ڿޣ������ѽ��ѣ�\n",
		"�̸�������Ǯ�˲���ӵ����࣬������Ҫ���٣�\n",
		"�̸�����û���������ѵ��˻��ŵ�ͬ����ȥ��\n",
		"�̸���������ϴ����Լ����˵������ģ�ʹ����ŵ�ʱ����Կ�ˡ�Լ��������飡\n",
		"�̸���������������Լ��Ľ���ȥ��ȡ��Ǯ��Ȼ����������Ǯ�ָ�������\n",
		"�̸���������˶�δ���������ǣ�ȴ�������ڡ���Ϊ�������콫ֻ��һ��ʧ�ܵ����죡\n",
		"�̸���������˻��ŵ�ʱ�������Զ������ȥ������ȥ�Ժ��ֺ����δ�����\n",
		"�̸���������Ӧ��֪����һ�������м�ֵ�Ĳ���ӵ��ʲô����������ӵ��ʲô�ˣ�\n",
		"�̸���������Ӧ��֪����������ȡ�������ˡ�����Ӧ��ѧ���ˡ���ˣ�\n",
		"�̸�����Ҫ�������������������ȴ��ˣ�ֻҪ�����ӣ��������ƴ�����Ҫ���ϼ���--����һ����\n",
		"�̸�������������ͯ��������ڳ���Ȼ���ֿ������ϻ�ͯ��\n",
        }));

	set("inquiry", ([
		"ϴ��" : (: ask_for_xili :),
		"����" : (: ask_for_xili :),
		"zuinie" : (: ask_for_xili :),
		"xili" : (: ask_for_xili :),
		"kneel" : (: ask_for_xili :),
		]) );

        setup();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_kneel", "kneel");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
       if( ob->query("env/invisibility") ) return;

//	switch( random(1) ) {
//                case 0:
	command("pat " + ob->query("id"));
	command("say ����ϴ����Լ����˵������ģ�");
//	break;
//	}
}

string ask_for_xili()
{
	object me;

	me = this_player();

	if (!me->query("impurity")) {
		command("smile " + me->query("id"));
		return "��λ" + RANK_D->query_respect(me)+"���ʰ������ᱣ����ƽ���ģ�\n";
	} else {


	me->set_temp("pending/zuinie_xili", 1);
	command("pat " + me->query("id"));
	return "��λ" + RANK_D->query_respect(me)+
		"��������ϴ���Լ������������ "HIR"(kneel)"NOR CYN" ��������ǰ����ϴ��ɡ�\n"NOR;
	}
}

int do_kneel()
{
	if( !this_player()->query_temp("pending/zuinie_xili") ) return 0;

	if((int)this_player()->query("balance")<200000) { 
		this_player()->delete_temp("pending/zuinie_xili");
		return notify_fail(WHT"��Ǯׯ����"+MONEY_D->money_num(200000)+"���ܽ���ϴ��\n"NOR);
	}

       if( this_player()->query("env/invisibility") ) {
	message_vision("\n$N��$n˵��������������ǰҲҪ������\n\n" NOR,
		this_player(), this_object() );
	this_player()->delete_temp("pending/zuinie_xili");
	return 1;
	}

	message_vision(HIG"\n$N���������ع���������$n�������$Nͷ�����������Щʥˮ����\n\n" NOR,
		this_player(), this_object() );

	command("smile");
	this_player()->delete_temp("pending/zuinie_xili");
	this_player()->add("balance", -200000);
	this_player()->add("impurity", -(1+random(100)));

	if ((int)this_player()->query("impurity")<0) 
	this_player()->set("impurity", 0);

	this_player()->save();
	this_player()->start_busy(2);

	return 1;
}
 
