//������


#include <weapon.h>
inherit STICK;
#include <ansi.h>

void create()
{
        set_name(HIG"������"NOR, ({"puti zhang","stick","bang"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("long","һ�ѵ���ɫ����������ֻ��壬����Щ������\n");
                set("unit", "��");
                set("value", 12000);
                set("wield_msg",HIW "$N��ľ��������Ȼ����ӱ�������\n"NOR);
                set("unwield_msg",HIW "$N��ھ�,�����Ȼ�Ϊһ������,��������ʧ��!\n");
                set("no_sell","�����������ɣ��ⶫ���㶼������\n"); 
                set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n"); 
                set("weapon_prop/courage", 20);
        }
        init_stick(120);
        setup();
}

mixed hit_ob(object me, object victim)
{
        int damage_bonus = 0;    
        if( (string)me->query("family/family_name") == "����ɽ���Ƕ�"
                 && me->query_skill("qianjun-bang",1) > 1)
        damage_bonus = me->query_skill("qianjun-bang",1);
        damage_bonus = (damage_bonus+random(damage_bonus))/2;
        victim->receive_wound("kee",damage_bonus);
        return HIB"������������һ˿�����̹⡣\n" NOR;

}

