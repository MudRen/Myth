//modifyed by stey steywen@21cn.com 
#include <ansi.h> 
inherit NPC; 
void _leave(); 
void leave(); 
void copy_status(object me, object who, int level);
void set_skills(int max_value, int level); 
void set_hp_status(object me, int level); 
object owner() {return query("owner");} 
object ownertwo() {return query("ownertwo");} 
 
string *dirs1 = ({ 
"/d/qujing/baotou", 
"/d/qujing/baoxiang", 
"/d/qujing/biqiu", 
"/d/qujing/chechi", 
"/d/qujing/dudi", 
"/d/qujing/fengxian", 
"/d/qujing/firemount", 
"/d/qujing/jilei", 
"/d/qujing/jindou", 
"/d/qujing/jinping", 
"/d/qujing/jisaiguo", 
"/d/qujing/maoying", 
"/d/qujing/nuerguo", 
"/d/qujing/pingding", 
"/d/qujing/pansi", 
"/d/qujing/tongtian", 
"/d/qujing/qilin", 
"/d/qujing/qinfa", 
"/d/qujing/qinglong", 
"/d/qujing/tianzhu", 
"/d/qujing/wudidong", 
"/d/qujing/wuji", 
"/d/qujing/xiaoxitian", 
"/d/qujing/yinwu", 
"/d/qujing/yuhua", 
"/d/qujing/zhujie", 
"/d/qujing/zhuzi", 
 
}); 
 
string *names = ({ 
        "����",  
        "����",  
        "����",  
        "����",  
        "Ы��",  
        "���",  
        "����",  
        "����",  
        "��ʨ",  
        "��ʨ",  
        "����",  
        "�ϻ�",  
        "ʨ��",  
        "��ʨ",  
        "��ʨ",  
        "����",  
        "ɽ��",  
        "�ݱ�",  
        "���",  
        "���",  
        "⨺�",  
        "Գ��",  
        "����",  
        "Ұ��",  
        "��¹",  
        "��¹",  
        "��¹",  
        "��¹",  
        "������",  
        "�׺���",  
        "�Һ���",  
        "����",  
        "����",  
        "ˮţ",  
        "��ţ",  
        "Ұţ",  
        "����",  
        "����",  
        "������",  
        "����",  
        "����",  
 
}); 
 
int random_place(object me, string* dirs); 
 
void setname() 
{ 
object ob = this_player(); 
        int i; 
        string name; 
        i=random(sizeof(names)); 
        name=names[i]+(random(2)?"��":"��"); 
 
set_name(name, ({ob->query("id") + " couple guai"})); 
 
} 
 
void create() 
{ 
        setname(); 
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
        set("chat_msg", ({ 
             (: random_move :) 
        }) ); 
 
 
        setup(); 
 /*       carry_object("/d/obj/cloth/tianyi.c")->wear(); 
        carry_object("/d/9ct/zb/sword")->wield(); 
        carry_object("/d/9ct/zb/pifeng")->wear(); 
        carry_object("/d/ourhome/obj/shoes")->wear();  
        */
 
} 
 
void copy_status(object me, object who, int level) 
{ 
        mapping me_skill,who_skill; 
        int *skill_value, max_value, i,t; 
        me_skill = me->query_skills(); 
       
        max_value = 200; 
        i=sizeof(me_skill); 
        if(i>0) { 
                skill_value=values(me_skill); 
                while(i--) { // �ҳ����skill���ֵ 
                    if(skill_value[i]>max_value) 
                        max_value=skill_value[i]; 
                } 
          } 
         who_skill = who->query_skills(); 
         t=sizeof(who_skill); 
        if(t>0) { 
                skill_value=values(who_skill); 
                
                while(t--) { // �ҳ����skill���ֵ 
                    if(skill_value[t]>max_value) 
                        max_value=skill_value[t]; 
                } 
          } 
          
          set("stay_time",time()+900+random(600)); 
          set_skills(max_value, level); 
          
          if(me->query("combat_exp") > who->query("combat_exp")) 
          {       set_hp_status(me,level);} 
          else {set_hp_status(who,level); }
 
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
int random_place(object me, string* dirs) 
{ 
        int  i, j, k; 
        object  newob; 
        mixed*  file, exit; 
 
        if( !sizeof(dirs) )  return 0; 
 
        i = random(sizeof(dirs));    // pick up one directory 
 
        file = get_dir( dirs[i]+"/*.c", -1 ); 
        if( !sizeof(file) )             return 0; 
 
        for(k=0;k<30;k++) { // try 30 times 
           j = random(sizeof(file)); 
           if( file[j][1] > 0 ) { 
             newob=load_object(dirs[i]+"/"+file[j][0]); 
             if (newob) { 
               if(newob->query("no_fight") || 
                       newob->query("no_magic") || 
                       newob->query("no_mieyao") || 
                       !(exit=newob->query("exits")) || 
                       sizeof(exit)<1 || 
                       !newob->query("outdoors") ) 
                   continue; 
 
               if(me->move(newob)) { 
                   message_vision("$N���˹�����\n",me); 
                   return 1; 
               } 
             } 
           } 
        } 
 
        return 0; 
} 
string invocation(object me, object who,int level) 
{ 
        object guai,env; 
        string *dirs, where; 
 
        dirs=dirs1; 
        guai=this_object(); 
        copy_status(me,who,level); 
        guai->set("title","����"+me->query("name")+"���޵�"); 
        set("owner", me); 
        set("ownertwo",who); 
        set("level",level); 
 
        if(!random_place(guai, dirs))  return "û���ڡ�"; 
 
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
  
    add_action("do_block","",1); 
  
 
 
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
 
int do_no(string arg)  
{  
  object who = this_player();  
  object me = this_object();  
     if (!userp(who)) return 1;  
  if (who != owner() && who !=ownertwo())  
        {  
        message_vision(CYN"$N˵�����㲻�����͹�����\n"NOR,me);  
        random_move();//�߿�  
         return 1;  
        }   
   
   
  me->kill_ob(who);  
  return 0;  
}  
 
 
 
 
 
 
void die () 
{ 
 
 
  object ob = query_temp("last_damage_from"); 
  object me = this_object(); 
  object where = environment (me); 
         int bons,bons2; 
 
        if (ob != owner() && ob!=ownertwo() ) 
        { 
        message_vision("$N���ˡ�\n"NOR,me); 
        destruct (me); 
         return; 
        } 
         message_vision(CYN"$N���ˡ�\n"NOR,me); 
       if(living(owner()) || living(ownertwo())) 
       { 
       
 
        
       owner()->delete("job_couple/get"); 
       ownertwo()->delete("job_couple/get"); 
       owner()->set("job_couple/done"); 
       ownertwo()->set("job_couple/done"); 
        bons=owner()->query("job_couple/rekee")+owner()->query("job_couple/resen"); 
        bons2=ownertwo()->query("job_couple/rekee")+ownertwo()->query("job_couple/resen"); 
        if(bons>(bons+bons2)/15) 
        { 
        owner()->add("combat_exp",(bons+bons2)/100); 
        owner()->add("potential",(bons+bons2)/700); 
        owner()->set("job_couple/resen",1); 
        owner()->set("job_couple/rekee",1); 
        tell_object(owner(),"��õ���"+(bons+bons2)/100+"����ѧ��\n"+"��õ���"+(bons+bons2)/700+"��Ǳ�ܡ�\n"); 
        } 
        if(bons2>(bons+bons2)/15) 
        { 
        ownertwo()->add("combat_exp",(bons+bons2)/100); 
        ownertwo()->add("potential",(bons+bons2)/700); 
        ownertwo()->set("job_couple/resen",1); 
        ownertwo()->set("job_couple/rekee",1); 
        tell_object(ownertwo(),"��õ���"+(bons+bons2)/100+"����ѧ��\n"+"��õ���"+(bons+bons2)/700+"��Ǳ�ܡ�\n"); 
         } 
        }
        destruct (me); 
} 
 
 
void unconcious() 
{ 
   die(); 
} 
 
void _leave() 
{ 
        object me=this_object(); 
        if(me->is_fighting() || me->is_busy()) 
        return; 
        leave(); 
} 
 
void leave() 
{ 
      if(this_object()) { 
        if(environment()) 
{ 
 
          message("vision",HIB + name() + 
                  "��ʧ�ˡ�\n" NOR,environment()); 
} 
        destruct(this_object()); 
      } 
      return; 
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
 
 
 
int do_block(string arg) 
{ 
    object me=this_object(); 
    object who=this_player(); 
    string verb=query_verb(); 
    int t; 
 
 
    if(!userp(who)) return 0; 
 
 
    if(who->query_temp("baohu_kill")==0) return 0; 
 
    if(verb!="go" && 
            verb!="fly" && 
            !(environment() && environment()->query("exits/" + verb))) 
        return 0; 
 
    t= random(1); 
 
    if (t==1) { 
 
        message_vision("$n����$N����������ˡ�\n",me,who); 
        return 0; 
    } 
 
        message_vision("$Nһ��������$n��ǰ�������е���\n"+ 
                " �����֣����������ң���Ҫ���ˡ�\n\n",me,who); 
        tell_object(who,me->name()+"һ����ס���㣡\n"); 
        return 1; 
} 
 
varargs int receive_wound(string type, int damage, object who)  
{  
        object me=this_object(); 
  call_out("exerthh",1,me); 
      if(userp(who)){  
        if(who==owner() && who==ownertwo()) {  
       
           // can't use other's NPC to help kill.  
         if(damage>0) {  
            switch(type) {  
                case "kee": who->add("job_couple/rekee",damage); break;  
                case "sen": who->add("job_couple/resen",damage); break;  
            }  
         }  
     }  
     }  
    return ::receive_wound(type, damage, who);  
}  
  
varargs int receive_damage(string type, int damage, object who)  
{  
    object me=this_object(); 
  call_out("exertheal",1,me); 
      if(userp(who)){  
        if(who==owner() && who==ownertwo()) {  
           // can't use other's NPC to help kill.  
        if(damage>0) {  
            switch(type) {  
                case "kee": who->add("job_couple/rekee",damage); break;  
                case "sen": who->add("job_couple/resen",damage); break;  
            }  
        }  
       }  
     }  
    return ::receive_damage(type, damage, who);  
} 
 
void exertheal(object me) 
{ 
        if(me->query("force")>100){      
   me->set("kee",me->query("eff_kee")); 
    me->set("sen",me->query("eff_sen")); 
    me->add("force",-30);} 
} 
void exerthh(object me) 
{ 
  me->set("eff_sen",me->query("max_sen")); 
  me->set("eff_kee",me->query("max_kee")); 
 
} 
 
 
