inherit NPC;

void create()
{
       set_name("���Ź�", ({"huangmen guan", "guan"}));
       set("gender", "����");
       set("age", 30);
        set("long", "һ����������ĵ�ǰ��ʿ����������ȥѲ���š�\n");
       set("attitude", "heroism");
       set("shen_type", 1);
       set("per", 18);
	set("str", 25);
         set("combat_exp", 80500);
        set_skill("unarmed", 75);
        set_skill("dodge", 75);
        set_skill("blade", 275);
        set_skill("parry", 75);
	set_skill("force", 75);
        set("force", 700);
        set("max_force", 700);
        set("force_factor", 10);
        set("max_kee", 800);
        set("max_sen", 800);
        set("max_mana", 30);
        set("mana", 30);
	set_weight(300000);
setup();
        carry_object("/d/obj/armor/tongjia-fake")->wear();
        carry_object("/d/qujing/baoxiang/obj/wandao")->wield();
}

void die()
{
	object ob;
        if( environment() ) {
        message("sound", "\n���Źٴ�У��д̿ͣ������������ϣ�\n", environment());
	seteuid(getuid());
        if (!objectp(present("guan 2", environment(this_object())))){
	if( ob=new("/d/qujing/jisaiguo/npc/guan"))
        message("sound", "\n�������Źٴ�̨������������\n", environment());
		ob->move("/d/qujing/jisaiguo/yunqi");
        	}
	}
	::die();
}

