/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
// Update by waiwai@2001/04/17

#include <ansi.h>
inherit NPC; 
inherit F_VENDOR;  
void create() 
{
        set_name(WHT "���ϰ�" NOR, ({"ding boss", "ding", "boss"}));
        set("long", "�����������ļ��̡�\n");
        set("gender", "����");
        set("title", WHT"��������"NOR);
         set("combat_exp", 10000000);
        set("age", 36);
        set("max_kee", 4000);
          set("force_sen", 100);
        set("force_kee", 100);
        set("max_gin", 4000);
         set("max_sen", 4000);
       set("food", 1000);
      set("water", 1000);
         set("max_gin", 4000);
        set("attitude", "friendly");
        set("shen_type", 1);           
    set_skill("unarmed", 600);        
 set_skill("dodge", 500);         
set_skill("parry", 500);      
   set_skill("spells", 1000); 	
set_skill("baguazhou", 1000);    
     set_skill("literate", 500);   
      set_skill("sword", 600);     
      set_skill("changquan", 500);  
          map_skill("spells", "baguazhou"); 
        map_skill("unarmed", "changquan"); 
         set("per", 30);       
  set("max_kee", 4000);     
    set("max_gin", 4000);      
   set("max_sen", 4000);     
    set("force", 4500);       
  set("max_force", 3000);       
  set("force_factor", 100);       
  set("mana", 6000);         
set("max_mana", 3000);       
  set("mana_factor", 100);      
  set("vendor_goods", ([  
               "shoe": "/d/obj/cloth1/shoe", 
                "shoes1": "/d/obj/cloth1/shoes1", 
                 "sanhua": "/d/obj/cloth1/sanhua",
                 "sppifeng": "/d/obj/cloth1/sppifeng",
                 "jinjia": "/d/obj/cloth1/jinjia",   
              "tiekui": "/d/obj/cloth1/tiekui",     
            "zhanpao": "/d/obj/cloth1/zhanpao",     
                        "dun": "/d/obj/cloth1/shield",   
     ]) );         
setup();       
  carry_object("/d/obj/cloth/choupao")->wear();  } 
void init() {    
     object ob;     
     ::init();      
   if( interactive(ob = this_player()) && !is_fighting() ) { 
                remove_call_out("greeting");      
           call_out("greeting", 1, ob);       
  }         
add_action("do_vendor_list", "list"); 
}  
void greeting(object ob) {         
if( !ob || !visible(ob) || environment(ob) != environment() ) return;    
     switch( random(1) ) {      
           case 0:      
                   say(name()+ CYN+"Ц���е�ӭ��������λ" + RANK_D->query_respect(ob)
                                 + "����㿴����\n"+NOR);      
                   break;   
      } 
}  
