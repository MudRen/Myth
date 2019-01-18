//����ʦ,��ũ��

#include <ansi.h>
inherit NPC;

int ask_ge();
int ask_la();
int ask_long();
int ask_sex();

void create()
{
        set_name(HIW"��ũ��"NOR,({"shennong shi","meirong shi","shi"}));
        set("title",HIR"�׵�"NOR);
        set("nickname",HIC"���ٲݣ�������"NOR);
        set("long",
                "\n������������µ���ũ�ϣ�ֻ�����׷�ͯ�գ������󣬵�ȴ��˶�ޱȡ�\n"
                "�������������񻰵�����ʦ,ר�Ÿ������ò���ѵ���ҽ������ݷ���\n"
                "���ݿ��Ǹ�����Ŷ,��˵��˫��ƤҪ1000gold����Ƥ3000gold��¡��5000gold��\n"
                "���ڱ�����,���ڳ�ǰ����,һ�ڼ�10000gold��\n");
        set("gender","����");
        set("age",180);
        set("per",40);
        set("str",30);
        set("int",40);
        set("attitude", "friendly");    
        set("max_kee",50000);
        set("kee",50000);
        set("max_sen",50000);
        set("sen",50000);
        set("max_force",80000);
        set("force",80000);
        set("max_mana",80000);
        set("mana",80000);
        set("combat_exp",100000000);
        set("daoxing",100000000);
        set("force_factor", 500);
        set("mana_factor", 500);

        set_skill("blade",500);
        set_skill("dodge",500);
        set_skill("parry",500);
        set_skill("unarmed",500);
        set_skill("dragonfight",500);
        set_skill("kugu-blade",500);

        map_skill("dodge","kugu-blade");
        map_skill("parry","kugu-blade");
        map_skill("blade","kugu-blade");
        map_skill("unarmed","dragonfight");

        set("inquiry", ([
                "��˫��Ƥ":(: ask_ge :),
                "¡��":(: ask_long :),
                "��Ƥ":(: ask_la :),
                "����":(: ask_sex :),
        ]) );

        set("chat_chance_combat", 80);

        set("chat_msg_combat", ({
                "\n��ũ��ҡͷ̾�����۵��������������������������Ǻο��أ�\n",
                (: command("smile") :),
                (: command("haha") :),
                (: command("chat ��λ" + RANK_D->query_respect(this_player())+",������ԩ�޳𣬺α���ˣ�\n") :),         
                (: perform_action, "blade", "diyu" :),
                (: exert_function, "recover" :),                          
        }) );
        setup();

        carry_object("/d/city/obj/dao")->wield();
        carry_object("/d/city/obj/dagua")->wear();
}

int ask_ge()
{
        object me = this_player();
         
        if (me->query("beauty_ge")=="done"){
//      command("hit"+ me->query("id"));
        tell_object(me,"���Ѿ����˫��Ƥ�ˣ���Ҫ��ѵ�����������Ƥ�� \n");
        return 1;
        }
        if (me->query("per")>=25){
        command("shake " + me->query("id"));
        tell_object(me,"�㱾������˫��Ƥ������ʲô�� \n");
        return 1;
        }
        if (me->query("balance")<10000000){
//         command("slap " + me->query("id"));
         tell_object(me,"��⵰�������Բ������������ݣ� \n");
         return 1;
         }
        else {
                me->set("beauty_ge","done");
                me->add("per",1);
                me->save();
                me->add("balance",-10000000);
                command("ok " + me->query("id"));
                message("channel:chat",HIY+"����ũ�ϡ�����˵ "+me->query("name")+" ����ũ���ݸ���˫��Ƥ��\n"+NOR,users());
                me->unconcious();
                
                return 1;
        }       
        return 1;
}

int ask_long()
{
        object me = this_player();
        
        if (me->query("gender")!="Ů��"){
//      command("slap " + me->query("id"));
        tell_object(me,"���̬ѽ���еĻ���¡�أ�������\n");
        message("channel:chat",HIY+"����ũ�ϡ���"+me->query("name")+" �����������̬�����˾�Ȼ�ܵ���ũ��������¡�أ�\n"+NOR,users());
        return 1;
        }        
        if (me->query("beauty_long")=="done"){
//      command("hammer " + me->query("id"));
        tell_object(me,"����ز���¡�ĺ�����һ�����ˣ���¡�� \n");
        return 1;
        }
        if (me->query("per")>=25){
        command("heihei " );
        tell_object(me,"����ز��Ѿ���С�ˣ� \n");
        return 1;
        }
        if (me->query("balance")<50000000){
  //      command("slap " + me->query("id"));
        tell_object(me,"��⵰�������Բ���������¡�أ� \n");
        return 1;
        }
        else {
                me->set("beauty_long","done");
                me->add("per",3);
                me->save();
                me->add("balance",-50000000);
                command("ok " + me->query("id"));
                message("channel:chat",HIY+"����ũ�ϡ�����˵ "+me->query("name")+" ����ũ��������һ��¡����������Χ������XX�磡\n"+NOR,users()); 
                me->unconcious();

                return 1;
        }       
         return 1;
}

int ask_la()
{
        object me = this_player();
         
        if (me->query("beauty_la")=="done"){
//      command("sigh " + me->query("id"));
        tell_object(me,"������Ƥ�����岻�ã���ҪΪ�����ݶ��������壡 \n");
        return 1;
        }
        if (me->query("per")>=25){
//      command("pat " + me->query("id"));
        tell_object(me,"���Ƥ���ܺã��������ˣ�����������ɳƤ���ˣ�\n");
        return 1;
        }
        if (me->query("balance")<30000000){
  //       command("kick " + me->query("id"));
        tell_object(me,"��⵰�������Բ������������ݣ� \n");
        return 1;
         }
        else {
                me->set("beauty_la","done");
                me->add("per",2);
                me->save();
                me->add("balance",-30000000);
                command("nod " + me->query("id"));
                message("channel:chat",HIY+"����ũ�ϡ�����˵ "+me->query("name")+" ����ũ�������˸�Ƥ�����������ˣ�\n"+NOR,users());
                me->unconcious();
                
                return 1;
        }       
        return 1;
}

int ask_sex()
{
        object me = this_player();

        tell_object(me,HIG"��������˵���Ҹ���Ů�Ա���Υ������Ѿ����ҴӴ˽�ֹ�����ˣ� \n");
        return 1;

        
        
}    


/*
int ask_sex()
{
        object me = this_player();

        if (me->query("beauty_sex")=="done"){
//      command("sigh " + me->query("id"));
        tell_object(me,"�������ǲ�����ë��ѽ�������������������ѽ������Ҹ㣡 \n");
        return 1;
        }

        if (me->query("balance")<100000000){
  //       command("kick " + me->query("id"));
        tell_object(me,"��⵰�������Բ������������ԣ� \n");
        return 1;
         }
        else {
                me->set("beauty_sex","done");
                
                if(me->query("gender")=="Ů��") 
                        me->set( "gender", "����" );
                else me->set( "gender", "Ů��" );
                me->add("balance",-100000000);
//              me->add("per",-3);
                command("nod " + me->query("id"));
                message("channel:chat",HIY+"����ũ�ϡ�����˵ "+me->query("name")+" ����ũ�������˸�����������\n"+NOR,users());
                me->unconcious();
                
                return 1;
        }       
        return 1;
}    
*/

   

