// ���NPC.nothing by Calvin of 2001.5

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name(HIW"������"NOR, ({"dan chenzi","dan","chenzi","zi"}));
        set("title", HIG"����ɽ֮ʦ��"NOR);
        set("gender", "����" );
        set("age", 17);
        set("per", 37);
        set("str", 238);
// set("long",".....\n");

//        set("attitude", "aggressive");
       set("shen_type", 1);
       set("combat_exp", 10206147);
       set("daoxing", 7000000);
       set("max_kee", 2018);
       set("max_gin", 210);
       set("max_sen", 2000);
       set("force", 10000);
       set("max_force", 5000);
       set("force_factor", 210);
       set("max_mana", 7500);
       set("mana", 15000);
       set("mana_factor", 210);

       set_skill("dodge", 296);
       set_skill("force", 287);
       set_skill("fork", 295);
       set_skill("literate", 160);
       set_skill("parry", 295);
       set_skill("spells", 296);
       set_skill("unarmed", 295);
       set_skill("dragonfight", 296);
       set_skill("dragonforce", 295);
       set_skill("dragonstep", 296);
       set_skill("fengbo-cha", 296);
       set_skill("moondance", 296);
       set_skill("seashentong", 296);
        map_skill("dodge", "moondance");
        map_skill("force", "dragonforce");
        map_skill("fork", "fengbo-cha");
        map_skill("parry", "fengbo-cha");
        map_skill("spells", "seashentong");
        map_skill("unarmed", "dragonfight");

       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
                (: cast_spell, "hufa" :),
                (: cast_spell, "dragonfire" :),
                (: perform_action, "unarmed", "sheshen" :),
                (: perform_action, "unarmed", "leidong" :),
                }) );

        set_temp("apply/armor",50);
        set_temp("apply/damage",25);
        setup();
        carry_object("/d/obj/armor/jinjia")->wear();
        carry_object("/d/city/npc/obj/pifeng")->wear();
        carry_object("/d/city/npc/obj/kui")->wear();
        carry_object("/d/obj/stey/xianyi")->wear();
        carry_object("/d/city/npc/obj/shoes")->wear();
        carry_object("/d/city/npc/obj/shield")->wear();
        carry_object("/d/calvin/obj/yjl")->wear();
//        carry_object("/d/calvin/armor/wan")->wield();
}
