

#include <weapon.h>

inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(HIY"б�����ǽ�"NOR, ({"longxing jian","sword","jian"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("long","����ɽ��ɽ֮�����ഫΪ������ʦ��ʥ�\n");
                set("unit", "��");
                set("value", 12000);
                set("wield_msg",HIW "$N˫��һ�ӣ����������������һ���������������\n"NOR);
                set("unwield_msg",HIW "$N���б���ͻȻ����һ������,�������...\n");
                set("no_sell","�����������ɣ��ⶫ���㶼������\n"); 
                set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n"); 
                set("weapon_prop/courage", 20);
        }
        init_sword(120);
        setup();
}

mixed hit_ob(object me, object victim)
{
        int damage_bonus = 0;
        if( (string)me->query("family/family_name") == "����ɽ���Ƕ�"
          && me->query_skill("liangyi-sword",1) > 1)
        damage_bonus = me->query_skill("liangyi-sword",1);
        damage_bonus = (damage_bonus+random(damage_bonus))/2;
        
        victim->receive_wound("kee",damage_bonus);
        return HIR"б�����ǽ��ϱŷ���ҫ�۵Ļ�⡣\n" NOR;

}

