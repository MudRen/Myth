#include <ansi.h>

inherit F_VENDOR_SALE;

void create()
{
        set_name("ÖìÕþ", ({ "zhu zheng", "zhu", "zheng" }));
        set("gender", "ÄÐÐÔ");
        set("title", "¿ø¼×µêÀÏ°å");
        set("age", 45);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("unarmed", 80);
        set_skill("blade", 80);
        set_skill("staff", 80);
        set_skill("sword", 80);
        set_skill("throwing", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);

        set("combat_exp", 400000);
        set("daoxing", 10000);
        set("shen_type", 1);
        setup();
        set("vendor_goods", ([
                "tiejia":"/d/obj/armor/tiejia",
                "tiekui":"/d/city/npc/obj/kui",
                "chanyi":"/d/obj/armor/gold-chanyi",
        ]));
        carry_object("/d/obj/armor/jinjia");
        carry_object("/d/luoyang/obj/jinkui");
        carry_object("/d/luoyang/obj/wanlun");
}

void init ()
{
  ::init();
  add_action ("do_vendor_list", "list");
}

