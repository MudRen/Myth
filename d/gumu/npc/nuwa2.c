//��ԯ��Ĺ�ռ�ʦ�� Ů�
//by junhyun@SK
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
string avenge();
void create()
{
       set_name(HIW"Ů�"NOR, ({"nu wa", "nuwa", "nu","wa","master","tianshen"}));
       set("long", "���֮ĸ���������������ʯ���죬
��ٶ��ж��ϲԣ���Ϊ�����ʥ������𣬺���槼��Ⱦ�
����Ů��ר�Ÿ�������
\n");
       set("title", HIM"���֮ĸ"NOR);
       set("gender", "Ů��");
       set("age", 100);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/respect", "����");
       set("cor", 30);
       set("per", 40);
      set("looking", "����Ʈ��,����ʵ�á�");
       set("max_kee", 6000);
       set("max_gin", 1000);
       set("max_sen", 6000);
       set("force", 12000);
       set("max_force", 6000);
       set("force_factor", 300);
       set("max_mana", 6000);
       set("mana", 12000);
       set("mana_factor", 400);
       set("combat_exp", 30000000);
       set("daoxing", 50000000);
       set_skill("literate", 350);
       set_skill("unarmed", 350);
       set_skill("dodge", 350);
       set_skill("force", 350);
       set_skill("parry", 350);
       set_skill("sword", 350);
       set_skill("spells", 350);
      set_skill("youming-spells", 350);
       set_skill("jiuyin-zhua", 350);
     set_skill("jiuyin-force", 350);
      set_skill("shengling-sword", 350);
      set_skill("kongming-steps", 350);

   map_skill("spells", "youming-spells");
   map_skill("unarmed", "jiuyin-zhua");
   map_skill("force", "jiuyin-force");
   map_skill("sword", "shengling-sword");
   map_skill("parry", "shengling-sword");
   map_skill("dodge", "kongming-steps");
   set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                 (: perform_action, "sword", "sword21" :),
        }) );
create_family("��ԯ��Ĺ", 1, "��");
setup();


        carry_object("/d/wizz/junhyun/obj/weapon/shengling-sword")->wield();
}

void attempt_apprentice(object ob)



{
   if ( (string)ob->query("family/family_name")=="��ԯ��Ĺ") {
   if (((int)ob->query("combat_exp") < 5000000 )) {
   command("say " + RANK_D->query_respect(ob) +
"�ĵ��в��������Щ��ѧ�ط�������������\n");
   return;
   }
     command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ�����պ�Ϊ������������\n");
       command("recruit " + ob->query("id") );
        ob->set("title", HIW"Ů����� "HIB"����ʥʹ"NOR);
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"������ȥѧЩ��������ɡ�\n");
        return;
}

