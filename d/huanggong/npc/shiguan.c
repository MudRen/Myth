#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�̹�", ({"shi guan", "guan", "waiter"}));
        set("gender", "����");
        set("long","�ʹ��е�С�٣�����ʹ��ڲ�����\n");
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
	carry_object("/d/obj/cloth/choupao")->wear();
}

