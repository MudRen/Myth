#include <ansi.h> 

inherit "/std/char/smith.c"; 

void create()
{
        set_name("����", ({ "tiejiang", "smith" }));
        set("long", "����������ǯ��סһ����ȵ�����Ž�¯�С�\n");
        set("gender", "����");
        set("title", "�������ϰ�");
        set("per", 15);
        set("combat_exp", 6800);
        set("age", 36);
        set("attitude", "friendly");
        set("shen_type", 1);
        set_skill("unarmed", 15);
        setup();
        add_money("coin", 50+random(200));
        carry_object("/obj/cloth")->wear();
        carry_object("/d/obj/weapon/hammer/hammer")->wield();
}

