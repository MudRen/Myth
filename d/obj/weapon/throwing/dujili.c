#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("������", ({"poison dart", "dart"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("base_unit", "֦");
		set("long", "�������������ޱȣ�����������ɫ������ι�˶�ҩ��\n");
                set("base_weight", 40);
		set("value", 20);
                set("base_value", 1);
        }
        set_amount(20);
        init_throwing(15);
        setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 0 ) return 0;
	victim->apply_condition("root_poison", 3);
	message_vision("$N���˶������ϵ��«�ݶ���\n", victim);
}

