      // shoes.c 
       
#include <armor.h> 
#include <ansi.h> 
       
      inherit BOOTS; 
       
       
      void create() 
      { 
              set_name(HIY "ĵ����Ь" NOR, ({ "shoes" }) ); 
              set_weight(900); 
              if( clonep() ) 
                      set_default_object(__FILE__); 
              else { 
                      set("long", "һ˫���µ�СЬ����������һ��ʢ����"HIY"��ĵ��"NOR"��  \n"); 
                      set("material", "cloth"); 
                      set("unit", "˫"); 
                      set("armor_prop/armor", 1 ); 
                      set("female_only", 1); 
       set("wear_msg","$N����һ˫���µ��廨Ь����С�ĵİѽ��յ�ȹ���¡� ֻ����һ˲�䣬�㿴������Ь���Ƕ�ʢ����"HIY"ĵ����\n");  
      set("unequip_msg", "$N����"HIY"С��Ь"NOR"��ͻȻ���������ճյ��������Ľţ����ɵ����Ϸ���һĨ"HIR"����"NOR"��\n");  

              } 
              setup(); 
      } 
       
       
                  int query_autoload() { return 1; }  

