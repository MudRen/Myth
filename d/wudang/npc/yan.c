// yan.c ִ��

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("ִ�����", ({ "zhi zhen" }));
        set("long","��������ʮ��ͷ��ͣ�˫��ȴ�зϣ���ħ���������������佣��\n");
        set("gender", "����");
        set("age", 31);
        set("attitude", "peaceful");
        set("str", 25);
	set("mana", 2000);
	set("max_mana", 2000);
	set("force", 2500);
	set("max_force", 2500);
	set("combat_exp", 1200000);

        set_skill("force", 100);
        set_skill("dodge", 150);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("sword", 100);
	set_skill("spells", 200);
	
	map_skill("spells", "dao");

	set("chat_chance", 1);

        set("chat_msg", ({
            "ִ�����˵�������佣���Ƕ�ʦ����Ѫ��",
            "ִ���������̾������ħ�����������ܳ���"
        }));

        create_family("�䵱��", 2, "����");

        setup();
	carry_object("/d/obj/weapon/sword/changjian")->wield();
        carry_object("/d/wudang/obj/bluecloth")->wear();
}
