#include <ansi.h>

inherit NPC;

void create()
{
        set_name("��Ů", ({"shi nu", "nu", "waiter"}));
        set("gender", "Ů��");
        set("long","�ʹ��е���Ů������ʹ������ʳ��ӵ�����\n");
        set("combat_exp", 1000+random(4000));
        set("attitude", "friendly");
        set("max_kee", 200);
        set("max_gin", 200);
	set("max_sen", 200);
        set("force", 100);
        set("max_force", 100);
        set("force_factor", 5);
        set_skill("unarmed", 15);
        set_skill("parry", 15);
        set_skill("dodge", 15);

        setup();
	carry_object("/d/obj/cloth/p_cloth")->wear();
}

