//ϲ��
//��ԯ��Ĺ

//ximei.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_for_leave();


void create()
{
              set_name(HIW"ϲ��" NOR, ({"xi mei", "ximei", "mei"}));
       set("long", "
һֻ������������������а�����Ϊ��槼��ǳ�
ϲ����������������֮�����������Ⱥò�����
�����ڳ���¹̨֮����������槼�����������֮
ʱ��ʤ��������¶ԭ�α���̫ʦ���ٵĽ��֮��
���ڷ���̨��槼�������������\n");
       set("title", HIB"������" NOR);
       set("gender", "Ů��");
       set("age", 20);
       set("class", "yaomo");
       set("attitude", "friendly");
       set("per", 40);
        set("int", 40);
       set("max_kee", 900);
       set("max_gin", 600);
       set("max_sen", 800);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 50);
       set("max_mana", 600);
       set("mana", 600);
       set("mana_factor", 40);
       set("combat_exp", 400000);
  set("daoxing", 800000);


        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 220);
       set_skill("unarmed", 220);
       set_skill("dodge", 220);
       set_skill("force", 220);
       set_skill("parry", 220);
       set_skill("blade", 220);
       set_skill("spells", 80);
        set_skill("youming-spells", 220);
        set_skill("jiuyin-zhua", 220);
        set_skill("jiuyin-force", 220);
        set_skill("zizhi-blade", 220);
        set_skill("kongming-steps", 200);
        map_skill("spells", "youming-spells");
        map_skill("unarmed", "jiuyin-zhua");
        map_skill("force", "jiuyin-force");
        map_skill("blade", "zizhi-blade");
        map_skill("parry", "zizhi-blade");
        map_skill("dodge", "kongming-steps");


        set("inquiry", ([
                "����" : (: ask_for_leave :),
                "leave" : (: ask_for_leave :),
                ]) );

create_family("��ԯ��Ĺ", 2, "����");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/d/moon/obj/feijian")->wield();
}

void attempt_apprentice(object ob)
{
        

        command("kiss "+ob->query("id"));
        command("say ��������Ҫ���Ŭ��Ŷ��Ҫ��ȻС��槼���������Ӵ��\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "yaomo");
}

void init()
{
        add_action("do_agree", "agree");
}

string ask_for_leave()
{
        object me=this_player();

        if (me->query("family/family_name") == "��ԯ��Ĺ" ) {
                command("say �������ͽ����ȻҪ����ʦ�ţ�");
                me->set_temp("m_betray", 2);
                return ("����ʦ��Ҫ�ϳ�����书�����Ը��(agree)��");
        }

        return ("��檲�֪��\n");
}

int do_agree(string arg)
{
        if(this_player()->query_temp("m_betray") > 1 ) {
                message_vision("$N���������Ը�⡣\n\n", this_player());
                command("say ����������ԯ��Ĺ��Ե�������ɽȥ�ɣ�");
                this_player()->add("betray/count", 1);
                this_player()->add("betray/moon", 1);
       this_player()->set("combat_exp", this_player()->query("combat_exp")/100*80);
   this_player()->set("daoxing", this_player()->query("daoxing")/100*80);
                if( this_player()->query_skill("youming-spells") )
                    this_player()->delete_skill("youming-spells");
                if( this_player()->query_skill("shengling-sword") )
                    this_player()->delete_skill("shengling-sword");
                if( this_player()->query_skill("jiuyin-force") )
                    this_player()->delete_skill("jiuyin-force");

                
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "��ͨ����");
                this_player()->delete_temp("betray");
                this_player()->save();
                command("say �����粨���ƶ����Σ�����Ϊ֮������\n");
                return 1;
        }
}



