// ������ by Calvin

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�ϰ�", ({"boss","waiter"}));
        set("title","�Ĵ��");
        set("gender", "����" );
        set("age", 45);
        set("per",18);
        set("long", "�Ĵ���ϰ�! \n");
        set("class","taoist");
        set("combat_exp", 25000);
        set("daoxing",25000);
        set("attitude", "peaceful");
        set_skill("unarmed",100);
        set("max_kee", 700);
        set("max_gin", 700);
        set("max_sen", 700);
        set("max_force",800);
        set("force",800);
        set("max_mana",800);
        set("mana",800);
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}
