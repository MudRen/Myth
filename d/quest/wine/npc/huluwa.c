inherit NPC;
int ask_hulu (); 

void create()
{
        set_name("��«��", ({ "hulu wa" }) );
        set("gender", "����" );
        set("age", 10+random(5));
        set("long", "����һ��������õĺ�«�ޡ�\n");
        set("combat_exp", 150+random(800));
        set("attitude", "friendly");
        set("env/wimpy", 60);
        set("chat_chance_combat", 50 );
        set("chat_msg_combat", ({
                "��«�޽е���ɱ���ģ���������\n",
                "��«�޽е����������Ⱦ��Ұ���\n",
                (: command, "surrender" :),
        }) );
        set("inquiry", ([ 
            "��պ�«" : (: ask_hulu :), 
           ]) ); 

        setup();
}

int ask_hulu () 
{ 
         object obj;
         object me=this_object();
         object who=this_player();
         if (who->query("level")<35){
               command("say "+RANK_D->query_respect(who)+"���ļ���Ŭ��ѽ������ȼ����������ɡ� \n"); 
           return 1;}
        if ( !who->query("wine/start") || !present("jiu pai",who)) { 
               command("say ����û����Ҫ�Ķ����� \n"); 
               return 1;} 
         if ( who->query_temp("poem/wrong") || !who->query("poem_answered")){
           command("pure "+who->query("id"));
           command("say ���⵹���и�������«�������������Ҫ������ȥ�������ָ�ʫ��ȥ��ʫ������˾͸��㡣 \n"); 
           command("xixi");
             return 1;}
          obj=new("/d/quest/wine/obj/hulu");
          obj->move(who);
          message_vision("$N����$nһֻ"+obj->query("name")+"��\n", me,who);
          who->delete("poem_answered");
            return 1; 
} 
