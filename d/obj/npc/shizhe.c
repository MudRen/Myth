//modifyed by stey steywen@21cn.com

inherit NPC;

#include <ansi.h>
void copy_status(object me, int level);
void set_skills(int max_value, int level);
void set_skills2(int max_value, int level);
void set_hp_status(object me, int level);
object owner() {return query("owner");}


void create()
{        
        set_name(HIC"����ʹ��"NOR, ({"shi zhe"}) );
        set("age", 40+random(80));
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
        add_money("silver",50);
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
void set_skills2(int max_value, int level)
{
        int guai_value,tt;
        set_skills(max_value, level);
        
        if (level==1) guai_value = max_value+max_value/8;
        else if (level==2) guai_value = max_value+max_value/6;
        else guai_value = max_value+max_value/4;
        switch(random(4)){
       case 0: 
        set_skill("changquan", guai_value+random(16));
        set_skill("yanxing-steps", guai_value+random(16));
        set_skill("spear", guai_value+random(16));
        set_skill("bawang-qiang", guai_value+random(16));
        set_skill("lengquan-force", guai_value+random(16));
        set_skill("literate", 180);
        set_skill("baguazhou", guai_value+20+random(16));
        map_skill("spells", "baguazhou");
        map_skill("force", "lengquan-force");
        map_skill("unarmed", "changquan");
        map_skill("spear", "bawang-qiang");
        map_skill("parry", "bawang-qiang");
        map_skill("dodge", "yanxing-steps");
        set("force_factor", query_skill("force")/8);
        set("mana_factor", query_skill("spells",1));
                        
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("d/obj/weapon/spear/jinqiang.c")->wield();
           break;
         case 1:
         set_skill("wuxing-quan", guai_value+random(16));
        set_skill("baguazhen", guai_value+random(16));
        set_skill("sword", guai_value+random(16));
        set_skill("sanqing-jian", guai_value+random(16));
        set_skill("zhenyuan-force", guai_value+random(16));
        set_skill("literate", 180);
        set_skill("taiyi", guai_value+20+random(16));
        map_skill("spells", "taiyi");
        map_skill("force", "zhenyuan-force");
        map_skill("unarmed", "wuxing-quan");
        map_skill("sword", "sanqing-jian");
        map_skill("parry", "sanqing-jian");
        map_skill("dodge", "baguazhen");
        set("force_factor", query_skill("force")/8);
        set("mana_factor", query_skill("spells",1));
                        
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/obj/weapon/sword/qinghong.c")->wield();
          break;
         case 2:
         set_skill("wuxing-quan", guai_value+random(16));
        set_skill("baguazhen", guai_value+random(16));
        set_skill("sword", guai_value+random(16));
        set_skill("sanqing-jian", guai_value+random(16));
        set_skill("zhenyuan-force", guai_value+random(16));
        set_skill("literate", 180);
        set_skill("taiyi", guai_value+20+random(16));
        map_skill("spells", "taiyi");
        map_skill("force", "zhenyuan-force");
        map_skill("unarmed", "wuxing-quan");
        map_skill("parry", "sanqing-jian");
        map_skill("sword", "sanqing-jian");
        map_skill("dodge", "baguazhen");
        set("force_factor", query_skill("force")/8);
        set("mana_factor", query_skill("spells",1));
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword","jianzhang" :)
               }) );
        
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/obj/weapon/sword/qinghong.c")->wield();
         break;
         case 3:
         set_skill("literate", 150);
        set_skill("stick", guai_value+random(16));
        set_skill("sword", guai_value+random(16));
        set_skill("liangyi-sword", guai_value+random(16));
        set_skill("dao", guai_value+20+random(16));
        set_skill("puti-zhi", guai_value+random(16));
        set_skill("wuxiangforce", guai_value+random(16));
        set_skill("qianjun-bang", guai_value+random(16));
        set_skill("jindouyun", guai_value+random(16));
        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
        map_skill("dodge", "jindouyun");
        map_skill("sword", "liangyi-sword");
        set("force_factor", query_skill("force")/8);
        set("mana_factor", query_skill("spells",1));
        
                
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/sea/obj/dragonstick.c")->wield();
        break;
         case 4:
          set_skill("literate", 150);
        set_skill("stick", guai_value+random(16));
        set_skill("sword", guai_value+random(16));
        set_skill("liangyi-sword", guai_value+random(16));
        set_skill("dao", guai_value+20+random(16));
        set_skill("puti-zhi", guai_value+random(16));
        set_skill("wuxiangforce", guai_value+random(16));
        set_skill("qianjun-bang", guai_value+random(16));
        set_skill("jindouyun", guai_value+random(16));
        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
        map_skill("dodge", "jindouyun");
        map_skill("sword", "liangyi-sword");
        set("force_factor", query_skill("force")/8);
        set("mana_factor", query_skill("spells",1));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "stick","qiankun" :),
                (: perform_action, "stick","pili" :)
        }) );
        break;
         case 5:
         set_skill("yinfeng-zhua", guai_value+random(16));
        set_skill("lingfu-steps", guai_value+random(16));
        set_skill("sword", guai_value+random(16));
        set_skill("qixiu-jian", guai_value+random(16));
        set_skill("huntian-qigong", guai_value+random(16));
        set_skill("literate", 180);
        set_skill("yaofa", guai_value+20+random(16));
        map_skill("spells", "yaofa");
        map_skill("force", "huntian-qigong");
        map_skill("unarmed", "yinfeng-zhua");
        map_skill("sword", "qixiu-jian");
        map_skill("parry", "qixiu-jian");
        map_skill("dodge", "lingfu-steps");
        set("force_factor", query_skill("force")/8);
        set("mana_factor", query_skill("spells",1));
                        
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/obj/weapon/sword/qinghong.c")->wield();
        break;
        }
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
        set("force_factor", skill_force/5);
        set("mana_factor", query_skill("spells",1));
        
        if (exp < 2000000)
           {
                set("max_kee", max_kee);
                set("eff_kee", max_kee);
                set("max_sen", max_sen);
                set("eff_sen", max_sen);
                set("kee", max_kee*2);
                set("sen", max_sen*2);
                set("max_mana", maximum_mana*3/2);
                set("mana",maximum_mana*3);
                set("combat_exp", exp+exp*1/20+random(exp*1/20));
                set("daoxing", daoxing+daoxing*1/16+random(daoxing*1/16));
                set_temp("apply/armor", 150);
                set_temp("apply/damage", 20);
           }
           
        else if (exp < 8000000)
           {
                set("max_kee", max_kee*2);
                set("eff_kee", max_kee*2);
                set("max_sen", max_sen*2);
                set("eff_sen", max_sen*2);
                set("kee", max_kee*2);
                set("sen", max_sen*2);
                set("max_mana", maximum_mana*2);
                set("mana",maximum_mana*4);
                set("combat_exp", exp+exp*1/12+random(exp*1/12));
                set("daoxing", daoxing+daoxing*1/12+random(daoxing*1/12));
                set_temp("apply/armor",200);
                set_temp("apply/damage", 50);
           }   
         
           
}

void unconcious()
{
   die();
}

void die()
{
   object killer;  
  
   
   command("say ��������ѽ,������ʹ��,��ȥҲ��");
   tell_room(environment(),"˵�꣬"+query("name")+"�������������Ϸ�ȥ����ʧ�ˡ�\n");
   
   killer = query_temp("last_damage_from");
   killer->set_temp("digok",1);
    
 
  destruct(this_object());
 
}

int heal_up()
{
  if( environment() && time()-query("new_time")>480&&!is_fighting()) {
    call_out("leave", 1);
    return 1;
  }
  return ::heal_up() + 1;
}

void leave()
{
    object me=query("pre_killer");
    tell_room(environment(),query("name")+"��ͬһ������ʧ�ˣ�\n");       
    destruct(this_object());
}


void heart_beat()
{  object guai = this_object();
   ::heart_beat();
   
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
  
}    
