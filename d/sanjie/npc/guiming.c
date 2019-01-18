// guiming.c ��ڤ

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIW"��ڤ"NOR, ({"master guiming", "master"}));
       set("long", "�ǹ���ʦ�ܣ������������������������ʦ��ǿ���ˡ�\n");
       set("title", HIC"��ʬ��"NOR);
       set("per", 40);
       set("gender", "����");
       set("age", 400);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "����");
       set("max_kee", 2000);
       set("max_gin", 100);
       set("max_sen", 2000);
       set("force", 3000);
       set("max_force", 3000);
       set("force_factor", 300);
       set("max_mana", 2400);
       set("mana", 2400);
       set("mana_factor", 270);
       set("combat_exp", 2400000);
       set("daoxing", 3500000);

        set_skill("dodge", 160);
        set_skill("parry", 200);  
        set_skill("tianmogong", 160);
        set_skill("literate", 200);
        set_skill("unarmed", 200);  
        set_skill("liushenjue", 200);
        set_skill("zhaoyangbu", 160);
        set_skill("force", 200);   
        set_skill("huntianforce", 200);

        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("sword", "liushenjue");
        map_skill("dodge", "zhaoyangbu");
        
        set("chat_msg_combat", ({
		(: cast_spell, "zhui" :),
        }) );

	create_family("����ɽ", 1, "��");
	
	set("inquiry", ([
	"name"     : "�Ϸ��˹�ڤ������ʦ�ܡ�\n",
	"here"     : "���˲�ʬ�أ�û��������������ܡ�\n",
	]));
	
	set("time", 1);
	
	setup();
	carry_object("/d/sanjie/obj/jinjia")->wear();
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="����ɽ") {
	if ((int)ob->query("daoxing") < 500000 ) {
  	command("say ��ĵ��л�������" + RANK_D->query_respect(ob) + "������Ŭ����\n");
	return;
	}

	if( (int)ob->query("pending/kick_out")) {
	command("say ��λ" + RANK_D->query_respect(ob) + "���������ɣ��Ҳ�ԭ������Ϊͽ�ˣ�\n");
	command("sigh");
	return;
	}

	if ((int)ob->query_int() < 25) {
	command("say ��λ" + RANK_D->query_respect(ob) + "����̫�ͣ�����������Ҳ������Ϊ��\n");
	command("sigh");
	return;
	}
	if( (int)ob->query_skill("huntianforce", 1) < 100 ) {
	command("say ��λ" + RANK_D->query_respect(ob) + "�Ի��챦����ỹ�������������Ҳ����Ϊ���ѣ��������գ�\n");
	command("sigh");
	return;
	}
        command("smile");
        command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
        command("recruit " + ob->query("id") );
	return;
	}
        command("shake");
        command("say �Ϸ������ŵ��ӣ�" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "sanjie");
}

�
