#include <ansi.h>
inherit F_VENDOR_SALE;
int ask_niang (); 

void create()
{
        set_name("�ƹ�", ({ "jiu gui" }) );
        set("gender", "����" );
        set("age", 25+random(20));
        set("long", "�㿴��һλ���������������Ժ����ľƹ�\n");
        set("combat_exp", 150+random(800));
        set("attitude", "friendly");
        set("env/wimpy", 60);
        set("chat_chance_combat", 50 );
        set("chat_msg_combat", ({
                "�ƹ�е���ɱ���ģ�ɱ���ģ�\n",
                "�ƹ�е����������ģ����컯���´���ģ�\n",
                (: command, "surrender" :),
        }) );
        set("inquiry", ([ 
            "�ٻ���" : (: ask_niang :), 
           ]) ); 

        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}

int ask_niang () 
{ 
         object obj,jiuyin,jiupai,hulu;
         object me=this_object();
         object who=this_player();
         jiuyin=present("jiu yin",who);
         jiupai=present("jiu pai",who);
         if (who->query("level")<20){
               command("say "+RANK_D->query_respect(who)+"���ļ���Ŭ��ѽ������ȼ����������ɡ� \n"); 
           return 1;}
        if(!userp(who)){
                command("say ����˭ѽ���Һ�����ʶ�㡣 \n");  
                return 1;
        }
         if ( !present("jiu yin",who)||!present("jiu pai",who) ) { 
               command("say ����ʲôѽ���Ҳ�֪��ม� \n"); 
               command("zzz");
               return 1;} 
         if(! who->query("quest/pending/ask/done")){
               command("say ������ٳ¹������ҵĺ����ѣ������ɣ���ȥ�������һ��������������Ҫ��������ɺ�ֱ������ร���Ҫ���ʹ����ͣ���Ȼ�����㡣 \n"); 
               command("hoho");
               return 1;} 
         if ( !who->query_temp("rent_paid")){
               command("hmm");     
               command("say �����ͷ�е����������....��֪���˰ɣ� \n"); 
               return 1;} 
          obj=new("/d/quest/wine/obj/baihuaniang");
          obj->move(who);
          who->delete("wine/start");
          who->delete("quest/pending/ask/done");
          who->delete_temp("rent_paid");
          who->delete("wine/mijiu");
          who->delete("wine/gaoliang");
          who->delete("wine/huangjiu");
          destruct(jiuyin);
          destruct(jiupai);
          message_vision("$N����$nһƿ"+obj->query("name")+"��\n", me,who);
          command("gongxi "+who->query("id"));
        message( "chat", HIC"��"+HIB"����ĸ"+HIC"���� ��ϲ��ϲ��"+who->query("name")+"������"+obj->query("name")+"�������ؽ���\n" NOR, users() );
        who->add("balance",500002+random(4500000));
            who->add("morality",1);
            who->add("daoxing",20000+random(80000));
        who->set("wine/done",1);
        log_file("winetask","["+ctime(time())+"] "+sprintf("%s(%s)����ĸ���������˰ٻ��𣬵õ��˽�����\n", who->query("name"),who->query("id")));  
            who->save();
            return 1; 
} 

int accept_object(object who, object ob)
{
        int value;
        if (ob->query("money_id") && (value=ob->value()) >= 300000 && present("jiu yin",who)) 
        {
            tell_object(who, name()+"һ������˵������л�ˣ����һ���������͸�������\n");
            who->set_temp("rent_paid",1);
            take_money(value, 300000);
                return 1;
        }
        return 0;
}
