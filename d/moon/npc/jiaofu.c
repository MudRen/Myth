// jiaofu.c �η�

inherit NPC;

int do_kill(string);

void create()
{
	set_name("�η�", ({ "jiaofu" }));
	set("long", "������ר�Ÿ���̧���εĽη�\n"
		"��������������֣��а���������̧�ǻ�������һ�����ȵ���\n");
	set("gender", "����");
	set("age", 25);
	set("attitude", "peaceful");
	set("str", 80);
	set("int", 10);
	set("max_kee", 600);
	set("combat_exp", 10000);
	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	setup();
}

void init()
{
	add_action("do_kill", "kill");
	add_action("do_kill", "fight");
}

int do_kill(string arg)
{
	if (arg=="jiaofu" && environment()!=find_object("/d/moon/yltw")) {
		write("���뻵�˺��£�̫�������˰ɡ�\n");
		return 1;
	 }
	return 0;
}
