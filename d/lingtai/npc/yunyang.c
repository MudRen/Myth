// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//yunyang.c
inherit NPC;
inherit F_MASTER;
#include "/d/obj/lquest.h"
#include "/d/lingtai/npc/zhenfa.h"

string do_task();
string expell_me(object me);
string ask_mieyao(object me);
string ask_cancel();
void re_rank(object who);

void create()
{
        set_name("��������", ({"master yunyang", "master", "yunyang"}));
        set("long", "����������������ʦʵ�ǰ�ʦ���ѣ�Ҳ�����Ƕ������ܹܣ�
����׳��ʱ��ħ�����������˳ơ�С��ʦ����\n");
        set("faith",4000);
        set("gender", "����");
        set("title", "С��ʦ");
        set("class", "taoist");
        set("age", 70);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("rank_info/respect", "�ϵ���");
        set("per", 30);
        set("int", 30);
        set("str", 30);
        set("cps", 30);
        set("max_kee", 1100);
        set("max_gin", 1100);
        set("max_sen", 1100);
        set("force", 2300);
        set("max_force", 1200);
        set("force_factor", 80);
        set("max_mana", 1200);
        set("mana", 2300);
        set("mana_factor", 60);
        set("combat_exp", 800000);

        set("eff_dx", 250000);
        set("nkgain", 400);

        set_skill("literate", 90);
        set_skill("unarmed", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("stick", 120);
        set_skill("spells", 120);
        set_skill("dao", 120);
        set_skill("puti-zhi", 120);
        set_skill("wuxiangforce", 120);
        set_skill("force", 120);
        set_skill("qianjun-bang", 120);
        set_skill("jindouyun", 120);
        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
        map_skill("dodge", "jindouyun");
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "qiankun" :),
                (: perform_action, "leiting" :),
                (: cast_spell, "light" :),
                (: cast_spell, "dingshen" :),
                (: cast_spell, "thunder" :)
        }) );

        set("inquiry", ([
                "����": (: ask_mieyao :),
                "��ɽ": (: expell_me :),
                "leave": (: expell_me :),
                "task": (: do_task :),
                "������" : (: ask_sixiang :),
                "������" : (: ask_bagua :),
        ]) );

        create_family("����ɽ���Ƕ�", 1, "��");
        setup();

        carry_object("/d/lingtai/obj/bang")->wield();
}

string ask_cancel()
{
        object me=this_player();
        if(me->query("secmieyao"))
//        if((int)me->query_temp("m_mieyao"))
        {
                me->add("daoxing",-2000);
                me->delete("secmieyao_mudage"); 
                me->add("m_fangqi",1);
                me->delete_temp("m_mieyao");
                me->delete("secmieyao");
                me->delete("secmieyao/type");
                me->delete("secmieyao/location");
                me->delete("secmieyao/place");
                me->delete("secmieyao/name");
                me->delete("secmieyao/id");
                return ("û�õĶ�����");
        }
        else
        {
                return ("���������𣿣�");
        }
}

void attempt_apprentice(object ob)
{
        if ( (string)ob->query("family/family_name")=="����ɽ���Ƕ�") 
        {
                if (((int)ob->query("combat_exp") < 100000 )) 
                {
                        command("say ��������֮ʿ���صľ��ǵ��У�" + RANK_D->query_respect(ob) + "������Ŭ�����ǡ�\n");
                        return;
                }
                command("smile");
                command("say �ü����ü���ʱ����ħ��������ֺ��С���"  + RANK_D->query_respect(ob) +
"����������֮ʿȴ���ټ���\n");
                command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�\n");
                command("recruit " + ob->query("id") );
                return;
        }
        command("shake");
        command("say �Ϸ������ŵ��ӣ�" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
        return;
}

string expell_me(object me)
{    
        me=this_player();
        if((string)me->query("family/family_name")=="����ɽ���Ƕ�") 
        {
                command("say �����ִ����ɽ��Ϊʦȴ�м��仰˵��");
                me->set_temp("fc_betray", 2);
                command("say �ҷ���ɽҲ���������ɣ��������ڡ����й�����ɽ��ɽ�棡");
                return ("����Ҫ��ɽ��ȴ����ɽ��ͷ������������书���ϳ������Ը��(agree)?");
        }
        return ("ƶ����֪��");
}

void init()
{
        ::init();
//        re_rank(this_player());
        add_action("do_agree", "agree");
        add_action("do_fuming","fuming");
}

int do_agree(string arg)
{
        if(this_player()->query_temp("fc_betray") > 1 ) 
        {
                message_vision("$N���������Ը�⡣\n\n", this_player());
                this_player()->add("betray/count", 1);
                this_player()->add("betray/fangcun", 1);
                command("say �����ҷ���ɽ��ǳ�ݲ��������������ɽȥ�ɣ�");
                this_player()->add("combat_exp", -(this_player()->query("combat_exp")/20));
                this_player()->delete_skill("dao");
                this_player()->delete_skill("qianjun-bang");
                this_player()->delete_skill("jindouyun");
                this_player()->delete_skill("wuxiangforce");
                this_player()->delete_skill("puti-zhi");
                this_player()->delete_skill("liangyi-sword");

                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->delete_temp("fc_betray");
                this_player()->set("title", "��ͨ����");
                this_player()->set("faith",0);
                this_player()->save();
                command("say �����粨���ƶ����Σ�����Ϊ֮������\n");
                return 1;
        }
        return 0;
}

string ask_mieyao(object me)
{
        me=this_player();
        if((string)me->query("family/family_name")=="����ɽ���Ƕ�") 
        {
//        if(me->query("faith")<100)
//                return ("�㻹���ȶ������Ϊ�");
                tell_room(environment(me),"�������˾������е�ľ�ȣ���ʱһ����â�����\n");
                return "/d/obj/mieyao"->query_yao(me);
        }
        return ("ƶ����֪��");
}

string do_task()
{
        object me=this_player();
        
        if(me->query("family/family_name")!="����ɽ���Ƕ�")
                return ("�㲻�Ǳ��ŵ��ӣ�");
        if(me->query("combat_exp")<1100000)
                return ("��ľ��黹������");
        if(me->query("longquest/name"))
                return ("��������������");
       
        give_quest(me);
                return ("�����ȥ�ɣ�");   
}

int do_fuming()
{
        fuming(this_player());     
        return 1;
}
/*
void re_rank(object who)
{
        int faith=who->query("faith");
        if(who->query("class")!="taoist")return;
        if(faith<=100)
        {
                if(who->query("gender")=="Ů��")
                who->set("title","����ɽ���Ƕ�����");
                else who->set("title","����ɽ���Ƕ���ʿ");
                return;
        }
        else if(faith<=300)
                {
                who->set("title","����ɽ���Ƕ�С����");
                return;
                }
                else if(faith<=600)
                        {
                        who->set("title","����ɽ���Ƕ�����");
                        return;
                        }
                        else if(faith<=1000)
                                {
                                who->set("title","����ɽ���Ƕ�С��ʦ");
                                return;
                                }
                                else if(faith<=1800)
                                        {
                                        who->set("title","����ɽ���Ƕ���ʦ");
                                        return;
                                        }
                                        else if(faith<=3000)
                                                {
                                                who->set("title","����ɽ���Ƕ�����ʦ");
                                                return;
                                                }
                                                else if(faith<=6000)
                                                        {
                                                        who->set("title","����ɽ���Ƕ�����");
                                                        return;
                                                        }
                                                        else who->set("title","����ɽ���Ƕ�Ԫ��");
        return;
}

*/
