#include <weapon.h>

inherit SPEAR;

void create()
{
      set_name("���˷����", ({"hua gan ji", "huaji", "ji"}));
      set_weight(8000);

      if( clonep() )
        set_default_object(__FILE__);
      else 
        {
        set("unit", "��");
        set("long", "һ�����컭ꪣ��Ͽ̣������˷���ꪣ�����ǧ���ٽ�����������ƣ���\n");
        set("value", 400000);
        set("no_give","���ֱ������������ˣ�\n");
        set("no_sell","�ƹ��ҡҡͷ˵������������ı�����С�겻���ա�\n");
        set("material", "gold");
        set("wield_msg", "$N���Ӿ��񣬴��һ�����𣡾���$n��\n");
        set("unwield_msg", "$N�����е�$n����������\n");
        set("weapon_prop/dodge", -60);
        set("weapon_prop/spear", -60);
        }
        init_spear(30);
        setup();
}


