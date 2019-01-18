//Ԫʼ����
//����NPC

inherit NPC;
#include <ansi.h>
#include "teamjob.c"

string ask_newjob();
string ask_newover();
void create()
{
       set_name(HIY"Ԫʼ����"NOR, ({"yuanshi tianzun","tianzun", "master"}));
       set("long", "���ǲ��̽�������������״����������֮һ,�䷨���ޱߣ�������֮�����ž������صĵ�λ��\n");
       set("title", HIW"����֮��"NOR);
       set("gender", "����");
       set("age", 100);
       set("class", "xian");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("family/family_name", "��ׯ��");
       set("per", 40);
       set("int", 60);
       set("max_kee", 10000);
       set("max_gin", 10000);
       set("max_sen", 10000);
       set("force", 60000);
       set("max_force", 60000);
       set("force_factor", 750);
       set("max_mana", 10000);
       set("mana", 10000);
       set("mana_factor", 750);
       set("combat_exp", 30000000);
       set("daoxing", 200000000);

        set_skill("spells",1000);
        set_skill("force", 1000);
        set_skill("dodge", 1000);
        set_skill("parry", 1000);
        set_skill("sword", 1000);
        set_skill("wuxiangforce", 1000);
        set_skill("jindouyun", 1000);
        set_skill("wuxing-quan", 1000);
        set_skill("sanqing-jian", 1000);
        set_skill("literate", 1000);
        set_skill("unarmed", 1000);
        set_skill("dao", 300);
        map_skill("spells", "dao");
        map_skill("dodge", "jindouyun");
        map_skill("force", "wuxiangforce");
        map_skill("parry", "sanqing-jian");
        map_skill("sword", "sanqing-jian");
        map_skill("unarmed", "wuxing-quan");

        set("chat_chance_combat", 30);  
        set("chat_msg_combat", ({ 
           (: cast_spell, "light" :), 
           (: cast_spell, "thunder" :), 
           (: cast_spell, "dingshen" :) 
           })); 
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "Ԫʼ����̾�˿��������������ħΪ����Ⱥħ�Ż�����������λ����Ը��ͦ����������������أ�\n",
        
        }));
        set("inquiry", ([
                "��������" : "��������������֮�ף��Ҹ�Ը���׳Ƴ���\n",
                "�������" : "�������ʦ�����������ڿɺã�\n",
                "̫���Ͼ�" : "��ʦ��Ǳ���޵���������������\n",
                "ͨ�����" : "���������ʦ�ܣ��ֲ�֪�����������ʲô��ı��ơ�\n",
//                "����"  : (: ask_gongde :),
                "ħ������"  : (: ask_jianxi :),
                "thief" : (: ask_jianxi :),
                "�ػ��칬" : (: ask_newjob :),
                "job"  : (: ask_newjob :),
                "����"  : (: ask_newover :),

                ]));


        setup();

        carry_object("/d/lingtai/obj/shoe")->wear();
        carry_object("/d/zhuxian/obj/wuchen")->wield();
}


void init()
{
        add_action("job_over","task");
}

string ask_newjob()
{
        object *ene;
        object me = this_player();

        if(is_fighting()) 
        {
                ene=query_enemy();
                
                if(sizeof(ene)>1) 
                        return "����"+RANK_D->query_respect(me)+"�Ե�Ƭ�̣����Ⱥ���"+sizeof(ene)+"λ�����д輸�£���\n";

                if(sizeof(ene)==1) 
                        return "����"+RANK_D->query_respect(me)+"�Ե�Ƭ�̣����Ⱥ�"+ene[0]->name()+"�д輸�£���\n";
        }

        if(me->query_temp("mark/job_shadi")>0 ) 
                return "��"+RANK_D->query_respect(me)+"���������������𣡡�\n";

        if ((int)me->query("combat_exp")<2000000) 
                return "��"+RANK_D->query_respect(me)+"������ǳ�����Ǳ��������Ϊ�ã���\n";

        if ( (int)me->query_skill("force",1) < 200 )
                return "�ػ��칬�Ǽ�Σ�չ������ҿ�"+RANK_D->query_respect(me)+"�Ĺ������⣡\n";

        if ((int)me->query_condition("jobshadi_failed"))
        {
                message_vision("$N����$nҡ��ҡͷ˵������ʧ���˻������ң�\n", this_object(), me);
                return "��"+RANK_D->query_respect(me)+"�㻹�Ǳ��������Ϊ�ã���\n";
        }

        if ((int)me->query_condition("jobshadi_limit")>1)
        {
                message_vision("$N����$nҡ��ҡͷ˵���㲻����������\n", this_object(), me);
                return "��"+RANK_D->query_respect(me)+"�����ȥ������������\n";
        }
     
        if ((int)me->query_condition("guojob2_busy"))
        {
                message_vision("$N����$nҡ��ҡͷ˵������Ⱥħ���ڹ����칬����\n", this_object(), me);
                return "��"+RANK_D->query_respect(me)+"��Ȼ���������\n"; 
        }

        message("channel:chat", HIW"���칬������"HIR + "��·Ⱥħ����Ҫ�����칬�ˣ�����\n"NOR,users() );
        
        switch( random(4) ) {
                case 0:
                        me->set_temp("mark/job_shadi",1);
                        me->set_temp("carry_location","eastgate");            
                      me->apply_condition("guojob2_busy",5);
                      me->start_busy(5+random(3));
                        return "������Ⱥħ�ַ��칬����λ"+RANK_D->query_respect(me)+"��ȥ�����Ű�������콫�ػ��칬�ɡ�";

                       break;
                case 1:
                        me->set_temp("mark/job_shadi",2);
                        me->set_temp("carry_location","southgate");            
                      me->apply_condition("guojob2_busy",5);
                      me->start_busy(5+random(3));
                        return "������Ⱥħ�ַ��칬����λ"+RANK_D->query_respect(me)+"��ȥ�����Ű�������콫�ػ��칬�ɡ�";

                       break;
                        
                case 2:
                        me->set_temp("mark/job_shadi",3);
                        me->set_temp("carry_location","westgate");
                      me->apply_condition("guojob2_busy",5);
                      me->start_busy(5+random(3));
                        return "������Ⱥħ�ַ��칬����λ"+RANK_D->query_respect(me)+"��ȥ�����Ű�������콫�ػ��칬�ɡ�";

                       break;
                case 3:
                        me->set_temp("mark/job_shadi",4);
                        me->set_temp("carry_location","northgate");
                      me->apply_condition("guojob2_busy",5);
                      me->start_busy(5+random(3));
                        return "������Ⱥħ�ַ��칬����λ"+RANK_D->query_respect(me)+"��ȥ�����Ű�������콫�ػ��칬�ɡ�";

                       break;
                
        }
}


int job_over(string arg)
{
        int job_pot,job_exp,job_dx;
        object me = this_player();
        object badguy;
        object room;

        if(!arg) return 1;

        if(arg!="over") return 1;
        if(me->query_temp("help_killed")>0)
        {
                message_vision(CYN "$N����$nЦ������"+RANK_D->query_respect(me)+"��Ϊ��ͥЧ����ǰ;����������\n" NOR, this_object(), me);
                job_exp=((int)me->query_temp("killed_mgb"))*80;
                job_pot=job_exp/3;
                job_dx=job_exp + random(1000) - random(1000);
                job_exp=job_exp;
                me->add("combat_exp", job_exp);
                me->add("potential",job_pot);
                me->add("daoxing",job_dx);
                tell_object(me, "�㱻������"+chinese_number(job_exp)+"����ѧ��"+chinese_daoxing(job_dx)+"�ĵ��У�"+chinese_number(job_pot)+"��Ǳ�ܣ�\n");
                me->delete_temp("killed_mgb");        
                me->delete_temp("job_over");
                me->delete_temp("mark/job_shadi");
                me->delete_temp("help_killed");
                me->start_busy(2);
                me->apply_condition("guojob2_busy",6);
                return 1;
        }
                
        if(me->query_temp("mark/job_shadi")==0)
        {
                message_vision(CYN"$N����$nһ��:����û��ȥ����������������\n",this_object(),me);
                return 1;
        }
        
        if(me->query_temp("job_over")==0)
        {
                message_vision(CYN"$N����$nһ��:������δ�����⡣��\n"NOR,this_object(),me);
                return 1;
        }

        if(me->query_temp("killed_mgb")<2)
        {
                message_vision(CYN"$N����$nһ��:��������ո�ɱ�˼�����ħ����ô����Ϊ�������ͣ�����\n"NOR,this_object(),me);
                me->delete_temp("job_over");
                me->delete_temp("mark/job_shadi");
                return 1;
          }

        message_vision(CYN "$N��$n˵������"+RANK_D->query_respect(me)+"�����ˣ�ȥ��Ϣһ�°ɣ���\n" NOR, this_object(), me);
        me->delete_temp("job_over");
        me->delete_temp("mark/job_shadi");
        job_exp=((int)me->query_temp("killed_mgb"))*80;
        job_pot=job_exp/3;
        job_dx=job_exp + random(1000) - random(1000);
        job_exp=job_exp;
        if (job_exp >3000) job_exp=3000;
        if (job_pot >500) job_pot=500;
        tell_object(me, "�㱻������"+chinese_number(job_exp)+"�㾭��ֵ��"+chinese_daoxing(job_dx)+"�ĵ��У�"+chinese_number(job_pot)+"��Ǳ�ܣ�\n");
        me->apply_condition("guojob2_busy",6);
        me->add("combat_exp", job_exp);
        me->add("potential",job_pot);
        me->add("daoxing",job_dx);
        me->delete_temp("killed_mgb");        
        me->start_busy(2);
        if (random(4) == 0)
        {
                message("channel:chat", HIW"����ͥս����"HIR + "��λ����콫�������ˣ��Ѿ��˵�����Ӹ�����\n"NOR,users() );
                if(objectp(room=load_object("/d/dntg/sky/dadao1")) && 
                objectp(badguy = new("/d/quest/teamjob/npc/tianbing")))
                badguy->move(room);
                room=load_object("/d/dntg/sky/dadao2");
                badguy = new("/d/quest/teamjob/npc/tianbing");
                badguy->move(room);
                room=load_object("/d/dntg/sky/dadao3");
                badguy = new("/d/quest/teamjob/npc/tianbing");
                badguy->move(room);
        }
        if (random(4) == 1)
        {
                message("channel:chat", HIW"����ͥս����"HIR + "������ħ����˱����ţ�����ǰ��֧Ԯ��\n"NOR,users() );
                if(objectp(room=load_object("/d/dntg/sky/jiashan")) && 
                objectp(badguy = new("/d/quest/teamjob/npc/yaomo2")))
                room=load_object("/d/dntg/sky/jiashan");
                badguy = new("/d/quest/teamjob/npc/yaomo3");
                badguy->move(room);
                room=load_object("/d/dntg/sky/yunlun1");
                badguy = new("/d/quest/teamjob/npc/yaomo3");
                badguy->move(room);
                room=load_object("/d/dntg/sky/yunlun2");
                badguy = new("/d/quest/teamjob/npc/yaomo2");
                badguy->move(room);
                room=load_object("/d/dntg/sky/yunlun3");
                badguy = new("/d/quest/teamjob/npc/yaomo2");
                badguy->move(room);
        }
        if (random(4) == 2)
        {
                message("channel:chat", HIW"����ͥս����"HIR + "һ�����������������ţ�������֧Ԯ��\n"NOR,users() );
                if(objectp(room=load_object("/d/dntg/sky/yunluw4")) && 
                objectp(badguy = new("/d/quest/teamjob/npc/yaomo1")))
                badguy->move(room);
                room=load_object("/d/dntg/sky/yunluw3");
                badguy = new("/d/quest/teamjob/npc/yaomo1");
                badguy->move(room);
                room=load_object("/d/dntg/sky/yunluw2");
                badguy = new("/d/quest/teamjob/npc/yaomo1");
                badguy->move(room);
                room=load_object("/d/dntg/bmw/hgj4");
                badguy = new("/d/quest/teamjob/npc/yaomo1");
                badguy->move(room);
                room=load_object("/d/dntg/bmw/hgj3");
                badguy = new("/d/quest/teamjob/npc/yaomo1");
                badguy->move(room);
                
        }
        if (random(4) == 3)
        {
                message("channel:chat", HIR"����ͥս����"HIR + "�м���������ǿ��ħ�ֱ仯���Σ�����������ţ������˲ʺ��ţ�\n"NOR,users() );
                if(objectp(room=load_object("/d/dntg/sky/caihongqiao")) && 
                objectp(badguy = new("/d/quest/teamjob/npc/yaomo4")))
                badguy->move(room);
                room=load_object("/d/dntg/sky/caihongqiao");
                badguy = new("/d/quest/teamjob/npc/yaomo4");
                badguy->move(room);
        }

        return 1;

}

string ask_newover()
{
         object me;
         me = this_player();
         if(me->query_condition("jobshadi_limit")<=1)
                 return "��û��������������Ҫ�����ĳ�����";
         me->clear_condition("jobshadi_limit");
         me->add("combat_exp",-300+random(50));
         me->apply_condition("jobshadi_failed",10);
         me->delete_temp("mark/job_shadi");
         me->delete_temp("carry_location");
         me->delete_temp("job_over");
         me->delete_temp("start_job");
         return "��ֲ�и������������ϣ�����´μ���Ŭ�� ��";
}

int accept_fight(object me, object ob)
{       ob=this_player();
        command("say " + RANK_D->query_rude(ob) + "ɱ��̫�أ��ֻ������ѣ�\n");
        return 0;
}
void die()
{

        if( environment() ) {
        message("sound", "\n\nԪʼ����΢��üͷ��������һ���ô������Ҳ�գ�����\n\n", environment());
        command("sigh");
        message("sound", "\nԪʼ��������һת������һ������������ա�����\n\n", environment());
        }

        destruct(this_object());
}

