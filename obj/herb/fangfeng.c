#include "herb.h"

void create()
{
        set_name(NOR + HIB "����" NOR, ({ "fang feng", "fang", "feng", "herb_fangfeng" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + HIB "�����ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "Ƭ");
                set("value", 5000);
                set("base_weight", 40);
        }
        setup();
}

