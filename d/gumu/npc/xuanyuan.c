//��ԯ��Ĺ�ռ�ʦ�� ��ԯ��
//by junhyun@SK
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
string avenge();
void create()
{
        set_name("��ԯ��", ({"xuanyuan gong", "xuanyuan", "gong","master","tianshen"}));
       set("long", "����ٵ�֮����Ů�ƽ��ƽ��������Ϊ
�ŷ������ò������ɵ���ͬ��
\n");
       set("title", HIW"����ٵ�"NOR);
       set("color", HIR);
       set("gender", "����");
       set("age", 100);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/respect", "����");
       set("cor", 30);
       set("per", 40);
      set("looking", "�ɷ���ǣ���ֹ������");
       set("max_kee", 6000);
       set("max_gin", 1000);
       set("max_sen", 6000);
       set("force", 4000);
       set("max_force", 2000);
       set("force_factor", 125);
       set("max_mana", 2000);
       set("mana", 4000);
       set("mana_factor", 100);
       set("combat_exp", 5000000);
       set("daoxing", 5000000);
       set_skill("literate", 350);
       set_skill("unarmed", 350);
       set_skill("dodge", 350);
       set_skill("force", 350);
       set_skill("parry", 350);
       set_skill("blade", 350);
       set_skill("spells", 350);
      set_skill("youming-spells", 350);
       set_skill("jiuyin-zhua", 350);
     set_skill("jiuyin-force", 350);
      set_skill("mohuang-blade", 350);
      set_skill("kongming-steps", 350);

   map_skill("spells", "youming-spells");
   map_skill("unarmed", "jiuyin-zhua");
   map_skill("force", "jiuyin-force");
   map_skill("blade", "mohuang-blade");
   map_skill("parry", "shengling-sword");
   map_skill("dodge", "kongming-steps");
   set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                 (: perform_action, "blade", "posui" :),
        }) );
create_family("��ԯ��Ĺ", 1, "��");
setup();


        carry_object("/d/wizz/junhyun/obj/weapon/xuanyuan-blade")->wield();
}

void attempt_apprentice(object ob)



{
   if ( (string)ob->query("family/family_name")=="��ԯ��Ĺ") {
   if (((int)ob->query("combat_exp") < 2000000 )) {
   command("say " + RANK_D->query_respect(ob) +
"�ĵ��в��������Щ��ѧ�ط�������������\n");
   return;
   }
     command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ�����պ�Ϊ������������\n");
       command("recruit " + ob->query("id") );
        ob->set("title", HIW"��ԯ���� "HIB"�����ħ"NOR);
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"������ȥѧЩ��������ɡ�\n");
        return;
}

