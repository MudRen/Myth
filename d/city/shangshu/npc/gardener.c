//Creat by waiwai@2001/05/12


#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����", ({ "gardener" }) );
	set("gender", "����");
	set("age", 55);
        set("long",
		"һ������ʵʵ�������ֵַ�ׯ԰����������ķ�˪����\n"
		"�����Ķ�ͷ��������������û��������ע���������Ҳ\n"
		"����ĬĬ���ڻ�԰�﹤����\n"
                );

        set("attitude", "peaceful");

        set("combat_exp", 500000);

        set("str", 25);
        set("int", 27);
        set("cor", 23);
        set("cps", 28);
        set("spi", 30);

        set("force", 1800);
        set("max_force", 900);
        set("force_factor", 25);

        set("mana", 1200);
        set("max_mana", 1200);

        set("mana_factor", 4);

        set_skill("literate", 100);
        set_skill("force", 30);
        set_skill("spells", 90);
        set_skill("unarmed", 30);
        set_skill("sword", 40);
        set_skill("parry", 40);
        set_skill("dodge", 40);
        set_skill("taoism", 90);


        setup();

        carry_object(__DIR__"obj/sword")->wield();
}
