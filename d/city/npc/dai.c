inherit NPC;
string send_mail();
string receive_mail();

void create()
{
        set_name("������", ({"dai wenzhong", "dai"}));
        set("age", 42);
        set("gender", "����");
        set("long",
"��վ��ĵ��ң�����ԲԲ���ֵġ�\n");
	set("title", "��վ����");
        set("attitude", "peaceful");

        set("combat_exp", 40000);
  set("daoxing", 20000);

        set("shen_type", 1);
	set("max_force", 300);
	set("force", 300);
	set("force_factor", 5);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        set_skill("parry", 40);
        set("inquiry", ([
                "����" : (: send_mail :),
                "����" : (: receive_mail :),
                "�ż�" : (: receive_mail :),
                "��" : (: receive_mail :),
                "mail" : "��������������ɣ���������Ү~~~~~~~~",
        ]) );

	setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}
string send_mail()
{
        object mbox;

        if( this_player()->query_temp("mbox_ob") )
                return "������仹�ڰɣ�������Ϳ��Լ����ˡ�\n";
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
                return "��һ�µ���վ�����Ұɡ�\n";
        seteuid(getuid());
        mbox = new(MAILBOX_OB);
        mbox->move(this_player());
        return "Ŷ...
Ҫ������������������䣬���ŵķ�����������˵����\n";
}

string receive_mail()
{
        object mbox;

        if( this_player()->query_temp("mbox_ob") )
                return "������仹�ڰɣ������е��Ŷ������档\n";
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
                return "��һ�µ���ʯͷ�����Ұɡ�\n";
        seteuid(getuid());
        mbox = new(MAILBOX_OB);
        mbox->move(this_player());
        return
"�ã���������....���ˣ�����������⣬�������ɣ���������ˡ�\n";
}

�
