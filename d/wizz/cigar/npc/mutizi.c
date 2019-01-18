// �������� "�������� ľ����" by Calvin

#define DEBUG 0
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string expell_me(object me);

void create()
{
   set_name(CYN"ľ����"NOR, ({"mu tizi", "mu", "tizi","mutizi","tianshen","si"}));
   set("title", CYN"��ľ��"NOR);
   set("gender", "����" );
   set("age", 100);
   set("per", 24);
   set("str", 30);
   set("long", "������Ԫ���ɵĽ������,ǰ����������һ����ľ��\n");
   set("class", "xian");
   set("combat_exp", 5600000);
   set("attitude", "peaceful");
   create_family("��ׯ��", 1, "��ʦ");
   set("rank_info/respect", "ľ��");

   set_skill("unarmed", 350);
   set_skill("wuxing-quan", 350);
   set_skill("dodge", 350);
   set_skill("baguazhen", 350);
   set_skill("parry", 350);
   set_skill("sword", 350);
   set_skill("sanqing-jian", 350);
   set_skill("staff", 350);
   set_skill("fumo-zhang", 350);
   set_skill("hammer", 350);
   set_skill("xiaofeng-sword", 350);
   set_skill("kaishan-chui", 350);
   set_skill("blade", 350);
   set_skill("yange-blade", 350);
   set_skill("force", 350);   
   set_skill("zhenyuan-force", 350);
   set_skill("literate", 350);
   set_skill("spells", 350);
   set_skill("taiyi", 350);
   map_skill("spells", "taiyi");
   map_skill("force", "zhenyuan-force");
map_skill("unarmed", "wuxing-quan");
   map_skill("sword", "sanqing-jian");
   map_skill("dodge", "baguazhen");
   map_skill("staff", "fumo-zhang");
   map_skill("blade", "yange-blade");
   map_skill("hammer", "kaishan-chui");

   set("max_kee", 6000);
   set("max_sen", 6000);
   set("force", 5000);
   set("max_force", 2500);
   set("mana", 7000);
   set("max_mana", 3500);   
   set("force_factor", 200);
   set("mana_factor", 200);

   set("spell_qiankun_on", 1);
   set("chat_chance_combat", 90);
   set("chat_msg_combat", 
   ({
     (: cast_spell, "zhenhuo" :),
     (: cast_spell, "qiankun" :),
   }) );
  setup();
      carry_object("/d/9ct/zb/tianjia")->wear();
//   carry_object("/d/9ct/zb/")->wield();
}

void attempt_apprentice(object ob)
{
   if( (string)ob->query("class")=="dao" )
     command("say �ã��ã����ɱ�һ�ҡ�\n");

   if( (string)ob->query("family/family_name")=="��ׯ��" )
   {
     if( (int)ob->query("family/generation") > 3   )
     {
        command("say ��ׯ���������������Ͳ�,�㻹��ȥ�ǿ����ɡ�\n");
     }
     else 
     {
        if( (int)ob->query("combat_exp") >= 300000 && (int)ob->query_skill("taiyi", 1) >= 120 )
        {
          command("nod ");
          command("say �ã�" + RANK_D->query_respect(ob) + "�����Ǳ��ŵ��˲ţ�\n");
          command("recruit " + ob->query("id") );
ob->set("title",HIR"��ׯ�۳��Ƹ���"NOR);
        }
        else
        {
          command("say �����Ϊ�Ǻܲ���,���ǲ��ϵļ��ͲŻ���á�\n");
        }
     }
   }

   else
   {
     command("nod");
     command("say ��λ" + RANK_D->query_respect(ob) + "���㻹����ȥ��ׯ�ۿ���,ѧ��ʵ��������ɡ�\n");
   }

   return;
}
