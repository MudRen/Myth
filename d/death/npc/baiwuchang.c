// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("���޳�", ({ "bai wuchang","wuchang", "gargoyle" }));
        set("long","һ�����°׾���Ƥ��ʹ�ߣ����׵����Ͽ������κ�ϲŭ���֡�\n");
        set("attitude", "peaceful");
	set("per", 10);
	set("str", 25);
	set("int", 25);
        set("age", 30);
	set("title", "�л�˾��");
        set("combat_exp", 120000);
  set("daoxing", 200000);

        set("max_gin", 1000);
        set("max_kee", 1000);
        set("max_sen", 1000);
	set("class", "youling");
	set("force", 1500);
	set("max_force", 800);
	set("force_factor", 50);
	set("max_mana", 600);
	set("mana", 1000);
	set("mana_factor", 40);
	set_skill("ghost-steps", 60);
        set_skill("dodge", 60);
        set_skill("unarmed", 60);
	set_skill("parry", 60);
	set_skill("spells", 80);
	set_skill("gouhunshu", 80);
	set_skill("jinghun-zhang", 60);
	set_skill("force", 60);
	set_skill("tonsillit", 60);
/*
	set_skill("stick", 100);
	set_skill("kusang-bang", 100);
	map_skill("stick", "kusang-bang");
	map_skill("parry", "kusang-bang");
*/
	map_skill("spells", "gouhunshu");
	map_skill("dodge", "ghost-steps");
	map_skill("force", "tonsillit");
	map_skill("unarmed", "jinghun-zhang");
create_family("���޵ظ�", 3, "���");
  set("inquiry",([
   "name":"�����л�ʹ���޳�����ʮ��ڤ��֮����ǰ�����乴�ꡣ\n",
   "here":"���������޵ظ���\n",
   "����":"�Ұ��������鹴�ˣ�����ԩ�������뷢�˹���֮ڤ������(complain)��\n",
   "ԩ��":"�Ұ��������鹴�ˣ�����ԩ�������뷢�˹���֮ڤ������(complain)��\n",
   "ԩ��":"�Ұ��������鹴�ˣ�����ԩ�������뷢�˹���֮ڤ������(complain)��\n",
  ]));

        setup();
	carry_object("/d/obj/cloth/bai")->wear();
}


void attempt_apprentice()
{
	object me;
	me = this_player();
        command("grin");

        command("say �ܺã�" + RANK_D->query_respect(me) +
"���Ŭ�������ձض��гɡ�\n");
       command("recruit " + me->query("id") );
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youling");
//		ob->set("title", "�ظ��л�˾����");
}

�
