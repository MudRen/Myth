//girl.c

inherit NPC;

void create()
{
        set_name("�㶹��", ({"girl"}));
        set("gender", "Ů��" );
        set("age", 11);
        set("long",  
"��õ�Ů�����������ʮ���ꡣ������ҧָ����, һ��������, 
��৵�һ�¾ͺ���, ����æ�����һ��, ����ͷ�ýż�����ǰ
������ȥ��С����, : ��...��...��ʲô����?\n");
        set("combat_exp", 20);
        set("attitude", "peaceful");
        set("per", 25);
        set("max_kee", 100);
        set("max_gin", 100);
        set("max_sen", 100);
        setup();
        carry_object("/d/ourhome/obj/skirt")->wear();
        carry_object("/d/ourhome/obj/shoes")->wear();
}

int accept_fight(object me)
{
	return 0;
}



