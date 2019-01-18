// xue.c

#include <ansi.h>
inherit NPC;

#include "greeting.h"
#include "tongchuan.h"

void create()
{
        set_name("Ѧ�ʹ�", ({ "xue rengui", "xue", "rengui" }) );
        set("gender", "����");
        set("age", 35);
        set("long","Ѧ�ʹ��ǳ����Ǿ����ᶽ������ʹ����ⰲȫ��\n");
        set("combat_exp", 200000000);
        set("daoxing", 200000000);
        set("title", HIR"�����ᶽ"NOR);
        set("nickname", HIY"�¹�����"NOR);
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
            "Ч��" : (: ask_tongchuan :),
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
        command("say ��Ϊ��ǰ���������������Ұƥ����գ�");
        return 0;
}

