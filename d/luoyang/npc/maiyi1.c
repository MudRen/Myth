#include <ansi.h>
inherit NPC;

void create()
{
        set_name("ˣ����", ({ "shuahou ren", "ren" }) );
        set("gender", "����" );
        set("age", 25);
        set("long",
              "һ���ؽ�ˣ����ˡ�\n");
        set("shen_type", 1);
        set("combat_exp", 10000);
        set("daoxing", 10000);
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        set("attitude", "peaceful");
        set_skill("dodge",20);
        set_skill("unarmed",20);
        set("chat_chance", 2);
        set("chat_msg", ({
                 CYN "ˣ���˴����е����߹�·����Ҫ�������ҿ������ơ�\n" NOR,
        }) );

        setup();
        add_money("silver", 10);
}

