//qiaofu.c

inherit NPC;

void create()
{
        set_name("�", ({"qiaofu","liding","li"}));
        set("gender", "����" );
        set("age", 35);
        set("title","�Է�");
        set("long", "�����Ǹ��Է�ȴҲ֪���������ʫ���ʡ�\n������һ�������ҵ��������֪�����ѡ�\n");
        set("combat_exp", 500);
        set("attitude", "peaceful");
        set_skill("dodge", 10);
        set_skill("axe", 20);
        set_skill("literate", 30);
        set("per", 25);
        set("max_kee", 200);
        set("max_gin", 100);
        set("max_sen", 100);
        setup();
        carry_object("/d/ourhome/obj/linen")->wear();
        carry_object("/d/ourhome/obj/lumber_axe")->wield();
}


