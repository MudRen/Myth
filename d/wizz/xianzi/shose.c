      // shoes.c 
       
#include <armor.h> 
#include <ansi.h> 
       
      inherit BOOTS; 
       
       
      void create() 
      { 
              set_name(HIY "牡丹绣鞋" NOR, ({ "shoes" }) ); 
              set_weight(900); 
              if( clonep() ) 
                      set_default_object(__FILE__); 
              else { 
                      set("long", "一双精致的小鞋，上面绣着一朵盛开的"HIY"黄牡丹"NOR"。  \n"); 
                      set("material", "cloth"); 
                      set("unit", "双"); 
                      set("armor_prop/armor", 1 ); 
                      set("female_only", 1); 
       set("wear_msg","$N穿上一双别致的绣花鞋，又小心的把脚收到裙子下。 只是那一瞬间，你看到了绣鞋上那朵盛开的"HIY"牡丹花\n");  
      set("unequip_msg", "$N脱下"HIY"小绣鞋"NOR"，突然发现你正痴痴地望着她的脚，不由地脸上飞起一抹"HIR"红云"NOR"。\n");  

              } 
              setup(); 
      } 
       
       
                  int query_autoload() { return 1; }  

