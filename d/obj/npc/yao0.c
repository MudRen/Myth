
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit NPC;

void init_skill(int exp,int skillmax,int max_kee,int max_force,int max_sen,int max_mana,string type);
int my_randommove();
//int bian();

void create()
{
   set_name("Ұ���", ({"yezhu guai"}) );
   if(random(2)) set("gender", "����" );
   else set("gender","Ů��" );
   
   set("age", 30);
   set("long", "\n");
   set("attitude", "heroism");

   set("chat_chance_combat", 50);

   set("str", 40);
   set("cor", 25);
   set("cps", 25);
   set("int", 25);
   set("chat_chance",20);
   set("chat_msg", ({
      (: my_randommove :),
  //    (: bian :),
        }));

    setup();
    add_money("silver",50);
}

void init_skill(int exp,int skillmax,int max_kee,int max_force,int max_sen,int max_mana,string type)
{
        object weap;
        
 if(type=="mo")
 switch(random(4)){
        case 0:
            set("chat_msg_combat", ({
//                 (: perform_action, "stick.leiting" :),
                 (: cast_spell, "thunder" :),
             }));
  
             set_skill("stick",skillmax+random(skillmax/10));
             set_skill("unarmed",skillmax+random(skillmax/10));
             set_skill("puti-zhi",skillmax+random(skillmax/10));
             set_skill("qianjun-bang",skillmax+random(skillmax/10));
             set_skill("spells",skillmax+random(skillmax/10));
             set_skill("dao",skillmax+random(skillmax/10));
             set_skill("dodge",skillmax+random(skillmax/10));
             set_skill("jindouyun",skillmax+random(skillmax/10));
             set_skill("force",skillmax+random(skillmax/10));
             set_skill("wuxiangforce",skillmax+random(skillmax/10));
             map_skill("force","wuxiangforce");
             map_skill("spells", "dao");
             map_skill("stick", "qianjun-bang");
             set_skill("parry",skillmax+random(skillmax/10));
             map_skill("parry", "qianjun-bang");
             map_skill("unarmed","puti-zhi");
             map_skill("dodge", "jindouyun");
             weap=new("/d/lingtai/obj/bang.c");
             weap->move(this_object());
             weap->wield();
             break;
         case 1:
           set("class","xian");
           set_skill("sword",skillmax+random(skillmax/10));
           set_skill("snowsword",skillmax+random(skillmax/10));
           set_skill("spells",skillmax+random(skillmax/10));
           set_skill("unarmed",skillmax+random(skillmax/10));
           set_skill("baihua-zhang",skillmax+random(skillmax/10));
           set_skill("moonshentong",skillmax+random(skillmax/10));
           set_skill("dodge",skillmax+random(skillmax/10));
           set_skill("moondance",skillmax+random(skillmax/10));
           set_skill("moonforce",skillmax+random(skillmax/10));
           
           map_skill("unarmed","baihua-zhang");
           map_skill("spells", "moonshentong");
           map_skill("sword", "snowsword");
           set_skill("parry",skillmax+random(skillmax/10));
           map_skill("parry", "snowsword");
           map_skill("dodge", "moondance");
           map_skill("force","moonforce");

           weap=new("/d/obj/weapon/sword/changjian.c");
           weap->move(this_object());
           weap->wield();   
           break;
  
           case 2:
           set("chat_msg_combat", ({
           (: perform_action, "staff.shenlong" :),
           }));

           set_skill("staff",skillmax+random(skillmax/10));
           set_skill("lunhui-zhang",skillmax+random(skillmax/10));
           set_skill("spells",skillmax+random(skillmax/10));
           set_skill("buddhism",skillmax+random(skillmax/10));
           set_skill("dodge",skillmax+random(skillmax/10));
           set_skill("lotusmove",skillmax+random(skillmax/10));
           set_skill("lotusforce",skillmax+random(skillmax/10));
           set_skill("unarmed",skillmax+random(skillmax/10));
           set_skill("jienan-zhi",skillmax+random(skillmax/10));
     
           map_skill("spells", "buddhism");
           map_skill("staff", "lunhui-zhang");
           set_skill("parry",skillmax+random(skillmax/10));
           map_skill("parry", "lunhui-zhang");
           map_skill("dodge", "lotusmove");
           map_skill("force","lotusforce");
           map_skill("unarmed","jienan-zhi");
           weap=new("/d/obj/weapon/staff/muzhang.c");
           weap->move(this_object());
           weap->wield();   
           break;

           case 3:
           set("class","dragon");
           set("chat_msg_combat", ({
            (: perform_action, "hammer.break" :),
            (: cast_spell, "freez" :),
           }));
         
           set_skill("hammer",skillmax+random(skillmax/10));
           set_skill("huntian-hammer",skillmax+random(skillmax/10));
           set_skill("spells",skillmax+random(skillmax/10));
           set_skill("seashentong",skillmax+random(skillmax/10));
           set_skill("dodge",skillmax+random(skillmax/10));
           set_skill("dragonstep",skillmax+random(skillmax/10));
           set_skill("dragonforce",skillmax+random(skillmax/10));
           set_skill("unarmed",skillmax+random(skillmax/10));
           set_skill("dragonfight",skillmax+random(skillmax/10));

           map_skill("spells", "seashentong");
           map_skill("hammer", "huntian-hammer");

           set_skill("parry",skillmax+random(skillmax/10));
           map_skill("parry", "huntian-hammer");
           map_skill("dodge", "dragonstep");
           map_skill("force", "dagonforce");
           map_skill("unarmed","dragonfight");
           weap=new("/d/obj/weapon/hammer/hammer.c");
           weap->move(this_object());
           weap->wield();   
           break;
       }
  else
    switch(random(3)){    
           case 0:
           set("chat_msg_combat", ({
           (: perform_action, "sword.toulin" :),
         }));

           set_skill("sword",skillmax+random(skillmax/10));
           set_skill("bainiao-jian",skillmax+random(skillmax/10));
           set_skill("spells",skillmax+random(skillmax/10));
           set_skill("dodge",skillmax+random(skillmax/10));
           set_skill("xiaoyaoyou",skillmax+random(skillmax/10));
           set_skill("ningxie-force",skillmax+random(skillmax/10));     
           set_skill("unarmed",skillmax+random(skillmax/10));    
           set_skill("yingzhaogong",skillmax+random(skillmax/10));

           map_skill("spells", "dengxian-dafa");
           map_skill("sword", "bainiao-jian");
           set_skill("parry",skillmax+random(skillmax/10));
           map_skill("parry", "bainiao-jian");
           map_skill("dodge", "xiaoyaoyou");
           map_skill("force","ningxie-force");  
           map_skill("unarmed","yingzhaogong");
           
           weap=new("/d/obj/weapon/sword/changjian.c");
           weap->move(this_object());
           weap->wield();   
           break;

         case 1: 
        
          set_skill("whip",skillmax+random(skillmax/10));
          set_skill("hellfire-whip",skillmax+random(skillmax/10));
          set_skill("spells",skillmax+random(skillmax/10));
          set_skill("gouhunshu",skillmax+random(skillmax/10));
          set_skill("dodge",skillmax+random(skillmax/10));
          set_skill("ghost-steps",skillmax+random(skillmax/10));
          set_skill("tonsillit",skillmax+random(skillmax/10));
          set_skill("jinghun-zhang",skillmax+random(skillmax/10));
          set_skill("kusang-bang",skillmax+random(skillmax/10));
          set_skill("unarmed",skillmax+random(skillmax/10));
          set_skill("jinghun-zhang",skillmax+random(skillmax/10));

          map_skill("spells", "gouhunshu");
          map_skill("whip", "hellfire-whip");
          set_skill("parry",skillmax+random(skillmax/10));
          map_skill("parry", "hellfire-whip");
          map_skill("dodge", "ghost-steps");
          map_skill("force", "tonsillit");
          map_skill("unarmed","jinghun-zhang");
          weap=new("/d/obj/weapon/whip/whip.c");
          weap->move(this_object());
          weap->wield();                       
          break;                     

           case 2:

            set("chat_msg_combat", ({
            (: cast_spell, "huanying" :),
            }));

           set_skill("blade",skillmax+random(skillmax/10));
           set_skill("kugu-blade",skillmax+random(skillmax/10));
           set_skill("unarmed",skillmax+random(skillmax/10));
           set_skill("yinfeng-zhua",skillmax+random(skillmax/10));
           set_skill("spells",skillmax+random(skillmax/10));
           set_skill("dodge",skillmax+random(skillmax/10));
           set_skill("lingfu-steps",skillmax+random(skillmax/10));
           set_skill("huntian-qigong",skillmax+random(skillmax/10));
           set_skill("yaofa", skillmax+random(skillmax/10));
           map_skill("spells", "yaofa");
           map_skill("blade", "kugu-blade");
           map_skill("dodge", "lingfu-steps");
           map_skill("force","huntian-qigong");
           map_skill("unarmed","yinfeng-zhua");
           weap=new("/d/obj/weapon/blade/blade.c");
           weap->move(this_object());
           weap->wield();
           break;

           case 3:
           

         set("chat_msg_combat", ({
              (: perform_action, "stick.pili" :),
            (: cast_spell, "thunder" :),
         }));

           set_skill("stick",skillmax+random(skillmax/10));
           set_skill("qianjun-bang",skillmax+random(skillmax/10));
           set_skill("dodge",skillmax+random(skillmax/10));
           set_skill("unarmed",skillmax+random(skillmax/10));
           set_skill("wuxing-quan",skillmax+random(skillmax/10));
           set_skill("xiaoyaoyou",skillmax+random(skillmax/10));
           set_skill("throwing",skillmax+random(skillmax/10));
           set_skill("huntian-qigong",skillmax+random(skillmax/10));
           set_skill("yaofa", skillmax+random(skillmax/10));
           map_skill("dodge", "xiaoyaoyou");
           map_skill("force","huntian-qigong");
           map_skill("unarmed","wuxing-quan");
           map_skill("stick","qianjun-bang");
           weap=new("/d/lingtai/obj/bang.c");
           weap->move(this_object());
           weap->wield();
           break;

  }       

   max_kee=5*max_kee/4;
   max_sen=max_sen*2;
   set("max_kee",max_kee);
   set("kee",max_kee);
   set("eff_kee",max_kee);
   set("max_sen",max_sen);
   set("eff_sen",max_sen);
   set("sen",query("max_sen"));
   if (max_mana<30*skillmax/2) max_mana=25*skillmax/2;
   set("max_force", max_force);
   set("force",  query("max_force"));
   set("force_factor", query("max_force")/15 );
   set("mana_factor", query("max_mana")/10 );
   set("max_mana",  max_mana);
   set("mana",  query("max_mana")*2);
   set("combat_exp", exp*2 );
   set("daoxing", exp*2 );
   set_temp("apply/armor",200+exp/50000);
   set_temp("apply/damage", 20+exp/100000);

   set("new_time",time());
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
 
   return ;
}


void unconcious()
{
   die();
}

void die()
{
   object killer,me,owner;
   int reward,index;
   string location;
   mapping skill_status;
   string* sname;
   
   command("say ���������ơ�");
   tell_room(environment(),"˵�꣬"+query("name")+"������һ�꣬��ʧ�ˡ�\n");
   owner = query("pre_killer");
   owner->add("m_mieyao",1);
     owner->add("m_win",1);
   
    if( objectp(killer = query_temp("last_damage_from")) ) {
      if(killer==query("pre_killer")&& killer->query("secmieyao/id") == query("id")){
          if(!killer->query("secmieyao"))killer->delete_temp("m_mieyao");
          killer->add("faith",1+random(2));
          killer->add("weiwang",1);
          reward=killer->query("combat_exp");
          if(reward>1000000){
             if(killer->query("mud_age")-killer->query("secmieyao_killedtime")>3600){
                if((int)killer->query_temp("m_mieyao"))killer->delete_temp("secmieyao_killed");
                killer->set("secmieyao_killedtime",killer->query("mud_age"));
             }else{     
                index=killer->query_temp("secmieyao_killed");
                index+=1;
                if(index==10){
                    killer->delete_temp("secmieyao_killed");
                    killer->set("secmieyao_killedtime",killer->query("mud_age"));
            killer->add("combat_exp",1000);
             killer->add("potential",300);
             tell_object(killer,"��ϲ��õ��˶���Ľ��͡�\n");                 
                }else killer->set_temp("secmieyao_killed",index);
             }
          }
          reward=reward/1000;
          if(reward>500)reward=500+random(300);
          killer->add("daoxing",reward);
           killer->add("potential",reward*2/5);
      killer->add("mieyao/menpai_reward/dh",reward);
      killer->add("mieyao/menpai_reward/pot",reward*2/5);
      killer->add("mieyao/menpai_num/",1);
        killer->set("menpai_task",99);
          tell_object(killer,"��ϲ��õ��˽��ͣ���ĵ��к�Ǳ������ˡ�\n");
      }
   }

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

int my_randommove()
{
   mapping exits;
   string *dirs;
   string ldir;
   string* loclist;
   string* loclist2;
   int size; 

   if( !mapp(exits = environment()->query("exits")) ) return 0;
   dirs = keys(exits);
   size=sizeof(dirs);
   if(size>0){
     ldir=dirs[random(size)];
     loclist=explode(exits[ldir],"/");
     loclist2=explode(file_name(environment()),"/");
     if(loclist[sizeof(loclist)-2]==loclist2[sizeof(loclist2)-2])
       return command("go " + ldir);
   }
   return 0;
}/*
int bian()
{
        object *inv;
        inv=all_inventory(environment());
        if( this_object()->query_temp("apply/name") ) return 0;
        if(sizeof(inv)<=1) return 0;
        command("bian "+inv[random(sizeof(inv))]->query("id"));
        return 1;

}
*/
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
