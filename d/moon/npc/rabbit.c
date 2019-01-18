//change.c
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("����", ({"yu tu", "rabbit", "jade rabbit" }));
       set("long",
"������ԭ��ֻ���϶�ĳ��������϶���ڵ��ϵ���ҩ�������Ρ�����
����ҩ֮�±���ĸ��ȥ��ҩ���ö���֮����ͨҩ����\n");
       set("gender", "Ů��");
       set("age", 20);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "�ɹ�");
       set("per", 30);
	set("int", 30);
       set("max_kee", 500);
       set("max_gin", 500);
       set("max_sen", 800);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 50);
       set("max_mana", 600);
       set("mana", 600);
       set("mana_factor", 40);
       set("combat_exp", 200000);
  set("daoxing", 200000);


        set("eff_dx", 200000);
        set("nkgain", 100);

       set_skill("literate", 50);
       set_skill("unarmed",50);
       set_skill("dodge", 100);
       set_skill("force", 80);
       set_skill("parry", 80);
       set_skill("sword", 80);
       set_skill("spells", 50);
        set_skill("moonshentong", 50);
        set_skill("baihua-zhang", 50);
        set_skill("moonforce", 80);
        set_skill("moondance", 100);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("dodge", "moondance");

create_family("�¹�", 2, "����");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/d/moon/obj/daoyaochu")->wield();
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="Ů��")){
           command("shake");
           command("say �����¹�ֻ��Ůͽ����λ" +
RANK_D->query_respect(ob) + "��������߾Ͱɡ�\n");
           return;
        }

        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ�����������¹�������\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xian");
}


�