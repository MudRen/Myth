#include "herb.h"

void create()
{
        set_name(NOR + HIB "����" NOR, ({ "lan hua", "lan", "hua", "herb_lanhua" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + HIB "�����ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 500);
                set("base_weight", 20);
        }
        setup();
}

