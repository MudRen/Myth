inherit NPC;
int give_me(object ob);

void create()
{
       set_name("��˶�", ({"gui badou", "gui"}));

	set("long","���׵Ĵ���ӣ��Բ��ǹ������ƣ����һử��������\n");
       	set("gender", "����");
       	set("age", 56);
        set("title", "��ʦ");
        set("per", 10);
        set("max_kee", 1000);
        set("max_sen",700);
       	set("attitude", "peaceful");
       	set_skill("unarmed",100);
       	set_skill("dodge",100);
        set_skill("parry", 100);
       	set_skill("literate",100);
	set_skill("force", 100);
	set_skill("spells", 100);
        set("combat_exp", 200000);
  set("daoxing", 500000);

	set("force", 400);
	set("force_factor",20);
	set("max_force", 400);
	set("mana", 400);
	set("max_mana", 400);
	set("mana_factor", 20);
        set("inquiry", ([
                "������": (: give_me :),
                "fu": (: give_me :),
        ]) );


        setup();
add_money("silver", 60);
       carry_object("/d/gao/obj/magua")->wear();

}

int give_me(object ob)
{
        object who, me;
        who=this_player();
        me=this_object();

        if( (string)who->query("family/family_name")!="��������" ) {
                message_vision("$Nбб�����$nһ�ۣ�˵���˲���Ϊ���˵�Ҳ��\n", me, who);
                return 1;
        }
	if ((int)me->query("number") >= 10)
		return notify_fail("��˶�����һ�죬����д̫���ˣ���������˵�ɣ�\n");

                ob=new("/d/sea/obj/fu");
                ob->move(who);
		me->add("number",1);

		message_vision("$N�ó��ŷ�ֽ���������������ݸ���$n��\n", me, who);
                return 1;
}

�
