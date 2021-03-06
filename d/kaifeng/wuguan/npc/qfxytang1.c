//xue.c
inherit "/u/helpler/npc/clubdd_master";

#include <ansi.h>

void create()
{
        set_name("清风前堂主", ({ "qfxy qiantangzhu" }) );
        set("gender", "男性");
        set("age", 35);
        set("long","清风前堂主是清风细雨楼，负责前堂安全。\n");
        set("combat_exp", 350000);
        set("title", HIR"清风前堂主"NOR);
        set("nickname", HIY"神气飞扬的"NOR);
        set("attitude", "friendly");
        set("per", 25);
        set("str", 35);
        set("max_kee", 850);
        set("max_gin", 600);
        set("max_mana", 500);
        set("mana", 500);
        set("force", 600);
        set("max_force", 600);
        set("force_factor", 35);
        set_skill("spear", 80);
        set_skill("unarmed", 80);
        set_skill("changquan", 70);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("bawang-qiang", 70);
        set_skill("yanxing-steps", 70);
        map_skill("spear", "bawang-qiang");
        map_skill("parry", "bawang-qiang");
        map_skill("dodge", "yanxing-steps");

        carry_object("/d/obj/weapon/spear/tiespear")->wield();
        carry_object("/d/obj/armor/tongjia")->wear();
}



