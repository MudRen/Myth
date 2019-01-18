// jftou.c �η�ͷ
#include <ansi.h>

inherit NPC;

int do_kill(string);
int do_enter(string);
int do_say(string);
int do_look(string);

void create()
{
	set_name("�η�ͷ", ({ "jiaofu tou", "tou" }));
	set("long", "���ǽη�ͷ������̧�����⣬����������Ӷ������\n"
		"������������ǿ�ɣ��е�����ͷ�Ե����ӣ�����Ҳ��С��\n");
	set("gender", "����");
	set("age", 30);
	set("attitude", "peaceful");
	set("str", 80);
	set("int", 10);
	set("max_kee", 600);
	set("combat_exp", 10000);
	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	set("inquiry", ([
		"name" : "С��������˵�ͷ���������ϵ��¶���С��һ�ָ������кηԸ���",
		"here" : "�����ȥ��������ͤ�ˣ����еĻ��������Ƕ������������������ü��ˡ�",
		"����" : "�Ǻǣ�С�ľ͸���������ƣ����Σ��η򣬴����֣�һӦ��ȫ���������⡣��Ҫ��Ҫ����⣿",
		"��Ǯ" : "���μӽη�һ�������ӡ�Ҫ�ǼӴ����֣����һ��������Ǯ���ף��ȸ����ӡ�",
       ]) );

	setup();
}

void init()
{
	add_action("do_kill", "kill");
	add_action("do_kill", "fight");
	add_action("do_enter", "enter");
	add_action("do_say", "say");
	add_action("do_look", "look");
}

int do_look(string arg)
{
	if ((arg=="jiaozi"
		|| arg=="huajiao"
		|| arg=="jiao")
		&& query("on_way")) {
		tell_object(this_player(),
"����һ��Ư���Ļ��Σ����Ķ��Ӳ����ţ��Ľ����Ŵ�컨���ĸ����Ӷ��òʴ����š�\n"
"�����η���̧�����ߣ�������Ȼ���Ÿ������ӡ�\n");
		return 1; }
	return 0;
}

int do_kill(string arg)
{
	if ((arg=="jiaofu tou"
		|| arg=="tou"
		|| arg==query("groom"))
		&& environment()!=find_object("/d/moon/yltw")) {
		write("���뻵�˺��£�̫�������˰ɡ�\n");
		return 1; }
	return 0;
}

int do_enter(string arg)
{
	object me, jiao, tou;
	me=this_player();
	tou=present("jiaofu tou", environment(me));

	if ((arg=="jiaozi" || arg=="huajiao" || arg=="jiao")
		&& getuid(me)==query("bride")) {
		message_vision("������$N���ߴ��������˻�����η����ϰѽ�������������\n",me);
		me->move("/d/moon/jiaoli");
		set_leader(find_player(query("groom")));
		command("say һ�о��������ɹ�����ǰ���·�����Ǹ��ţ����˵ط���С��˵һ�������ˡ�");
		set_leader(find_player(query("groom")));
		jiao=present("jiaozi",environment(tou));
		jiao->move(tou);
		message_vision("$N����һ���η�һ�𣬺���һ�°ѽ���̧��������\n",tou);
		tell_object(me, "��е����ӱ���̧����������������·�ˡ�\n");
		set("on_way",1);
		return 1; }
	return 0;
}

int do_say(string arg)
{
	object me, tou, jiao, worker1;
	me=this_player();

	if ((arg=="����" || arg=="here") && getuid(me)==query("groom") && query("on_way")) {
		message_vision("$N���߽η�ͷ���ط��ˡ�\n", me);
		message_vision("�η�ѽ��ӷ������������������������վ�˳�����\n", me);
		find_player(query("bride"))->move(environment(me));
		me->delete_temp("marrying");
		me->delete_temp("bride");
		command("say ��л�����չ�С�ĵ����⣬��ϲ��λ���ˣ�ף��λ��ͷ���ϣ�С�ĸ���ˡ�");
		message_vision("�η�һ����̧�ſս����뿪�ˡ�\n",me);
		if (present("jiaofu tou", find_object("/d/moon/yltw"))) {
			if (objectp(tou=present("jiaofu tou",environment(me))))
				destruct(tou);
			if (objectp(worker1=present("jiaofu",environment(me))))
				destruct(worker1);
			if (objectp(worker1=present("luogu shou",environment(me))))
				destruct(worker1);
			if (objectp(worker1=present("suona shou",environment(me))))
				destruct(worker1);
			return 1; }
		if (objectp(tou=present("jiaofu tou",environment(me)))) {
			tou->move("/d/moon/yltw");
			tou->set_leader(0);
			tou->delete("in_job");
			tou->delete("on_way");
			tou->delete("groom");
			tou->delete("bride");
			tou->delete_temp("no_return");
			if (objectp(jiao=present("jiaozi",tou)))
				jiao->move("/d/moon/yltw");
		}
		if (objectp(worker1=present("jiaofu",environment(me)))) {
			worker1->move("/d/moon/yltw");
			worker1->set_leader(0);
			worker1->delete_temp("no_return"); }
		if (objectp(worker1=present("luogu shou",environment(me)))) {
			worker1->move("/d/moon/yltw");
			worker1->set_leader(0);
			worker1->delete_temp("no_return"); }
		if (objectp(worker1=present("suona shou",environment(me)))) {
			worker1->move("/d/moon/yltw");
			worker1->set_leader(0);
			worker1->delete_temp("no_return"); }
		return 1;
	}
	return 0;
}

int accept_object(object who, object ob)
{
	object worker1, worker2, worker3;

	if (query("in_job")) {
		command("say ʮ�ֱ�Ǹ�������ڸպ���׮���⣬�����������������");
		return 1; }

	if (!ob->query("money_id")) {
		command("say ��Ӵ������С�Ŀ�ʲô��Ц���ⶫ��С���Ķ����հ���");
		return 1; }

	if (!who->query_temp("marrying")
		|| !present(who->query_temp("bride"), environment(who))) {
		command("say ��ѽ������̫�����ˣ�û�¶��ʹ��ͣ��������׵�ʱ��С��һ�����ķ���");
		remove_call_out("destroying");
		call_out("destroying", 1, this_object(), ob);
		return 1; }

	if (ob->value()==10000)	{
		if (!objectp(worker1=present("jiaofu",environment()))) {
			command("say ��Ӵ����������ֲ��룬û�����������ˣ�̫�Բ����ˣ����϶������");
			return 1; }

		command("say �õĺõģ���л���ϵ����ӣ�������ͱ��ã����������ϽΡ�");
		set("in_job",1);
		set("bride",who->query_temp("bride"));
		set("groom",getuid(who));
		set_temp("no_return",1);
		worker1->set_leader(this_object());
		worker1->set_temp("no_return",1);
		message_vision("�η�ͷ�ѽ�������������������Խ�ȥ�ˡ�\n",who);
		remove_call_out("destroying");
		call_out("destroying", 1, this_object(), ob);
		return 1;
	}

	if (ob->value()==20000) {
		if (!objectp(worker1=present("jiaofu",environment()))
			|| !objectp(worker2=present("luogu shou",environment()))
			|| !objectp(worker3=present("suona shou",environment()))) {
			command("say ��Ӵ����������ֲ��룬û�����������ˣ�̫�Բ����ˣ����϶������");
			return 1; }

		command("say �õĺõģ���л���ϵ����ӣ�������ͱ��ã����������ϽΡ�");
		command("say ���Ϸ��ģ���������Ӹ��Ŵ��򣬱�֤��һ·��⡣");
		set("in_job",1);
		set("bride",who->query_temp("bride"));
		set("groom",getuid(who));
		set_temp("no_return",1);
		worker1->set_leader(this_object());
		worker1->set_temp("no_return",1);
		worker2->set_leader(worker1);
		worker2->set_temp("no_return",1);
		worker3->set_leader(worker1);
		worker3->set_temp("no_return",1);
		message_vision("�η�ͷ�ѽ�������������������Խ�ȥ�ˡ�\n",who);
		message_vision("�����ִ����ش��������ţ�����������������ģ��ò����֡�\n",who);
		remove_call_out("destroying");
		call_out("destroying", 1, this_object(), ob);
		return 1;
	}
}

void destroying(object me, object obj)
{
	destruct(obj);
	return;
}
