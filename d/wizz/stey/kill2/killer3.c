//modifyed by stey steywen@21cn.com

inherit NPC;

#include <ansi.h>
void copy_status(object me, int level);
void set_skills(int max_value, int level);
void set_hp_status(object me, int level);
object owner() {return query("owner");}




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



void setname()
{
        int i;
        string name;
        i=random(sizeof(names));
        name=names[i]+(random(2)?"С��":"С��");
        
        set_name(name, ({ "yao guai", "guai" }) );
                
}

void create()
{        
        setname();
        set("age", 100+random(80));
        set("gender", random(2)?"����":"Ů��");
        set("attitude", "heroism");
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
        set("taskguai",1);
        set("chat_chance", 5);
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");        

        setup();
}



string invocation(object me, int level)
{
        object guai,env;        
        guai=this_object();
        copy_status(me, level);
        
        set("owner", me);
//        set("kind",me->query("bauhu/kind"));
        set("level",level);
        call_out("follow",10);
      
        
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
        set("force_factor", skill_force/2);
        set("mana_factor", query_skill("spells",1));
        
        if (exp < 2000000)
           {
                set("max_kee", max_kee*2);
                set("eff_kee", max_kee*2);
                set("max_sen", max_sen*2);
                set("eff_sen", max_sen*2);
                set("kee", max_kee*2);
                set("sen", max_sen*2);
                set("max_mana", maximum_mana*3/2);
                set("mana",maximum_mana*3);
                set("combat_exp", exp+exp*1/16+random(exp*1/16));
                set("daoxing", daoxing+daoxing*1/16+random(daoxing*1/16));
                set_temp("apply/armor", 150);
                set_temp("apply/damage", 80);
           }
           
        else if (exp < 8000000)
           {
                set("max_kee", max_kee*3);
                set("eff_kee", max_kee*3);
                set("max_sen", max_sen*3);
                set("eff_sen", max_sen*3);
                set("kee", max_kee*3);
                set("sen", max_sen*3);
                set("max_mana", maximum_mana*2);
                set("mana",maximum_mana*4);
                set("combat_exp", exp+exp*1/12+random(exp*1/12));
                set("daoxing", daoxing+daoxing*1/12+random(daoxing*1/12));
                set_temp("apply/armor",200);
                set_temp("apply/damage", 120);
           }   
           
           else if (exp < 15000000)
           {
                set("max_kee", max_kee*4);
                set("eff_kee", max_kee*4);
                set("max_sen", max_sen*4);
                set("eff_sen", max_sen*4);
                set("kee", max_kee*4);
                set("sen", max_sen*4);
                set("max_mana", maximum_mana*5/2);
                set("mana",maximum_mana*5);
                set("combat_exp", exp+exp*1/6+random(exp*1/6));
                set("daoxing", daoxing+daoxing*1/6+random(daoxing*1/6));
                set_temp("apply/armor", 250);
                set_temp("apply/damage", 150);
           }
           else 
           {
                set("max_kee", max_kee*8);
                set("eff_kee", max_kee*8);
                set("max_sen", max_sen*8);
                set("eff_sen", max_sen*8);
                set("kee", max_kee*8);
                set("sen", max_sen*8);
                set("max_mana", maximum_mana*5/2);
                set("mana",maximum_mana*5);
                set("combat_exp", exp+exp*1/2+random(exp*1/3));
                set("daoxing", daoxing+daoxing*1/2+random(daoxing*1/3));
                set_temp("apply/armor", 450);
                set_temp("apply/damage", 200);
           }  
}
void init()
{
  ::init();
  add_action("do_no", "fight");
  add_action("do_no", "kill");
  add_action("do_no", "steal");
  add_action("do_no", "cast");
  add_action("do_no","ji");
  add_action("do_no","throw");
  add_action("do_block","",1);
  call_out("leave",20);   
}
int do_no(string arg)
{
  object who = this_player();
  object me = this_object();
  if (who != owner())
        {
        message_vision(CYN"$N˵�����㲻�����͹�����\n"NOR,me);
       
         return 1;
        }

 
  me->kill_ob(who);
  return 0;
}
void follow()
{
      object me = this_player(); 
      object where = environment (me);
      object ob = present (me, where);
     // object ob2 = find_living(me);
        object guai = me->query_temp("baohu/ob");
  if (!living(guai))    
  //    if (!ob2 && !living(guai))
       {   
        command("say �ֵ����ǵ����ˣ����Ż��ǸϿ쳷������");
        message("vision",HIB + name() + "һ���̵�����ۡ�\n" NOR,environment());
        remove_call_out("follow");
        destruct(this_object());
        return ;
       }
       
   remove_call_out("follow");
   call_out("follow",5); 
   return;
}

void heart_beat()
{  object guai = this_object();
   ::heart_beat();
 /*  
   if ( !is_fighting()
        && query("eff_kee") >= query("max_kee") / 2 
        && !query_skill("tonsillit",1)
        && !query_skill("shushan-force",1)
         && query("eff_kee") <  query("max_kee") )
     command("eat yao");
      
   if (query("kee") < query("eff_kee")-10 )
         command("exert recover");
   if (query("sen") < query("eff_sen")-10) 
     command("exert refresh");
   if (query("force") < query("max_force"))
     command("cast transfer");
   if (!owner() || owner()->query("bauhu/fail") )    
        destruct(guai);
   */
}       




void die()
{       object me = owner();
       
       me->add_temp("bauhu_killer",1);
             
        ::die();
}



void destruct_ob (object ob)
{
  destruct (ob);
}

void kill_ob (object ob)
{
          object mee = this_object();  
          if (mee->query("level")>1)
              mee->set_leader(ob);
            ::kill_ob(ob);
}           
int do_block(string arg)
{
    object me=this_object();
    object who=this_player();
    string verb=query_verb();
    int t;
    
    // wizardp(who) && 
    
    if(!userp(who)) return 0;
       
      
    if(who->query_temp("bauhu_kill")==0) return 0;
       
    if(verb!="go" &&
            verb!="fly" &&
            !(environment() && environment()->query("exits/" + verb)))
        return 0;
    
    t= random(2);
   
    if (t==1) {
        
        message_vision("$n��$Nһ����ע�⣬��æ���˹�ȥ��\n",me,who);
        return 0;
    }
   
        message_vision("$Nһ������$n��ǰ�������е���\n"+
                " �����֣�����������������,�������ɣ�\n\n",me,who);
        tell_object(who,me->name()+"һ����ס���㣡\n");
         return 1;
}
