// sevenstar.c
// 1996/10/03 by none

inherit NPC;

string send_mail();
string receive_mail();

void create()
{
	set_name("��ʮ����ư��С��", ({ "28star bug", "28star", "bug" }) );
	set("title", "���žֽӴ�Ա");
	set("gender", "Ů��" );
	set("age", 18);
	set("long",
		"��ʮ����ư��С�㣬�׳ƻ���㣬ϲ���ں������м䴩�����ߡ�\n");
	set("combat_exp", 800);
	set("attitude", "friendly");
	set("inquiry", ([
		"���ž�" : "�ǰ�... ������ǵ��ž֣���Ҫ������",
		"����" : (: send_mail :),
		"����" : (: receive_mail :),
		"mail" : "��������������ɣ���������Ү~~~~~~~~",
	]) );
	set_skill("literate", 70);
	set_skill("dodge", 50);
	set_skill("unarmed", 40);
	setup();
	add_money("coin", 70);
	carry_object("/d/ourhome/obj/pink_cloth")->wear();
}

string send_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "������仹�ڰɣ�������Ϳ��Լ����ˡ�\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "���Ǳ�Ǹ��������һ�µ����ž������Ұɡ�\n";
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
		return "���Ǳ�Ǹ��������һ�µ����ž������Ұɡ�\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "�ã���������....���ˣ�����������⣬�������ɣ���������ˡ�\n";
}
