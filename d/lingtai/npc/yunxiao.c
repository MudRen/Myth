// worker.c

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("����", ({"yun xiao", "yun"}));
        set("gender", "����" );
        set("age", 33);
        set("long",
"����ɽ���Ƕ������������еĽܳ����
�ڳ���ת��תȥ��Щ��ɧ��\n");
	set("int", 25);
	set("class", "taoist");
        set("combat_exp", 80000);
	set("daoxing", 100000);

        set("attitude", "peaceful");
        create_family("����ɽ���Ƕ�", 3, "����");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("spells", 50);  
        set_skill("dao", 50);
        set_skill("literate", 30);
        set_skill("stick", 50);  
        set_skill("puti-zhi", 50);  
        set_skill("jindouyun", 50);
        set_skill("dodge", 50);  
        set_skill("force", 50);   
        set_skill("wuxiangforce", 50);

        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");
        map_skill("dodge", "jindouyun");

	set("str", 30);
        set("per", 30);
        set("max_kee", 500);
        set("max_gin", 500);
        set("max_sen", 500);
        set("force", 450);
        set("max_force", 300);
        set("force_factor", 20);
        set("mana", 450);
        set("max_mana", 300);
        set("mana_factor", 5);

        setup();
        carry_object("/d/lingtai/obj/cloth")->wear();
}


void init()
{
        object ob;

        ::init();
        set("chat_chance", 10);
        set("chat_msg", ({
            "�������˸����磮\n",
            "�����������´������㼸�ۡ�\n",
	    "��������һ����\n"
        }) );
}

�
