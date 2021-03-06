// xue.c

#include <ansi.h>
inherit NPC;

#include "greeting.h"
#include "tongchuan.h"

void create()
{
        set_name("薛仁贵", ({ "xue rengui", "xue", "rengui" }) );
        set("gender", "男性");
        set("age", 35);
        set("long","薛仁贵是长安城九门提督，负责皇宫内外安全。\n");
        set("combat_exp", 200000000);
        set("daoxing", 200000000);
        set("title", HIR"九门提督"NOR);
        set("nickname", HIY"勇冠三军"NOR);
        set("attitude", "friendly");
        set("per", 25);
        set("str", 35);
        set("max_kee", 20000);
        set("max_sen", 20000);
        set("max_mana", 20000);
        set("mana", 40000);
        set("force", 40000);
        set("max_force", 20000);
        set("force_factor", 500);
        set_skill("spear", 500);
        set_skill("unarmed", 500);
        set_skill("changquan", 500);
        set_skill("parry", 500);
        set_skill("dodge", 500);
        set_skill("bawang-qiang", 500);
        set_skill("yanxing-steps", 500);
        map_skill("spear", "bawang-qiang");
        map_skill("parry", "bawang-qiang");
        map_skill("dodge", "yanxing-steps");
        map_skill("unarmed", "changquan");
        set("inquiry", ([ //
            "效力" : (: ask_tongchuan :),
                ]));
        setup();

        carry_object("/d/obj/weapon/spear/tiespear")->wield();
        carry_object("/d/obj/armor/tongjia")->wear();
}

void init ()
{
        greeting2(this_player());
}

int accept_fight(object me)
{
        command("say 我为殿前将军，岂能与你村野匹夫较艺！");
        return 0;
}

