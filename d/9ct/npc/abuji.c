// �������� "�������� ������" by Calvin
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
string avenge();
void create()
{
       set_name(HIM"������"NOR, ({"a buji", "a", "buji","abuji","master","tianshen"}));
       set("long", "����ĸ������ʦ��,����ת��Ϊ��������\n");
       set("title", HIM"��Ӱʥ��"NOR);
       set("gender", "����");
       set("age", 100);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/respect", "ʥ��");
       set("cor", 30);
       set("per", 40);
      set("looking", "����Ʈ��,����ʵ��,��������,һ���˲š�");
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
       set_skill("sword", 350);
       set_skill("blade", 350);
       set_skill("xuanhu-blade", 350);
       set_skill("spells", 350);
      set_skill("moonshentong", 350);
       set_skill("baihua-zhang", 350);
     set_skill("moonforce", 350);
      set_skill("snowsword", 350);
      set_skill("moondance", 350);
  set_skill("whip", 350);
  set_skill("jueqingbian", 350);
   map_skill("spells", "moonshentong");
   map_skill("unarmed", "baihua-zhang");
   map_skill("force", "moonforce");
   map_skill("sword", "snowsword");
   map_skill("parry", "snowsword");
   map_skill("dodge", "moondance");
   set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "mihun" :),
                (: cast_spell, "arrow" :)
        }) );
create_family("�¹�", 1, "��");
setup();

        carry_object("/d/9ct/zb/wan")->wear();
//        carry_object("/d/obj/weapon/sword/qinghong")->wield();
}

void attempt_apprentice(object ob)
{
   if ( (string)ob->query("family/family_name")=="�¹�") {
   if (((int)ob->query("combat_exp") < 2000000 )) {
   command("say " + RANK_D->query_respect(ob) +
"�ĵ��в��������Щ��ѧ�ط�������������\n");
   return;
   }
     command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ�����������¹�������\n");
       command("recruit " + ob->query("id") );
        ob->set("title", HIG"�¹���Ӱ����"NOR);
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"������ȥѧЩ��������ɡ�\n");
        return;
}

