// jiading.c

inherit NPC;

void create()
{
       set_name("�Ҷ�", ({"jiading"}));

set("long","һ�����Ϳ��򣬿��������������Ĵ���ӣ�\n���ݰͰ͵ĵ����㣮\n");
       set("gender", "����");
       set("age", 26);
       set("attitude", "peaceful");
       set("shen_type", 1);
	set("combat_exp", 1800);
        set_skill("stick", 15);
	set_skill("parry", 25);
	set_skill("dodge", 35);
	set("force_factor", 3);
	setup();
        add_money("coin", 50);
        carry_object("/d/gao/obj/bang")->wield();

}

