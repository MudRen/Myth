//modifyed by stey steywen@21cn.com 
#include <ansi.h> 
inherit NPC; 
void _leave(); 
void leave(); 
void copy_status(object me, int level); 
void set_skills(int max_value, int level); 
void set_hp_status(object me, int level); 
object owner() {return query("owner");} 
 
string *list=({"yg-qiankun","yg-jianmang","yg-jianzhang","yg-zxzx", 
                "yg-ba","yg-jldl", 
        }); 
         

 
int random_place(object me, string* dirs); 
 

 
void create() 
{       set_name("����", ({ "tang xuanzhang", "xian" }) );     
        set("age", 100+random(80)); 
        set("gender", "Ů��"); 
        set("attitude", "friendly"); 
        set("per", 40); 
        set("str", 100); 
        set("cor", 40); 
        set("con", 40); 
        set("int", 40); 
        set("spi", 40); 
        set("cps", 40); 
        set("kar", 40); 
        set("max_gin", 1000); 
        set("food", 10000); 
        set("water", 10000); 
        set_weight(30000); 
        set("no_steal",1); 
        set("class","xian"); 
       set("taskguai",1); 
        set("chat_chance", 5); 
        set("can_move",1);
 
         
        setup(); 
        carry_object("/d/obj/cloth/tianyi.c")->wear(); 
        carry_object("/d/9ct/zb/sword")->wield(); 
        carry_object("/d/9ct/zb/pifeng")->wear(); 
        carry_object("/d/ourhome/obj/shoes")->wear(); 
 
} 
 
void copy_status(object me, int level) 
{ 
        mapping me_skill; 
        int *skill_value, max_value, i; 
         
        me_skill = me->query_skills(); 
        i=sizeof(me_skill); 
        if(i>0) { 
                skill_value=values(me_skill); 
                max_value=skill_value[0]; 
                while(i--) { // �ҳ����skill���ֵ 
                    if(skill_value[i]>max_value) 
                        max_value=skill_value[i]; 
                } 
          } else max_value=1; 
          set("stay_time",time()+900+random(600));             
          set_skills(max_value, level); 
           
          set_hp_status(me,level); 
             
}          
           
void set_skills(int max_value, int level) 
{ 
        object guai=this_object();        
        int guai_value; 
         
        if (level==1) guai_value = max_value+max_value/8; 
        else if (level==2) guai_value = max_value+max_value/6; 
        else guai_value = max_value+max_value/4; 
         
        set_skill("unarmed", guai_value+random(16)); 
        set_skill("dodge", guai_value+random(16)); 
        set_skill("parry", guai_value+random(16)); 
        set_skill("force", guai_value+random(16)); 
        set_skill("spells", guai_value+20+random(16)); 
         set_skill("literate", guai_value+20+random(16)); 
        
   set_skill("moonshentong", guai_value+20+random(16)); 
   set_skill("baihua-zhang", guai_value+20+random(16)); 
   set_skill("moonforce", guai_value+20+random(16)); 
   set_skill("snowsword", guai_value+20+random(16)); 
   set_skill("moondance", guai_value+20+random(16)); 
   map_skill("spells", "moonshentong"); 
   map_skill("unarmed", "baihua-zhang"); 
   map_skill("force", "moonforce"); 
   map_skill("sword", "snowsword"); 
   map_skill("parry", "snowsword"); 
   map_skill("dodge", "moondance"); 
   set("chat_chance_combat", 50); 
     set("chat_msg_combat", ({ 
                (: cast_spell, "mihun" :), 
                (: cast_spell, "arrow" :) 
        }) ); 
}        
 
 
void set_hp_status(object me, int level) 
{       int max_kee,max_sen,skill_force,maximum_mana,exp,daoxing; 
        max_kee = me->query("max_kee"); 
        max_sen = me->query("max_sen"); 
        skill_force = query_skill("force"); 
        maximum_mana = me->query("maximum_mana"); 
        exp = me->query("combat_exp"); 
        daoxing = me->query("daoxing"); 
         
        set("max_force", skill_force*10); 
        set("force", skill_force*20); 
        set("force_factor", skill_force/10); 
        set("mana_factor", query_skill("spells",1)/10); 
         
        if (exp < 8000000) 
           { 
                set("max_kee", max_kee*2); 
                set("eff_kee", max_kee*2); 
                set("max_sen", max_sen*2); 
                set("eff_sen", max_sen*2); 
                set("kee", max_kee*2); 
                set("sen", max_sen*2); 
                set("max_mana", maximum_mana); 
                set("mana",maximum_mana); 
                set("combat_exp", exp+exp*1/16+random(exp*1/16)); 
                set("daoxing", daoxing+daoxing*1/13+random(daoxing*1/16)); 
                set_temp("apply/armor", 400); 
                set_temp("apply/damage", 100); 
           } 
            
        else  
           { 
                set("max_kee", max_kee*2); 
                set("eff_kee", max_kee*2); 
                set("max_sen", max_sen*2); 
                set("eff_sen", max_sen*2); 
                set("kee", max_kee*3/2); 
                set("sen", max_sen*3/2); 
                set("max_mana", maximum_mana); 
                set("mana",maximum_mana); 
                set("combat_exp", exp+exp*1/12+random(exp*1/12)); 
                set("daoxing", daoxing+daoxing*1/12+random(daoxing*1/12)); 
                set_temp("apply/armor",300); 
                set_temp("apply/damage", 150); 
           }    
            
       
 
            
} 

string invocation(object me, int level) 
{ 
        object guai,env;         
        string where; 
         
        guai=this_object(); 
        copy_status(me, level); 
        guai->set("title",me->query("name")+"��ȵ�"); 
        set("owner", me); 
        set("level",level); 
       
         
        env=environment(guai); 
        where=guai->query("name"); 
           
        if(env) 
         where += "��"+MISC_D->find_place(env); 
        return where; 
//        call_out("destruct_me",900); 
         
         
} 
 
void init() 
{ 
    object me=this_object(); 
    object who=this_player(); 
    int type; 
    int t=query("stay_time"); 
    ::init(); 
    add_action("do_no","ji");     
    add_action("do_qk","cast"); 
    add_action("do_go","comeon"); 
    add_action("do_block","",1);    
    add_action("do_baohu", "baohu"); 
    add_action("do_baohu", "dajiu"); 
    add_action("do_healup", "heal"); 
     
 
    
    if(t && time()>(t+300)) { 
        remove_call_out("leave"); 
        call_out("leave",1); 
        return; 
    } 
 
    if(t && time()>t) { 
        remove_call_out("_leave"); 
        call_out("_leave",300); 
    } 
    if(!living(this_object())) return; 
    if(!living(who)) return; 
    remove_call_out("check_room");  
    call_out("check_room",2); 
 
}
int do_go(string arg) 
{ 
        object me,who,env;
        string dirt,cast_name; 
        me=this_object();
        who = this_player(); 
         if(who!=owner()) 
           {      
                 tell_object(who,"�����ʲô����\n"); 
                 return 1;}
         if(!this_object()->query("can_move")) {
                command("shake "+who->query("id"));
                return 1;}
//230         if (arg) return 1;
       env = environment(me);
       if (env->query("tsj_done"))
       { 
        who->set_temp("jfftop",1);
        command("smile "+who->query("id"));
        command("smile "+who->query("id"));
        call_out("destruct_me",0,me);
        return 1;}
       dirt=env->query("tsj_exst");
         
         me->command("go "+arg);
              
    //          if (!me->query("where1") && env!=me->query("where1")) 
                    call_out("newguai",1); 
      return 1; 
  
    
}  

void newguai()
{
        object me,who,guai,env;
        int level;
        string where;
        
        
        me=this_object();
        who=this_player();
                level = random(10); 
        if (level<5) level=1; 
        else if (level<8) level=2; 
        else level=3; 
    remove_call_out("newguai");         
  guai = new("/d/jjf/npc/killer/"+list[random(sizeof(list))]); 
  guai->invocation(me, level); 
   guai->move(environment(me)); 
  message_vision ("\n"+guai->query("name")+"ͻȻ���˳���......\n",me); 
       guai->command("follow tang sanzhang"); 
  guai->kill_ob(me); 
  env=environment(me); 
  me->set("where1",env);
  me->delete("can_move"); 
  
  
  
}
int do_qk(string arg) 
{ 
     
        string cast_id,cast_name; 
        object who = this_player(); 
         
    if (sscanf(arg, "%s on %s", cast_id,cast_name) == 2) 
      
      if(cast_id=="qiankun" || arg=="qiankun") 
      
       tell_object(who,"��������������Ԫ���ɵ�������������ͽ����Ҫ�����ҹ��з�����\n"); 
      return 1; 
  
    
} 
int do_healup() 
{ 
       object who = this_player(); 
        object ob = this_object(); 
        if (ob->query("kee")>(ob->query("max_kee")-20)){ 
        message_vision("$N˵����лл!\n$N��ɫ����\n",ob); 
        return 1; 
        } 
        if (who->query("kee") < 300 || who->query("force")<1000) 
         {      tell_object(who,"����ɫ���\n"); 
              return 1; 
              } 
        who->add("force", -300); 
        ob->add("kee", 50); 
        message_vision("$N�ܵ���$n����������!\n$N����ɫ�������ö��ˡ�\n",ob,who); 
        return 1; 
} 
  
int do_no(string arg) 
{ 
        object who = this_player(); 
        object me = this_object(); 
        message_vision("$N������첻֪���ʲô��$n����Ķ���$N��\n",who,me); 
        return 1; 
} 
 

 
 
void destruct_me(object me) 
{ 
 
        load_object("/obj/empty"); 
         me->move("/obj/empty"); 
          destruct (me); 
   
} 
 
void die () 
{ 
  object me=this_object();
       message_vision(CYN"$N���������ˡ�\n"NOR,me); 
        destruct (me); 
} 
 
 
void unconcious() 
{ 
   die(); 
} 
 

void check_room() 
{ 
    object me=this_object(); 
    object env=environment(me); 
    if(!living(me)) return; 
    if(env && (env->query("no_fight") || 
                env->query("no_magic"))) { 
        random_move(); 
    } 
} 

void heart_beat() 
{ 
object guai = this_object(); 
        if (!query_temp("weapon") && !query_temp("added")) 
        { 
        set_temp("added", 1); 
        set("force_factor",200); 
        set("force",2000); 
        } 
        if (query("eff_kee")<query("max_kee")) 
        { 
        if (random(10)<5){ 
        command("eat yao");} 
 
        else 
        { 
      
                call_out("exertheal",1,this_object()); 
        } 
        } 
 
 
        ::heart_beat(); 
       
} 
varargs int receive_damage(string type, int damage, object who) 
{ 
  object me=this_object(); 
  call_out("exertheal",1,me); 
  return ::receive_damage(type,damage,who); 
} 
 
void exertheal(object me)  
{ 
  me->command("exert recover"); 
 
} 

 

