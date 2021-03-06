//Creat by waiwai@2001/05/12


#include <ansi.h>

inherit NPC;

void create()
{
        set_name("花匠", ({ "gardener" }) );
	set("gender", "男性");
	set("age", 55);
        set("long",
		"一个老老实实、本本分分的庄园花匠，多年的风霜刻满\n"
		"了他的额头。多年以来从来没有人认真注意过他，他也\n"
		"总是默默地在花园里工作。\n"
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
