//change.c
inherit NPC;
inherit F_MASTER;
int youyuan();

void create()
{
       set_name("�����ɹ�",({"chi meng","dream", "fairy"}));
       set("long",
"�����Խ�����ɹ�Ҳ�����ܽ���֮л��������Ե�߶�֮��\n");
       set("title", "�Խ����");
       set("gender", "Ů��");
       set("age", 18);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "�ɹ�");
       set("per", 30);
	set("int", 30);
       set("max_kee", 1000);
       set("max_gin", 1000);
       set("max_sen", 1000);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 50);
       set("max_mana", 500);
       set("mana", 500);
       set("mana_factor", 40);
       set("combat_exp", 1000000);
  set("daoxing", 500000);


        set("eff_dx", 100000);
        set("nkgain", 300);

       set_skill("literate", 90);
       set_skill("unarmed", 80);
       set_skill("dodge", 100);
       set_skill("force", 120);
        set_skill("parry", 120);
       set_skill("whip", 180);
       set_skill("unarmed", 80);
       set_skill("spells", 120);
        set_skill("sword", 140);
       set_skill("baihua-zhang", 120);
        set_skill("moonshentong",140);
        set_skill("jueqingbian", 180);
        set_skill("moonforce", 120);
            set_skill("snowsword", 140); 
        set_skill("moondance", 100);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("whip", "jueqingbian");
        map_skill("parry", "jueqingbian");
        map_skill("dodge", "moondance");
        map_skill("sword", "snowsword");

create_family("�¹�", 2, "����");
        set("inquiry", (["��Ե"   : (:youyuan:),]));
setup();

        carry_object("/d/obj/cloth/luoyi")->wear();
        carry_object("/d/moon/obj/moonsword")->wield();
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("title")=="�㺮������")
	  {
	command("jump");
        command("say ��Ȼ���Ž��Ը������ѧϰ,�Һܸ���!\n");
        command("recruit " + ob->query("id") );
	return;
	}
        if ( !((string)ob->query("gender")=="Ů��")){
           command("shake");
           command("say �����¹�ֻ��Ůͽ����λ" +
RANK_D->query_respect(ob) + "��������߾Ͱɡ�\n");
           return ;
        }
	if (random(this_player()->query_kar()) < 20 || this_player()->query("mark/moon_chimeng")){
	  this_player()->set("mark/moon_chimeng", 1);
	  command("shake");
	  command("say ������Ե����������߾Ͱɡ�\n");
	  return ;
	}
        else{
	command("pat "+ob->query("id"));
        command("say ��Ȼ" + RANK_D->query_respect(ob) +
"������Ե���Ҿ��������ˡ�\n");
        command("recruit " + ob->query("id") );
        return ;}
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xian");
}

int youyuan()
{
object youyuan;
object who=this_player();
command("sigh");
who->delete("mark");
return 1;
}
�
