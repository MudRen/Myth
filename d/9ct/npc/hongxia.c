// �������� "����ư�� ��ϼ" by Calvin

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
       set_name(HIR"��ϼ"NOR, ({"hong xia", "xia", "hongxia","master","hong","tianshen"}));
       set("long", "�ഫ��ϼ������˿����ʦ����˫ϼ��ʦ��
����Ϊ����λͽ��һֱ�Ķ�Ż����, ���
��������簲��, ��������λ���ӱ�����
�������,����ϼҲ�������������졣

\n");
       set("title", HIR"����ư��"NOR);
       set("gender", "Ů��");
       set("age", 20);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/respect", "����");
       set("cor", 30);
       set("per", 40);
       set("max_kee", 6000);
       set("max_gin", 800);
       set("max_sen", 6000);
       set("force", 5000);
       set("max_force", 3000);
       set("force_factor", 125);
       set("max_mana", 2500);
       set("mana", 5000);
       set("mana_factor", 250);
       set("combat_exp", 5000000);
           set("daoxing", 5000000);

       set_skill("literate", 350);
       set_skill("unarmed", 350);
       set_skill("dodge", 350);
       set_skill("force", 350);
       set_skill("parry", 350);
       set_skill("sword", 350);
       set_skill("spells", 350);
       set_skill("whip", 350);
   set_skill("pansi-dafa", 350);
   set_skill("lanhua-shou", 350);
   set_skill("jiuyin-xinjing", 350);
   set_skill("chixin-jian", 350);
   set_skill("qin", 350);
   set_skill("yueying-wubu", 350);
   set_skill("yinsuo-jinling", 350);
   map_skill("spells", "pansi-dafa");
   map_skill("unarmed", "lanhua-shou");
   map_skill("force", "jiuyin-xinjing");
   map_skill("sword", "chixin-jian");
   map_skill("parry", "yinsuo-jinling");
   map_skill("dodge", "yueying-wubu");
   map_skill("whip", "yinsuo-jinling");
        set("chat_msg_combat", ({
                (: cast_spell, "wuzhishan" :),
                (: cast_spell, "ziqi" :)
        }) );
create_family("��˿��", 1, "��");
setup();

        carry_object("/d/9ct/zb/xue")->wear();
        carry_object("/d/9ct/zb/zhaoxia")->wield();
}

void attempt_apprentice(object ob)
{
  if ( (string)ob->query("family/family_name")=="��˿��") {
   if (((int)ob->query("combat_exp") < 2000000 )) {
   command("say " + RANK_D->query_respect(ob) +
"�����в������ף�����ѧϰ�����������ѡ�\n");
   return;
   }
        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ��������ϧ��һ��,Ī��������˫ϼ�������Ķ��ǡ�\n");
       command("recruit " + ob->query("id") );
           ob->set("title", HIM"����ɽ��˿С��"NOR);
           ob->set("class", "xian");
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"������ȥѧЩ��������ɡ�\n");
        return;
}

