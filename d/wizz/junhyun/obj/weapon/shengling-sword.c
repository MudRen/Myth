//zhaoyaojian.c 
#include <ansi.h> 
#include <weapon.h> 
        
       inherit SWORD; 
        
       void create() 
       { 
           set_name( WHT "ʥ�鱦��" NOR, ({ "shengling jian", "jian","sword" }) ); 
          set_weight(4000); 
              if( clonep() ) 
                      set_default_object(__FILE__); 
              else { 
                      set("unit", "��"); 
                      set("value", 100000); 
      //              set("no_drop", "1"); 
                      set("material", "iron"); 
                      set("long", "��˵��Ů洵��������ʲ���ʯ���죬�����ޱȡ�\n"); 
                      set("wield_msg","$NĬ���ľ���$n�������԰�Χ����$N����ߡ�\n"); 
                      set("unwield_msg", "$N����һָ��$n��������������С�\n"); 
                                      set("no_sell",1); 
                                      set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n"); 
                                      set("no_give","������������!\n"); 
                      } 
              init_sword(120); 
              setup(); 
      } 
