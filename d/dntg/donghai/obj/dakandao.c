#include <weapon.h>

inherit BLADE;

void create()
{
      set_name("�󿳵�", ({"da kan dao", "blade", "dao"}));
      set_weight(8000);
      if( clonep() )
        set_default_object(__FILE__);
      else 
        {
        set("unit", "��");
        set("long", "һ�Ѵ󿳵��������Ϲ���ʮ�����󻷡�\n");
        set("value", 50000);
        set("no_give","���ֱ������������ˣ�\n");
        set("no_sell","�ƹ��ҡҡͷ˵������������ı�����С�겻���ա�\n");
        set("material", "gold");
        set("wield_msg", "$N���һ����$n�������С�\n");
        set("unwield_msg", "$N�����е�$n���ڱ���\n");
        set("weapon_prop/dodge", -10);
        set("weapon_prop/blade", -10);
        }
        init_blade(30);
        setup();
}


