//Cracked by Roath
//girl.c

inherit NPC;

void create()
{
        set_name("ũ��Ů", ({"girl"}));
        set("gender", "Ů��" );
        set("age", 15);
        set("long",  
"���ׯ������ũ��Ů��ƽʱ����ֲ����������˳��ҹ��ڵ�Ů�����档\n");
        set("combat_exp", 20);
        set("attitude", "peaceful");
        set("per", 25);
        set("max_kee", 200);
        set("max_gin", 200);
        set("max_sen", 200);
        setup();
        carry_object("/d/obj/cloth/skirt")->wear();
        carry_object("/d/obj/cloth/shoes")->wear();
}

int accept_fight(object me)
{
        return 0;
}

