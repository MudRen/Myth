
inherit NPC;

void create()
{
        set_name("���ֹ�����", ({ "fat bear", "bear" }) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 10);
        set("long", "һֻ���ֵĴ��ֹ����ܣ�ƨ���ϲ�֪��˭�ú�̿����ŤŤ��д�ˡ��������֡�\n");
        set("attitude", "friendly");
	set("looking", "�ʷ����֣�С��С�ۡ�");
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
        message("vision",
               name() + "�ߺ�ߴߴ�ؽ��˼�����Ť��ƨ�����ˡ�\n", environment(),
                this_object() );
        destruct(this_object());
}

