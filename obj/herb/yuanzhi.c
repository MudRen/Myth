#include "herb.h"

void create()
{
        set_name(NOR + HIB "Զ־" NOR, ({ "yuan zhi", "yuan", "zhi", "herb_yuanzhi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + HIB "Զ־�ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 3000);
                set("base_weight", 75);
        }
        setup();
}

