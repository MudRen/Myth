//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/npc/heshang.c
 
inherit NPC;

void create()
{
        set_name("С����", ({"he shang","monk"}));
        set("long", "һλ����У����������Ƶĺܣ����ﻹ��ͣ��ӽ����\n");

        set("gender", "����");
        set("attitude", "peaceful");
        set("class", "bonze");

        set("age", 10+random(10));
        set("combat_exp", 15000);
        set("shen_type", 1);
        set("per", 25);
        set("max_kee", 380);
        set("max_gin", 300);
        set("force", 250);
        set("force_factor", 5);
        set_skill("force", 20+random(20));
        set_skill("unarmed", 20+random(20));
        set_skill("dodge", 20+random(20));
        set_skill("parry", 20+random(40));

        setup();
        carry_object("/d/obj/cloth/sengyi")->wear();

        setup();
}

int accept_fight(object me)
{
        command("say �ðɣ����꼼�գ��㵽Ϊֹ��\n");
        return 1;
}

