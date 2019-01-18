//  /d/quest/yaota/npc/xxn.c
      
inherit NPC; 
#include <ansi.h> 
 
int ask_yaota ();  
void create() 
{ 
         set_name( HIY "С��Ů" NOR, ({"xiao xiannv","xiannv"})); 
        set("title",HIR+"��������"+NOR);  
        set("long", "����һ������������磬���ĸ�ǿ��ֱ��ܷܷŮ�ӣ��������·�Ѱ���ܹ�������ħ������־ʿ��\n");  
        set("gender", "Ů��");  
        set("attitude", "peaceful"); 
        set("class", "xian"); 
        set("age", 16); 
        set("str", 40+random(10)); 
        set("int", 30); 
        set("per", 30+random(4)); 
        set("con", 20); 
        set("max_kee", 50000);    
        set("max_sen", 50000);     
        set("kee", 50000);   
        set("sen", 50000);    
        set("max_force", 30000);   
        set("force", 30000);  
        set("force_factor", 450);  
        set("max_mana", 30000);   
        set("mana", 30000);   
        set("mana_factor", 450);  
        set("combat_exp", 15000000);   
        set("daoxing", 15000000);   
    
        set_skill("unarmed", 600);  
        set_skill("force", 600);  
        set_skill("dodge", 600);  
        set_skill("parry", 600);  
        set_skill("spells", 600);  
        set_skill("sword", 600);  
        set_skill("snowsword",600);  
        set_skill("moonforce",600);  
        set_skill("moonshentong",600);  
        set_skill("moondance",600);  
        set_skill("baihua-zhang",600); 
        map_skill("dodge","moondance");  
        map_skill("unarmed","baihua-zhang");  
        map_skill("force","moonforce");  
        map_skill("spells","moonshentong");  
        map_skill("sword","snowsword");  
        map_skill("parry","snowsword");   
        set("chat_chance_combat", 60);  
        set("chat_msg_combat", ({ 
                (: exert_function, "recover" :),  
                (: perform_action, "sword", "hanyue" :),  
                (: perform_action, "sword", "tian" :),  
          }) );  
         
          set("inquiry", ([ 
            "����" : (: ask_yaota :),  
          ]) ); 
          setup(); 
         
          carry_object("/d/obj/cloth/nichang")->wear();   
          carry_object("/d/obj/cloth/huazheboots")->wear();
          carry_object("/d/obj/weapon/sword/qinghong")->wield();   
} 
             
int ask_yaota () 
{ 
         int tt; 
        object me=this_player();
        object ob=this_object();
        if( (tt=(int)me->query("yaota/job_start")) && me->query("yaota/done")=="done") { 
        // job done 
                if(tt<=time() && time()<tt+900) { 
                        message_vision("\n"+ob->query("name")+"˵��:�����Ѿ���ɣ��㻹�ǵȵ�������\n",me); 
                        return 1; 
                } 
        } 
        if( me->query("yaota/fail") ) { 
                if(tt<=time() && time()<tt+900) { 
                        message_vision("\n"+ob->query("name")+"˵����������ʧ���ˣ��ȵ������ɡ�\n",me); 
                        return 1; 
                } 
                me->delete("yaota/fail");   
        } 
        if(me->query("combat_exp")<8000000 || me->query("daoxing")<8000000){  
                command("say �������ڵ���Ϊȥ����̫Σ���ˣ����Ǻú����������ɡ�\n");  
                command("pat " +me->query("id"));  
                return 1;
        } 
        if(me->query("yaotapass")>=3 ){  
                command("say ���Ѿ�����˷��ڵ����飬������ȥ�ˡ�\n");  
                command("thank " +me->query("id")); 
                return 1;
        } 
        else {
                command("say ȥ�����׶༪�ٰ��������İ��ҽ�����ħ��������������ѽ�����������������һ�úô�л��ģ���������㵽������Ű��"+HIB"����"NOR+"����ҪС�Ĳ��ǣ�ף����ˣ�\n");    
                tell_room(environment(me),HIW"\nͻȻһ��������ƴ����Ʈ������"+me->query("name")+"�������𣬲���һ�̾���ʧ����Ӱ���١�\n"NOR);
                me->move("/d/quest/yaota/gate");
                me->delete("yaota/job_start"); 
                me->set("yaota/job_start",time()); 
                me->delete("yaota/done");
        }
        return 1; 
} 

int accept_fight(object ob) 
{ 
         object me = this_object();  
         object who = this_player();  
         if(me->is_fighting() )  
                 return notify_fail(HIY"С��Ů"NOR+"����˵��û������æ����ô��\n"); 
         if( (int)me->query("kee")*100/(int)me->query("max_kee") < 60 )  
                 return notify_fail(HIY"С��Ů"NOR+"����˵�����������岻�ʣ������˴�ܣ�\n"); 
         command("hmm");  
         command("say ��Ϊ�󣬲�Ҫ�������ʹ���...\n");  
         return 0;  
} 
