// fairygirl.c
// 1996/10/31 by none...modified:)

inherit NPC;

#include <ansi.h>

int send_back(object me);
string ask_shuizhu();
string ask_qingsuojian();

void create()
{
        set_name("�����ɹ�", ({ "fairy girl", "fairy", "girl" }) );
        set("gender", "Ů��" );
        set("age", 18);
        set("long",
                "�������Σ���÷��ѩ��������Σ�������˪��
�侲���Σ������չȡ��������Σ�ϼӳ������
�������Σ��������ӡ��������Σ����亮����\n");
        set("combat_exp", 200000);
        set("attitude", "friendly");
        set("inquiry", ([
                "name" : "̫��þ������ɹ���Ҳ��",
                "here" : "�����֮�ϣ���֮�С�",
                "̫��þ�" : "̫�����飬�þ����ľ�",
                "��" : "ׯ���ε���������ׯ������",
                "����" : "ׯ���ε���������ׯ������",
                "��" : "ľͷ��ľͷ����������δ�ѣ�������˽��Ρ�",
                "����" : "ľͷ��ľͷ����������δ�ѣ�������˽��Ρ�",
                "��ȥ" : (: send_back :),
                "back" : (: send_back :),
                "ˮ����" : (: ask_shuizhu :),
                "������" : (: ask_qingsuojian :),
        ]) );
        set_skill("literate", 100);
        set_skill("dodge", 100);
        setup();
        carry_object("/d/obj/cloth/skirt")->wear();
        carry_object("/d/obj/cloth/shoes")->wear();
}

int send_back(object me)
{
        me=this_player();
        command("sigh " + me->query("id"));
        command("say " + "����һ��ľͷ...�ã������ȥ�ɡ�\n");
        tell_object(me,"\n�����ɹ����泤�䣬������ǰһ��...\n\n�������۾������˹�����\n\n");
        if(!me->query("dream_place")) me->move("/d/changan/pinqiting");
        else me->move((string)me->query("dream_place"));
        return 1;
}

string ask_shuizhu()
{
        object who,me,room;
        
        who = this_player();
        me = this_object();
        command("sigh " + who->query("id"));
        command("say " + "��������ң����Ϊ����置�󺵣�Ҳ��Ѱˮ���顣\n");
        command("say " + "���ȴ...����Ҳ�գ���������һ�̡�\n");
        if(!( room = find_object("/d/ourhome/honglou/dreamland/dreamland")) )
            room = load_object("/d/ourhome/honglou/dreamland/dreamland");
        if(objectp(room))
            who->move(room);
        return "\n�����ɹ����泤�䣬������ǰһ��...\n\n�������۾������˹�����\n\n";
}

string ask_qingsuojian()
{
           object who,me,room;
 
           who = this_player();
           me = this_object();
           command("look " + who->query("id"));
           if(random(5)>2)
           {
               command("say " + "�������µĴ����ܣ���ϵ����а��������\n�㻹�ǲ�Ҫ���˰ɡ�\n");
               command("pat " + who->query("id"));
               return "\n�㻹��ȥ�ɡ�\n";
           }
           command("say " + "�˽����Ƕ��ҳ�ü���˵�����ħ֮�á�\n");
           command("say " + "�Դӳ�ü���˷������ɺ󣬴˽��������伣�ˡ�\n��Ҳ������������ڣ���������ĸ���и��Ҳ���������������\n");
           who->set_temp("qingsuojian",1);
           return "��������ĸ�������ˣ��㻹����Ϊ����Щ���飬\n������ʲô����Ϳ����Լ�ȥ���ˡ�\n";
}
