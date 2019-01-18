// guiyou.c ����

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"����"NOR, ({"gui you", "gui"}));
       set("long", "�ǹ�ڤ��ʦ�֣�����Ů�����Ǯ���书����ʦ�ܻ��\n");
       set("title", HIC"��ʬ��"NOR);
       set("per", 30);
       set("gender", "����");
       set("age", 46);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "����");
       set("max_kee", 1000);
       set("max_gin", 100);
       set("max_sen", 1000);
       set("force", 1200);
       set("max_force", 1200);
       set("force_factor", 120);
       set("max_mana", 1500);
       set("mana", 1500);
       set("mana_factor", 120);
       set("combat_exp", 1000000);
       set("daoxing", 1100000);

        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("spells", 100);  
        set_skill("tianmogong", 100);
        set_skill("literate", 100);
        set_skill("unarmed", 100);  
        set_skill("liushenjue", 100);
        set_skill("zhaoyangbu", 100);
        set_skill("force", 100);   
        set_skill("huntianforce", 100);

        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("unarmed", "liushenjue");
        map_skill("dodge", "zhaoyangbu");

	create_family("����ɽ", 2, "��");

	set("inquiry", ([
	"name"     : "���ǲ�ʬ�ش���ӣ���������ʲô�£���\n",
	"here"     : "�����ǲ�ʬ�أ�����С�����ʲô��\n",
	]));	
	
	setup();
	carry_object("/d/sanjie/obj/jinjia")->wear();
}

void attempt_apprentice(object ob, object me)
{
        command("say �ܺã�" + RANK_D->query_respect(ob) +"���Ŭ�������ձض��гɡ�\n");
        command("recruit " + ob->query("id") );
	return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "sanjie");
}

�
