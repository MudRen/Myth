//change.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
           set_name(HIG"ţ��"NOR, ({"niu lang", "niulang", "lang"}));
       set("long",
"ԭ���Ǹ���ţ�ޣ�����֯Ů�మ������һ˫��Ů���󱻷�����������\nֻ��ÿ������³��߲���ȵ����ᡣ\n");
         set("gender", "����");
       set("age", 20);
       set("class", "xian");
        set("title", "");
       set("attitude", "friendly");
       set("per", 30);
	set("int", 30);
           set("max_kee", 1000);
           set("max_gin", 1000);
           set("max_sen", 1000);
           set("force", 1000);
          set("max_force", 1000);
        set("force_factor", 50);
          set("max_mana", 500);
          set("mana", 500);
           set("mana_factor", 0);
          set("combat_exp", 600000);
     set("daoxing", 500000);


          set_skill("literate", 50);
          set_skill("unarmed", 150);
        set_skill("dodge", 100);
          set_skill("force", 100);
          set_skill("parry", 100);
            set_skill("blade", 170);
            set_skill("xuanhu-blade", 170);
          set_skill("spells", 50);
           set_skill("moonshentong", 50);
             set_skill("baihua-zhang", 50);
             set_skill("moondance", 50);
           set_skill("moonforce", 100);
         map_skill("spells", "moonshentong");
         map_skill("force", "moonforce");
             map_skill("blade", "xuanhu-blade");
             map_skill("parry", "xuanhu-blade");
              map_skill("unarmed", "baihua-zhang");
              map_skill("dodge", "moondance");

create_family("�¹�", 2, "����");
setup();

              carry_object("/d/obj/cloth/linen")->wear();
        carry_object("/d/obj/weapon/blade/yuandao")->wield();
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="����")){
           command("shake");
             command("say ��Ů�б��������㣬�պ��������в��㣬�㻹���������˰�!\n");
            return;
}
        command("pat "+ob->query("id"));
        command("say ͬ�����������ˣ������Ҿ������㣡�պ�������������ձ������ɣ�\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xian");
}
