    //��Į��Ӱ
    //by dewbaby@sk

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
       set_name(WHT"��Į��Ӱ"NOR,({"guying sword","guying","sword"}));
        set_weight(20000);
       if( clonep() )
              set_default_object(__FILE__);
       else {
            set("unit","��");
            set("value",12000);
            set("material","silver");
            set("long",WHT"һ��ɢ����˿˿ɱ������籦������������ɽ����ɽ֮����\n"NOR);
            set("wield_msg",WHT"$N����һ�ӣ�ֻ��һ����Ӱ��ಡ���һ�������׹��$N���С�\n"NOR);
            set("unwield_msg",WHT"$N΢��˫�ۣ����װ�Ȼ��ע�������ܡ�$n"WHT"ȴ���ѻ�Ϊһ�����������ʧ����!\n"NOR);
            set("no_sell","������������? �ⶫ����Ҳ����? \n"NOR);
            set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n"NOR);
            set("weapon_prop/courage",20);
     }
       init_sword(130);
       setup();
   }
/*
mixed hit_ob(object me, object victim)  
{
         int damage_bonus = 0;  

        if( (string)me->query("family/family_name") == "����ɽ"  
                       && me->query_skill("huxiaojian",1) > 1)  
                damage_bonus = me->query_skill("huxiaojian",1);  
                damage_bonus = (damage_bonus+random(damage_bonus))/2;  

                 victim->receive_wound("kee",damage_bonus);  
                return HIB"��Į��Ӱ������ȣ��ڷ���������! \n" NOR;  
        }
*/
