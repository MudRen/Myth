#include <weapon.h>

inherit HAMMER;

void create()
{
      set_name("����÷��������", ({"mei hua chui", "hammer", "chui"}));
      set_weight(8000);

      if( clonep() )
        set_default_object(__FILE__);
      else 
        {
        set("unit", "��");
        set("long", "һ�����������Ͽ̣�������÷��������������ǧ�İٽ�����������ƣ���\n");
        set("value", 100000);
        set("no_give","���ֱ������������ˣ�\n");
        set("no_sell","�ƹ��ҡҡͷ˵������������ı�����С�겻���ա�\n");
        set("material", "gold");
        set("wield_msg", "$N������������$n����������\n");
        set("unwield_msg", "$N�����е�$n����������\n");
        set("weapon_prop/dodge", -40);
        set("weapon_prop/hammer", -40);
        }
        init_hammer(30);
        setup();
}


