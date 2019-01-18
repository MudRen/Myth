// blade.c 
        
#include <ansi.h> 
#include <weapon.h> 
        
       inherit BLADE; 
        
       void create() 
       { 
              set_name( HIR "轩辕魔刀" NOR, ({ "xuanyuan dao", "dao" }) ); 
              set_weight(4000); 
              if( clonep() ) 
                      set_default_object(__FILE__); 
              else { 
                      set("unit", "柄"); 
                      set("value", 100000); 
                      set("material", "iron"); 
                      set("long", "一柄散发着妖气的魔刀，据说刀身浸染过群魔的鲜血！\n"); 
                      set("wield_msg", "一股妖气夹杂在血腥中，$n已经握在$N手中，！。\n"); 
                      set("unequip_msg", "$N将$n插入背后的刀鞘。妖气渐渐散去！\n"); 
                                      set("no_sell",1); 
                                      set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n"); 
                                      set("no_give","魔刀不能易主！\n"); 
      } 
              init_blade(105); 
              setup(); 
      } 
