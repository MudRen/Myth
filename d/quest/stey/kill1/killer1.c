//modifyed by stey steywen@21cn.com

inherit NPC;

#include <ansi.h>
void copy_status(object me, int level);
void set_skills(int max_value, int level);
void set_hp_status(object me, int level);
object owner() {return query("owner");}
void _leave();
void leave();




string *names = ({
        "∫¸¿Í",
        "∫⁄–‹",
        "π∑–‹",
        "∞◊–‹",
        "–´◊”",
        "Ú⁄Úº",
        "ª®±™",
        "∞ﬂ¬Ì",
        "∫⁄ ®",
        "ª∆ ®",
        "≤Ú¿«",
        "¿œª¢",
        " ®◊”",
        "ª∆ ®",
        "∞◊ ®",
        "ª®±™",
        "…Ω±™",
        "≤›±™",
        "¥ÛµÒ",
        "¬Ì∫Ô",
        "‚®∫Ô",
        "‘≥∫Ô",
        "ª“¿«",
        "“∞÷Ì",
        "¬Ì¬π",
        "∞◊¬π",
        "ª“¬π",
        "∫⁄¬π",
        "ª®∫¸¿Í",
        "∞◊∫¸¿Í",
        "ª“∫¸¿Í",
        "–…–…",
        "·Ù·Ù",
        "ÀÆ≈£",
        "ÍÛ≈£",
        "“∞≈£",
        "∞◊ Û",
        "ª“ Û",
        "∫⁄¬Ï“œ",
        "¬Ï“œ",
        "∞◊“œ",
});



void setname()
{
object ob = this_player(); 
        int i;
        string name;
        i=random(sizeof(names));
        name=names[i]+(random(2)?"¿œæ´":"¿œπ÷");
        
set_name(name, ({ob->query("id") + " lao guai"})); 
                
}

void create()
{        
        setname();
        set("age", 100+random(80));
        set("gender", random(2)?"ƒ––‘":"≈Æ–‘");
        set("attitude", "heroism");
        set("per", 40);
        set("str", 50);
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
//        set("kind",me->query("baohu/kind"));
        set("level",level);
  //      call_out("follow",10);
      
        
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
                while(i--) { // ’“≥ˆÕÊº“skill◊Ó¥Û÷µ
                    if(skill_value[i]>max_value)
                        max_value=skill_value[i];
                }
          } else max_value=1;
            set("npcstart",time()+900+random(900));      
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
                set("kee", max_kee*7/6);
                set("sen", max_sen*7/6);
                set("max_mana", maximum_mana*3/2);
                set("mana",maximum_mana*3/2);
                set("combat_exp", exp);
                set("daoxing", daoxing);
                set_temp("apply/armor", 150);
                set_temp("apply/damage", 35);
           }
           
        else if (exp < 8000000)
           {
                set("max_kee", max_kee*2);
                set("eff_kee", max_kee*2);
                set("max_sen", max_sen*2);
                set("eff_sen", max_sen*2);
                set("kee", max_kee*2);
                set("sen", max_sen*2);
                set("max_mana", maximum_mana*5/4);
                set("mana",maximum_mana*5/4);
                set("combat_exp", exp);
                set("daoxing", daoxing);
                set_temp("apply/armor",250);
                set_temp("apply/damage", 35);
           }   
           
           else if (exp < 15000000)
           {
                set("max_kee", max_kee*2);
                set("eff_kee", max_kee*2);
                set("max_sen", max_sen*2);
                set("eff_sen", max_sen*2);
                set("kee", max_kee*2);
                set("sen", max_sen*2);
                set("max_mana", maximum_mana*5/4);
                set("mana",maximum_mana*2);
                set("combat_exp", exp);
                set("daoxing", daoxing);
                set_temp("apply/armor", 350);
                set_temp("apply/damage", 35);
           }
           else 
           {
                set("max_kee", max_kee*10/3);
                set("eff_kee", max_kee*10/3);
                set("max_sen", max_sen*10/3);
                set("eff_sen", max_sen*10/3);
                set("kee", max_kee*10/3);
                set("sen", max_sen*10/3);
                set("max_mana", maximum_mana*3/2);
                set("mana",maximum_mana*2);
                set("combat_exp", exp);
                set("daoxing", daoxing);
                set_temp("apply/armor", 450);
                set_temp("apply/damage", 40);
           }  
}
void init()
{
    object me=this_object();
    object who=this_player();
    int type;
    int t=query("npcstart");
  ::init();
  add_action("do_no", "fight");
  add_action("do_no", "kill");
  add_action("do_no", "steal");
  add_action("do_no", "cast");
  add_action("do_no","ji");
  add_action("do_no","throw");
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
//  call_out("follow",150);   
}
int do_no(string arg)
{
  object who = this_player();
  object me = this_object();
     if (!userp(who)) return 1;
  if (who != owner())
        {
        message_vision(CYN"$NÀµµ¿£∫ƒ„≤ª≈¬À¿æÕπˆ£°°£\n"NOR,me);
        random_move();//◊ﬂø™
         return 1;
        } 
 
 
  me->kill_ob(who);
  return 0;
}


void heart_beat()
{  object guai = this_object();
   object who= owner();
  
   ::heart_beat();  

     if ( living(who) && is_fighting(who)) {
                  if (who->query("env/invisibility"))
                                                 {
                     who->delete_temp("yinshentime");
                  who->set("env/invisibility",0);
           message_vision(HIW"\n$N¥µ¡Àø⁄∆¯,$n”÷œ÷≥ˆ¡À…Ì–Œ°£\n"NOR, guai,who); 
                                                 }
                                     }
}       

void unconcious()
{
   die();
}

void die()
{       object me = owner();
       me->add("baohu_killer", 1);
        if ((int)me->query("baohu_killer") >= 3)
             {
              me->set("baohu/done",1);
              me->delete("baohu/get");
              me->delete("baohu_killer");
        }
         message_vision (CYN"\n$N∫∞:  –÷µ‹£¨Œ“√≈ÕÍ¡À......\n"NOR,this_object());
        load_object("/obj/empty");      
        this_object()->move("/obj/empty");
        destruct (this_object());
}



void destruct_ob (object ob)
{
  destruct (ob);
}

void kill_ob (object ob)
{
          object me = this_object();  
          if (me->query("level")>1)
              me->set_leader(ob);
            ::kill_ob(ob);
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
                  "…Ì◊”“ªªŒ£¨±‰≥…“ªπ…«‡—Ã…¢»•¡À°£\n" NOR,environment());
}
        destruct(this_object());
      }
      return;
}
