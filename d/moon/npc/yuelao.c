// yuelao.c ��������
// AceP
// mon 1/2/97

inherit NPC;

int do_register();
int do_zuomei(string);
int do_divorce(string);

void create()
{
	set_name("��������", ({ "yuexia laoren", "yuelao", "laoren" }));
	set("long", 
"������ר�����ϵ�����Ե�����������ˡ�
��������⣬��ü�԰ף��������Ƕ�����һ���飬
�������һ������������������������Щʲô��\n");
	set("gender", "����");
	set("age", 101);
	set("attitude", "friendly");
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("per", 25);
      
	set("max_kee", 1200);
	set("max_gin", 1000);
	set("max_sen", 1200);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 50);
	set("max_mana", 1200);
	set("mana", 1200);
	set("combat_exp", 500000);
  set("daoxing", 5000000);


	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("literate", 150);

	set("inquiry", ([
		"name" : "�����������ϣ��ڴ˸������ϵ������е���Ե�����в�֪���������ˡ�",
		"here" : "��������Ұ칫�ĵط������е���Ե�����������͵͵ǣ���ߣ�Ҳ�������ע�����ġ�",
//		"news" :,
		"���" : "���飿��Ҫ�ҵ�������ע��������Ե��Ȼ��һ���������Ǽ�(jiehun)��顣",
		"�Ǽ�" : "���飿��Ҫ�ҵ�������ע��������Ե��Ȼ��һ���������Ǽ�(register)��顣",
		"���" : "�����������ˣ�����ͷ���Ĳ��ţ�����ʸߵÿ��¡�����������������Ҳ���������(divorce/lihun)���롣",
		"��ý" : "ý���ǽ��ز����ٵ�֤�ˣ���ý(zuomei)�ĸ����Ů����֤��",
       ]) );

	setup();
}

void init()
{
	add_action("do_register", "register");
	add_action("do_register", "jiehun");
	add_action("do_divorce", "divorce");
	add_action("do_divorce", "lihun");
	add_action("do_zuomei", "zuomei");
}

int do_register()
{
	object me, who, meiren;
        object ring, ring2;
        ring = new ("/d/moon/obj/ring");
        ring2 = new ("/d/moon/obj/ring");
	me=this_player();
	message_vision("$N���������˴��������¡�\n", me);
	if (! interactive(me))
		return 1;
	if (!me->query("waiting_marry")) {
		command("say �ף�������Ե����û���������ѽ ... ..."); 
		command("say ���������Ȼ�ȥ�����Ҹ����ҵ�������Ե�����ɡ�");
		return 1;
	}
	if (me->query("gender")=="Ů��") {
		command("say �ţ������δ�����ǰ����");
		return 1;
	}
	if (!objectp(who=present(me->query("partner"),environment(me)))) {
		command("say �ţ������Ե�����ˣ�����Ϊʲô���δ����ûһ������");
		command("say ������δ���޵����������Ҳ���Ϊ������ɵǼ�������");
		return 1;
	}
	if (who->query("partner")!=getuid(me)) {
		command("say �����������δ����Ϊ���ִ�Ӧ��������ˣ�����");
		command("say �����뿪ʲô��Ц�������������������");
		return 1;
	}
	if (!who->query("meiren")) {
		command("say ����Ե��׻�˵�ĺá���ĸ֮����ý��֮�ԡ�������̶���޸�ĸ����Ҳ���ˡ�");
		command("say ������ý��֮�ԣ���Ҳ̫�����ˡ�");
		command("say ����ȥ�Ҹ�ý�����ɣ������ڴ���֤���Ҳ���Ϊ�������顣");
		return 1;
	}
	if (!objectp(meiren=present(who->query("meiren"),environment(me)))) {
		command("say �ţ�����˶�������ˣ�������ý�������Ķ�ȥ����");
		command("say ���ý���ҵ���������Ҳ���Ϊ������ɵǼ�������");
		return 1;
	}

	command("say �����������ü��ˣ�һ���뱸�������Ϊ���ǵǼǣ�");
	write("�������˵�ͷ����Ե�����˷���д��Щʲô��\n");
	command("say ��ϲ����ϲ��");
	command("chat ����������������");
	command("chat "+me->name()+"��"+who->name()+"��"+meiren->name()+"��ý������ϲ����Ե����λ����������֤��");
	command("chat ��ף��λ��ͷ���ϣ��������ӡ�");

	log_file("yl.rc",me->name()+"��"+who->name()+
	  "��"+meiren->name()+"��ý����"+NATURE_D->game_time()+"("+
	  ctime(time())+")ϲ����Ե��\n");

	who->delete("waiting_marry");
	who->delete("partner");
	who->delete("meiren");
	who->set("married",1);
	who->set("husband/"+getuid(me), me->name());
	who->set("couple/id", getuid(me));
	who->set("couple/name", me->name());
	me->delete("waiting_marry");
	me->delete("partner");
	me->set("married", 1);
	me->set("wife/"+getuid(who), who->name());
	me->set("couple/id", getuid(who));
	me->set("couple/name", who->name());
	me->set_temp("marrying",1);
	me->set_temp("bride",getuid(who));
        ring->move(who);
        ring2->move(me);

	return 1;
}

int do_zuomei(string arg)
{
	object me, who;
	me=this_player();

	if (! interactive(me))
		return 1;
 	if (!arg || !objectp(who=present(arg,environment(me)))) {
		tell_object(me,"��Ҫ��˭��ý��\n");
		return 1;
	}
	if (arg==me->query("partner")) {
		tell_object(me,"�������Լ���ý����˵���𣿣���\n");
		return 1;
	}
	if (who->query("gender")=="����") {
		tell_object(me, "�ţ���ý��ΪŮ����ý��\n");
		return 1;
	}
	if (!who->query("waiting_marry")) {
		tell_object(me,"�ţ�����û�����鰡����Ϲ��ʲô�壿����\n");
		return 1;
	}
	message_vision("$NЦ������˵�������Ů����ý��\n", me);
	command("say " + me->query("name") + "ԭ���" + who->name() + "��ý��");
	command("say ����ǳ���֮�������°����ü��ˣ�����ͼ�¼������");
	who->set("meiren", getuid(me));
	return 1;
}

int do_divorce(string arg)
{
	object me,who;
	me=this_player();

	if (! interactive(me))
		return 1;
	if (!arg) {
		tell_object(me, "������˭��飿\n");
		return 1;
	}
 	if (!me->query("married")) {
		tell_object(me, "�����û����飡\n");
		return 1; }
	if (me->query("gender")=="����") {
		if (!me->query("wife/"+arg))
			return notify_fail("����������ֵؿ�����һ�ۣ��������˸������������ӣ�\n");
		if (!(who=find_player(arg))) {
			message_vision("$N�����������˴��������ţ�������û�����ˣ���Ҫ��飡\n", me);
			command("say �Բ������������ڲ������ϣ����ܰ����������");
			return 1; }
		if (!me->query_temp("divorcing")) {
			message_vision("$N�����������˴��������ţ�������û�����ˣ���Ҫ��飡\n", me);
			command("say �����㵱���������������������ǣ�������������һ�Ρ�");
			me->set_temp("divorcing",1);
			return 1; }
		me->delete("married");
		me->delete("couple");
		me->delete("wife");
		me->delete_temp("divorcing");
		who->delete("married");
		who->delete("couple");
		who->delete("husband");
		tell_object(who, me->name()+"�������ˡ�");
	}
	else {
		if (!me->query("husband/"+arg))
			return notify_fail("����������ֵؿ�����һ�ۣ��������˸����������ɷ�\n");
		if (!(who=find_player(arg))) {
			message_vision("$N�����������˴��������ţ�������û�����ˣ���Ҫ��飡\n", me);
			command("say �Բ������ɷ����ڲ������ϣ����ܰ����������");
			return 1; }
		if (!me->query_temp("divorcing")) {
			message_vision("$N�����������˴��������ţ�������û�����ˣ���Ҫ��飡\n", me);
			command("say �����㵱������������ɷ�������ǣ�������������һ�Ρ�");
			me->set_temp("divorcing",1);
			return 1; }
		who->delete("married");
		who->delete("wife");
		who->delete("couple");
		me->delete("married");
		me->delete("couple");
		me->delete_temp("divorcing");
		me->delete("husband");
		tell_object(who, me->name()+"�������㣬��֪�Ǹ�˭˽��ȥ�ˡ�");
	}
	command("say �� ... ...");
	command("chat �� ... �ӽ�����"+me->name()+"��"+who->name()+"�Ͳ����Ƿ����ˡ�");
	command("chat ��һ׮ʧ�ܵĻ������� ... ... ");

        log_file("yl.rc",me->name()+"��"+who->name()+
	   "��"+NATURE_D->game_time()+"("+ctime(time())+")��顣\n");

	return 1;
}
�
