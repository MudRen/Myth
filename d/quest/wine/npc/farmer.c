inherit NPC;
int ask_jiu (); 

void create()
{
        set_name("ũ��", ({ "farmer" }) );
        set("gender", "����" );
        set("age", 25+random(20));
        set("long", "�㿴��һλ��ɫ��ڵ�ũ��\n");
        set("combat_exp", 150+random(800));
        set("attitude", "friendly");
        set("env/wimpy", 60);
        set("chat_chance_combat", 50 );
        set("chat_msg_combat", ({
                "ũ��е���ɱ���ģ�ɱ���ģ�\n",
                "ũ��е����������ģ����컯���´���ģ�\n",
                (: command, "surrender" :),
        }) );
        set("inquiry", ([ 
            "������" : (: ask_jiu :), 
           ]) ); 

        setup();
        add_money("coin", 20);
}

int ask_jiu () 
{ 
         int tt; 
         object obj;
         object me=this_object();
         object who=this_player();
         tt=who->query("wine/gaoliang");
         if( tt) 
         { if(tt<=time() && time()<tt+1200) 
        { message_vision("\n"+me->query("name")+"˵�������Ҫ���ƣ��ȵ������ɡ�\n",who); 
            return 1; } 
        }
         if (who->query("level")<20){
               command("say "+RANK_D->query_respect(who)+"���ļ���Ŭ��ѽ������ȼ����������ɡ� \n"); 
           return 1;}
         if ( !who->query("wine/start") || !present("jiu pai",who)) { 
               command("say ����û�����־ơ� \n"); 
               return 1;} 
         if ( !who->query_temp("killshu")){
           command("sigh"); 
           command("say ��....����ͷ������֣������ׯ�ڶ����Թ��ˣ�������ܰ���ɱ�˻���ׯ�ڵ����󾫣��Ҿ��ø����ƿ���㡣 \n"); 
             return 1;}
          obj=new("/d/quest/wine/obj/gaoliangjiu");
          obj->move(who);
          who->set("wine/gaoliang",time());
          who->delete_temp("killshu");
          message_vision("$N����$nһƿ"+obj->query("name")+"��\n", me,who);
            return 1; 
} 
