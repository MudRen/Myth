//Cracked by Roath
// �����  


#include <weapon.h>

inherit "/d/obj/weapon/sword/anqi_container.c";

void create()
{
   set_name("�����", ({"fenghuang qin","qin","sword"}));
   set_weight(4000);
   if( clonep() ) 
          set_default_object(__FILE__);
   else 
     {
      set("long", "һ����ɫ���ɵĹ��٣�������ֻ����ķ�ˣ�����ȥ��˵Ҳ���ϰ���ı����ˡ�\n");
      set("orilong", "һ����ɫ���ɵĹ��٣�������ֻ����ķ�ˣ�����ȥ��˵Ҳ���ϰ���ı����ˡ�\n");
      set("unit", "��");
      set("value", 20000);
      set("material", "leather");
      set("wield_msg", "$N�ӱ���ժ��һ��$n���������С�\n");
      set("unwield_msg", "$N�������е�$n��С������ı��ر���\n");
      set("anqi/allow", 1);
      set("anqi/max", 40);
      set("anqi/now", 0);
      set("music/type", "qin");
     }
     init_sword(65);
     setup();
}

