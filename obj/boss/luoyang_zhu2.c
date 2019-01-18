#include <ansi.h>

inherit F_VENDOR_SALE;

void create()
{
        set_name("÷Ï“˚", ({ "zhu yin", "zhu", "yin" }));
        set("gender", "ƒ––‘");
        set("title", "Œ‰∆˜µÍ¿œ∞Â");
        set("age", 45);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("blade", 80);
        set_skill("staff", 80);
        set_skill("sword", 80);
        set_skill("throwing", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);

        set("combat_exp", 400000);
        set("shen_type", 1);
        setup();
        set("vendor_goods", ([
               "dagger": "/d/obj/weapon/dagger/dagger.c",
                "axe": "/d/obj/weapon/axe/tiefu.c",
                "hammer": "/d/obj/weapon/hammer/hammer",
                "fork": "/d/obj/weapon/fork/fork",
                "tiegun": "/d/obj/weapon/stick/bintiegun",
                "tielian":"/d/obj/weapon/whip/tielian",
                "shield": "/d/obj/armor/niupi",
                "sword": "/d/obj/weapon/sword/changjian",
                "blade": "/d/obj/weapon/blade/blade",
                "spear": "/d/obj/weapon/spear/tieqiang",
                "staff": "/d/obj/weapon/staff/chanzhang",
        ]) );
        carry_object("/d/obj/weapon/blade/jindao");
}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}

