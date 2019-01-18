
inherit NPC;

void create()
{
        set_name("��ĸ��", ({ "old pig", "pig" }) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 10);
        set("long", "һֻ���ֵ���ĸ��ƨ���ϲ�֪��˭�ú�̿����ŤŤ��д�ˡ����������֡�\n");
        set("attitude", "friendly");
	set("looking", "�ʷ����֣����������ж������");
        set("str", 20);
        set("con", 40);
	set("kee", 300);
	set("sen", 300);
        set("limbs", ({ "ͷ��", "����" }) );
        set("verbs", ({ "bite"}) );
	set("combat_exp", 2000);
        set_skill("dodge", 20);
        set_temp("apply/armor", 30);

        setup();
}

int heal_up()
{

        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
	this_object()->add("time", 1);
	if ( (int)this_object()->query("time") > 3 ) {
        message("vision",
               name() + "�ߺ�ߴߴ�ؽ��˼�����Ť��ƨ�����ˡ�\n", environment(),
                this_object() );
        destruct(this_object());
	}
	return;
}
