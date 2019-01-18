// huanwangzi.c ������

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"������"NOR, ({"huan wangzi", "huan"}));
       set("long", "ϲ���ٻ����󣬲����޵���ƶ��Ͷ��ħ����Ϊ��������\n");
       set("title", HIC"��һ��"NOR);
       set("per", 30);
       set("gender", "����");
       set("age", 65);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "�ϵ���");
       set("max_kee", 1000);
       set("max_gin", 100);
       set("max_sen", 1000);
       set("force", 1200);
       set("max_force", 1200);
       set("force_factor", 120);
       set("max_mana", 1200);
       set("mana", 1200);
       set("mana_factor", 120);
       set("combat_exp", 1200000);
       set("daoxing", 1100000);

        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("spells", 40);  
        set_skill("tianmogong", 40);
        set_skill("literate", 80);
        set_skill("sword", 80);  
        set_skill("huxiaojian", 80);
        set_skill("zhaoyangbu", 80);
        set_skill("force", 80);   
        set_skill("huntianforce", 80);

        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("sword", "huxiaojian");
        map_skill("parry", "huxiaojian");
        map_skill("dodge", "zhaoyangbu");

	create_family("����ɽ", 3, "��");
	
	set("inquiry", ([
	"name"     : "����Խ��һ����ӡ�\n",
	"here"     : "���ﲻ�Ǻõط���������ٻ����󣬿��Ը���һ���ߡ�\n",
	]));	
	
	setup();
	carry_object("/d/sanjie/obj/jinjia")->wear();
	carry_object("/d/sanjie/obj/qinghong")->wield();
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
