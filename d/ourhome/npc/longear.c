// longear.c
// 1996/12/06 by cglaem

inherit NPC;

string send_mail();
string receive_mail();

void create()
{
	set_name("˳���", ({"shunfeng er", "er", "longear",
"youchai","chai" }) );
	set("title", "�ʲ�");
	set("gender", "����" );
	set("age", 30);
	set("long",
		"ǰ��ʴ�����š���Ϊ͵����ʴ�۸��϶���������Ϊ�ʲ\n");
	set("combat_exp", 8000);
  set("daoxing", 100000);

	set("attitude", "friendly");
	set("inquiry", ([
                        "name":"�����㶼����ʶ������������˳��������ҡ�", 
		"here" : "��֪������ʲô�ط�����ֻ�������ŷ��š�",
                        "�϶�" : "��...��ϧֻ������δ�����ˡ�",
                        "��ʴ��" : "���������һ���Ҿ�����...ֻ���ݹٷŻ𣬲�����յ�ơ�",
		"����" : (: send_mail :),
		"����" : (: receive_mail :),
		"�ż�" : (: receive_mail :),
		"��" : (: receive_mail :),
		"mail" : "��������������ɣ���������Ү~~~~~~~~",
	]) );
	set_skill("literate", 70);
	set_skill("dodge", 50);
	set_skill("unarmed", 40);
	set("per", 15);
            set("max_kee", 500);
            set("max_gin", 100);
            set("max_sen", 300);
            set("force", 150);
            set("max_force", 300);
            set("force_factor", 0);
	setup();
	add_money("coin", 70);
	carry_object("/d/ourhome/obj/linen")->wear();
}

string send_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "������仹�ڰɣ�������Ϳ��Լ����ˡ�\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "��һ�µ���ʯͷ�����Ұɡ�\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "Ŷ... Ҫ������������������䣬���ŵķ�����������˵����\n";
}

string receive_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "������仹�ڰɣ������е��Ŷ������档\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "��һ�µ���ʯͷ�����Ұɡ�\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "�ã���������....���ˣ�����������⣬�������ɣ���������ˡ�\n";
}
�