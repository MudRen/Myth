// wiuxuke.c ����

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"����"NOR, ({"qiu xuke", "qiu"}));
       set("long", "���׿��޵���ѧϰ�����������ڴ�ʦ�֣����޹��뿪ʦ�ţ���Ѷȫ�ޣ�\n");
       set("title", HIC"��һ��"NOR);
       set("per", 30);
       set("gender", "����");
       set("age", 35);
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
       set("combat_exp", 1400000);
       set("daoxing", 1500000);

        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("spells", 80);  
        set_skill("tianmogong", 80);
        set_skill("literate", 80);
        set_skill("sword", 120);  
        set_skill("huxiaojian", 120);
        set_skill("zhaoyangbu", 80);
        set_skill("force", 80);   
        set_skill("huntianforce", 80);
        set_skill("unarmed", 120); 
        set_skill("huxiaoquan", 120); 

        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("sword", "huxiaojian");
        map_skill("parry", "huxiaojian");
        map_skill("dodge", "zhaoyangbu");
        map_skill("unarmed", "huxiaoquan");

	create_family("����ɽ", 3, "��");
	
	set("inquiry", ([
	"name"     : "�ҽ����ͣ������ҵ���������������㲻��Ҳ�ա�\n",
	"here"     : "���Ǻ�ɽ���أ�û����׼���ܽ������������Ȼ�Ե���Ҳ�����Ե�֡�\n",
	"����"     : "����İ���ͼ����ͨ����һ�ɸ�����������û��������֣���Ҫ��Ե�ˡ�\n",
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
