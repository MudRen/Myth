       //jiujiani.c 
           //by dewbaby@skxy
 
#include <weapon.h>
#include <ansi.h>
       inherit SWORD; 

    void create()
       { 
          set_name(MAG"�Ž�����"NOR,({"jiu jian","jiujian"})); 
           set_weight(4000); 
              if( clonep() ) 
            set_default_object(__FILE__);
              else { 
                      set("unit","��"); 
                      set("value",4000000000); 
                      set("no_drop","1");
                      set("no_sell","1"); 
                      set("material","gold"); 
                      set("long",MAG"��˵���Ǿ�����Ů���񽣣�������ɢ����ҫ�۵Ĺ�â��\n"NOR); 
                      set("wield_msg",MAG"$N����һЦ��$n"MAG"�Ѿ���$N"MAG"�������С�һ������˲���Χ���㡣\n"NOR); 
                      set("unwield_msg",MAG"$N˫��΢�գ�գ�ۼ��ѽ�$n"MAG"������䡣\n"NOR); 
                      set("no_drop","���ǲ�Ҫ���ɣ�С�ľ�����ŮҪ�����С����\n"); 
                    } 
          init_sword(200); 
           setup();
      } 

