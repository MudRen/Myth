
// bula and mon@xyj

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

        me->set("title","��ڤ���");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("whip", j+random(15));
        me->set_skill("hellfire-whip", j+random(15));
        me->set_skill("stick",j+random(15));
        me->set_skill("kusang-bang",j+random(15));
        me->set_skill("ghost-steps", j+random(15));
        me->set_skill("jinghun-zhang", j+random(15));
        me->set_skill("tonsillit", j+random(15));
        me->set_skill("gouhunshu", j+random(15));

        me->map_skill("force", "tonsillit");
         me->map_skill("whip", "hellfire-whip");
        me->map_skill("stick","kusang-bang");
        me->map_skill("parry", "kusang-bang");
        me->map_skill("spells", "gouhunshu");
        me->map_skill("dodge", "ghost-steps");
        me->map_skill("unarmed", "jinghun-zhang");

	set("chat_chance_combat", cast_chance(level));
        set("chat_msg_combat", ({
        (: perform_action,"whip", "three" :),
        (: cast_spell, "gouhun" :),
        (: exert_function, "sheqi" :),
//        (: cast_spell, "dingshen" :),
        }) );

        if (random(2))
           weapon=new("/d/obj/weapon/whip/tielian");
        else
           weapon=new("/d/obj/weapon/stick/xiangmo");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        command("wield all");
}
