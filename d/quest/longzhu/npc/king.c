// �������.c

inherit NPC;

void create()
{
       set_name("����", ({"guo wang", "wang", "king"}));
       set("title", "�������");
       set("long","����ǵĹ���,��˵�Ǹ����Ƶļһ\n");
       set("gender", "����");
       set("age", 40);
       set("attitude", "peaceful");
       set("shen_type", 1);
        set("per", 30);
        set("combat_exp", 1000000);
        set_skill("unarmed", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        setup();
      carry_object("/d/calvin/armor/armor")->wear();
         carry_object("/d/quest/longzhu/obj/jingshi2");

}

