// blade.c 
        
#include <ansi.h> 
#include <weapon.h> 
        
       inherit BLADE; 
        
       void create() 
       { 
              set_name( HIR "��ԯħ��" NOR, ({ "xuanyuan dao", "dao" }) ); 
              set_weight(4000); 
              if( clonep() ) 
                      set_default_object(__FILE__); 
              else { 
                      set("unit", "��"); 
                      set("value", 100000); 
                      set("material", "iron"); 
                      set("long", "һ��ɢ����������ħ������˵�����Ⱦ��Ⱥħ����Ѫ��\n"); 
                      set("wield_msg", "һ������������Ѫ���У�$n�Ѿ�����$N���У�����\n"); 
                      set("unequip_msg", "$N��$n���뱳��ĵ��ʡ���������ɢȥ��\n"); 
                                      set("no_sell",1); 
                                      set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n"); 
                                      set("no_give","ħ������������\n"); 
      } 
              init_blade(105); 
              setup(); 
      } 
