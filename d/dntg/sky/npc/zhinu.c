//change.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
           set_name(HIM"֯Ů"NOR, ({"zhi nu", "zhinu", "xian"}));
       set("long",
"����ĸ������Ů����Ϊ˽���·���ţ���మ������������������\nֻ��ÿ������³��߲���ȵ����ᡣ\n");
       set("gender", "Ů��");
       set("age", 20);
       set("class", "xian");
        set("title", "");
       set("attitude", "friendly");
       set("rank_info/respect", "�ɹ�");
       set("per", 30);
	set("int", 30);
         set("max_kee", 1500);
         set("max_gin", 1500);
         set("max_sen", 1500);
         set("force", 1200);
         set("max_force", 1200);
       set("force_factor", 50);
         set("max_mana", 1200);
         set("mana", 1200);
         set("mana_factor", 80);
         set("combat_exp", 800000);
    set("daoxing", 2000000);



         set_skill("literate", 140);
         set_skill("unarmed", 120);
       set_skill("dodge", 180);
         set_skill("force", 120);
         set_skill("parry", 120);
           set_skill("blade", 150);
           set_skill("xuanhu-blade", 150);
         set_skill("spells", 120);
          set_skill("moonshentong", 120);
          set_skill("baihua-zhang", 120);
          set_skill("moonforce", 120);
        set_skill("moondance", 200);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
            map_skill("blade", "xuanhu-blade");
            map_skill("parry", "xuanhu-blade");
        map_skill("dodge", "moondance");

create_family("�¹�", 2, "����");
setup();

             carry_object("/d/moon/obj/luoyi")->wear();
             carry_object("/d/obj/flower/rose")->wear();
       carry_object("/d/obj/weapon/blade/yangdao")->wield();
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="Ů��")){
           command("shake");
             command("say ��Ů�б��������㣬�պ��������в��㣬�㻹���������˰�!\n");
            return;
}
        command("pat "+ob->query("id"));
        command("say ��Ȼ��Ҳ�ǳ���Ů���Ҿ������㣡�պ�������������ձ������ɣ�\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xian");
}
