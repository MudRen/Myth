#include <weapon.h>

inherit FORK;

void create()
{
      set_name("�Źɲ�", ({"jiu gu cha", "fork", "cha"}));
      set_weight(8000);

      if( clonep() )
        set_default_object(__FILE__);
      else 
        {
        set("unit", "��");
        set("long", "һ�������ľŹ�����棬�Ͽ̣����Ź�����棬����ǧ���ٽ�����������ƣ���\n");
        set("value", 100000);
        set("no_give","���ֱ������������ˣ�\n");
        set("no_sell","�ƹ��ҡҡͷ˵������������ı�����С�겻���ա�\n");
        set("material", "gold");
        set("wield_msg", "$N��һ��������ǧ���$n����������\n");
        set("unwield_msg", "$N�����е�$n����������\n");
        set("weapon_prop/dodge", -20);
        set("weapon_prop/fork", -20);
        }
        init_fork(30);
        setup();
}


