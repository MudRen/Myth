// whitexiu.c

inherit NPC;

void create()
{
        set_name("������ʿ", ({"xiu shi","xiushi","xiu","shi"}));
        set("gender", "����" );
        set("age", 25);
        set("long", "һλ������������������ɫ�������ֵֹģ��������������¡�\n");
        set("combat_exp", 5000);
        set("attitude", "peaceful");
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set_skill("literate", 30);
        set_skill("force", 30);   
        set("per", 25);
        set("max_kee", 1000);
        set("max_gin", 100);
        set("max_sen", 100);
        set("force", 150);
        set("max_force", 300);
        set("force_factor", 0);
        setup();
        carry_object("/d/ourhome/obj/choupao")->wear();
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 20);
        set("inquiry", ([
                "name" : "����ƨ�£�\n",
                "here" : "�����۾��㲻�ῴ����\n",
	    "Ԭ�س�" : "����ƭ�ӡ�ֻ���������ɵ�ϲ�������\n",
	    "��������" : "����ƭ�ӡ�ֻ���������ɵ�ϲ�������\n",
	 ]) );
}



