//fisher.c

inherit NPC;

void create()
{
        set_name("����", ({"fisher","zhangshao","zhang"}));
        set("gender", "����" );
        set("age", 45);
        set("title","���");
        set("long", "�����Ǹ����ȴҲ֪���������ʫ���ʡ�\n������һ��������Է�����֪�����ѡ�\n");
        set("combat_exp", 500);
        set("attitude", "peaceful");
        set_skill("dodge", 10);
        set_skill("unarmed", 20);
        set_skill("literate", 30);
          set_skill("staff", 20);
        set_skill("parry", 20);
        set("per", 25);
        set("max_kee", 200);
        set("max_gin", 100);
        set("max_sen", 100);
        setup();
        carry_object("/d/ourhome/obj/linen")->wear();
        carry_object("/d/southern/jinghe/obj/yugan")->wield();
}


