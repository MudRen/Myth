//槼�
//��ԯ��Ĺ
 
//daji.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_mieyao();
string ask_cancel(); 
void create()
{
       set_name("槼�", ({"da ji", "daji", "ji"}));
       set("long", "Ů����� ������Ů ����槼�\n");
       set("title", HIB"��Ĺ�Ļ�" NOR);
       set("color", HIW);
       set("gender", "Ů��");
       set("age", 20);
       set("class","yaomo");
       set("attitude", "friendly");
       set("cor", 30);
       set("per", 40);
       set("max_kee", 4500);
       set("max_gin", 800);
       set("max_sen", 4500);
       set("force", 4000);
       set("max_force", 2000);
       set("force_factor", 125);
       set("max_mana", 2000);
       set("mana", 4000);
       set("mana_factor", 100);
       set("combat_exp", 2000000);
       set_skill("literate", 220);
       set_skill("unarmed", 220);
       set_skill("dodge", 220);
       set_skill("force", 220);
       set_skill("parry", 220);
       set_skill("sword", 220);
       set_skill("spells", 220);
   set_skill("youming-spells", 220);
   set_skill("jiuyin-zhua", 180);
   set_skill("jiuyin-force", 220);
   set_skill("qinghu-jian", 200);
   set_skill("kongming-steps", 150);
   map_skill("spells", "youming-spells");
   map_skill("unarmed", "jiuyin-zhua");
   map_skill("force", "jiuyin-force");
   map_skill("sword", "qinghu-jian");
   map_skill("parry", "qinghu-jian");
   map_skill("dodge", "kongming-steps");
   set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "mei" :),
                (: cast_spell, "huo" :)
        }) );
   set("inquiry", ([
                           "����": (: ask_mieyao :),
]));
create_family("��ԯ��Ĺ", 1, "��");
setup();

        carry_object("/d/obj/cloth/tianyi.c")->wear();
        carry_object("/d/obj/weapon/sword/qinghong.c")->wield();
        carry_object("/d/ourhome/obj/shoes")->wear();
}
void init()
{
add_action("do_kneel","kneel");
}

void attempt_apprentice(object ob)
{


   if ( (string)ob->query("family/family_name")=="��ԯ��Ĺ") {
   if (((int)ob->query("combat_exp") < 100000 )) {
   command("say " + RANK_D->query_respect(ob) +
"�ĵ��в��������Щ��ѧ�ط�������������\n");
   return;
   }
        command("nod "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ�����г�һ������ԯ��Ĺ�ư����磡\n");
       command("recruit " + ob->query("id") );
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"������ȥ��������ѧЩ��������ɡ�\n");
        return;
}
int accept_fight(object me)
{
   return 0;
}

// lost add
string ask_cancel() 
{
object me=this_player(); 
if((int)me->query("secmieyao")) 
{
me->add("daoxing",-2000); 
me->delete_temp("m_mieyao"); 
me->delete("secmieyao"); 
me->delete("secmieyao_mudage");  
me->set("m_mieyao",1); 
me->add("m_fangqi",1);
return ("û�õĶ�����"); 
}
else
{
return ("�Һ���û��������ʲôѽ����"); 
}
}
string ask_mieyao()
{
    object who=this_player();

    if((string)who->query("family/family_name")=="��ԯ��Ĺ") {
      command("smile "+who->query("id"));
      return "/d/obj/mieyao"->query_yao(who);
    }
    return ("��������,�ι�����?\n");
}
int do_kneel()
{
    object who = this_player();
    if((string)who->query("family/family_name")!="��ԯ��Ĺ")
     return notify_fail(this_object()->query("name")+"˵�����ֲ����ɼҵ��ӣ����Ҹ�ʲô��\n");
   if("/d/obj/mieyao"->delete_mieyao(who)){
        command("say ��Ȼ��ˣ������˰ɣ�������û��������񣬵���Щ�ͷ���\n");
        who->add("faith",-5);
        message_vision("$N���ҳ϶��½��ˣ�\n",who);
     }
}
string ask_hebi()
{
    object who=this_player();
    if((string)who->query("family/family_name")!="��ԯ��Ĺ")
        return ("�㲻�Ǳ��ɵ��ӣ���ô֪��������?");
    if(who->query("qinghu-jian")<300)
        return ("������������������������Ŭ�����С�");
    if(who->query("zizhi-blade")<300)
        return ("�������������������������Ŭ�����С�");
    who->set_temp("gumu_hebi",1);
        return ("�����perform hebi,Ҳ���Գ���perform ziqing hebi��");
}

