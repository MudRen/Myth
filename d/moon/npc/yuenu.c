//change.c
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("��ū", ({"yue nu", "yuenu", "yue","master"}));
       set("long",
"�����ǹ��������֮�������ɣ�����϶�Ϊʦ��\n");
       set("title", "����");
       set("gender", "Ů��");
       set("age", 20);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "�ɹ�");
       set("per", 30);
	set("int", 30);
       set("max_kee", 500);
       set("max_gin", 500);
       set("max_sen", 500);
       set("force", 500);
       set("max_force", 500);
       set("force_factor", 20);
       set("max_mana", 300);
       set("mana", 300);
       set("mana_factor", 20);
       set("combat_exp", 200000);
  set("daoxing", 100000);


        set("eff_dx", 70000);
        set("nkgain", 260);

       set_skill("literate", 20);
       set_skill("unarmed", 50);
       set_skill("dodge", 80);
       set_skill("force", 50);
       set_skill("parry", 50);
       set_skill("sword", 50);
       set_skill("spells", 50);
        set_skill("moonshentong", 60);
        set_skill("baihua-zhang", 60);
        set_skill("moonforce", 60);
        set_skill("snowsword", 60);
        set_skill("moondance", 60);
           set_skill("whip", 50);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("sword", "snowsword");
        map_skill("parry", "snowsword");
        map_skill("dodge", "moondance");

create_family("�¹�", 3, "����");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
      //  carry_object("/d/moon/obj/guihuajian")->wield();
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
