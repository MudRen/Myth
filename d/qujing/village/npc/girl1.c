//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/village/npc/girl1.c

inherit NPC;
#include <ansi.h>

void create()
{
   set_name(HIC"����"NOR, ({ "su su", "susu"}));
   set("gender", "Ů��" );
   set("age", 15);
   set("per",39);
   set("long",
     "һλ��ɫ��Ů��\n");

   set("combat_exp", 600+random(400));
   set("attitude", "friendly");
   set_skill("dodge", 10);
   set_skill("unarmed", 10);
   setup();
   carry_object("/obj/cloth")->wear();
   add_money("silver", 3+random(20));
}

