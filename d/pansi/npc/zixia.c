
//zixiaxianzi.c 2001 by lestat
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_love();
void create()
{
       set_name(HIM"��ϼ����"NOR, ({"zixia xianzi", "zixia", "xianzi","master"}));
       set("long", "��������˿���Ŀ�ɽ��ʦ,��˵���Ƿ����һ�õ�о��������޵���
��,����˼���½�ռ�˻���ɽһ������,��ɽ����,������ͽ��\n");
       set("title", HIB"��˿����"NOR);
       set("gender", "Ů��");
       set("age", 20);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/respect", "С����");
       set("cor", 30);
       set("per", 40);
       set("max_kee", 4500);
       set("max_gin", 800);
       set("max_sen", 4500);
       set("force", 5000);
       set("max_force", 3000);
       set("force_factor", 125);
       set("max_mana", 2500);
       set("mana", 5000);
       set("mana_factor", 250);
       set("combat_exp", 3000000);
	   set("daoxing", 4000000);
       set_skill("literate", 200);
       set_skill("unarmed", 220);
       set_skill("dodge", 220);
       set_skill("force", 220);
       set_skill("parry", 220);
       set_skill("sword", 220);
       set_skill("spells", 220);
       set_skill("whip", 220);
   set_skill("pansi-dafa", 220);
   set_skill("lanhua-shou", 180);
   set_skill("jiuyin-xinjing", 220);
   set_skill("chixin-jian", 180);
   set_skill("qin", 220);
   set_skill("yueying-wubu", 180);
   set_skill("yinsuo-jinling", 200);
   map_skill("spells", "pansi-dafa");
   map_skill("unarmed", "lanhua-shou");
   map_skill("force", "jiuyin-xinjing");
   map_skill("sword", "chixin-jian");
   map_skill("parry", "yinsuo-jinling");
   map_skill("dodge", "yueying-wubu");
   map_skill("whip", "yinsuo-jinling");
   set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "wuzhishan" :),
                (: cast_spell, "ziqi" :)
        }) );
   set("inquiry", ([
          "����" : (: ask_love :),
]));
create_family("��˿��", 1, "��");
setup();

        carry_object("/d/obj/cloth/tianyi.c")->wear();
        carry_object("/d/pansi/obj/ziqing.c")->wield();
        carry_object("/d/ourhome/obj/shoes")->wear();
}

void attempt_apprentice(object ob)
{

   if ( (string)ob->query("family/family_name")=="��˿��") {
   if (((int)ob->query("combat_exp") < 1000000 )) {
   command("say " + RANK_D->query_respect(ob) +
"�ĵ��в��������Щ��ѧ�ط�������������\n");
   return;
   }
        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ�������հ���ɱ���Ǹ������ӡ�\n");
       command("recruit " + ob->query("id") );
           ob->set("title", HIY"����ɽ��˿���ɻ���"NOR);
	   ob->set("class", "xian");
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"������ȥѧЩ��������ɡ�\n");
        return;
}
int accept_fight(object me)
{
   return 0;
}

int ask_love()
{
        object ob=this_player();
        if(ob->query("family/family_name") != "��˿��")
        {
        command("say ���ֲ�����˿���ģ�ѧ����ʲô?");
        return 1;
        }
        if(ob->query("family/master_name")!= this_object()->query("name"))
        {
        command("say ���ֲ����ҵ�ͽ�ܣ�˭���㣡");
        return 1;
        }
        if(!ob->query("pansi/love_master"))
        {
        ob->set("pansi/love_master",1);
        command("say ��һ�а�����Ϊʦ������������Ӧ�ÿ��԰��㱣���ģ�");
        ob->set("pansi/ask_zixia_go", 1);
        return 1;
	} else
	{
        command("say ��һ�а����Ҳ����Ѿ�����������?");
        return 1;
	}
}
