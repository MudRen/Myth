#include "herb.h"

void create()
{
        set_name(HIR "�컨" NOR, ({ "hong hua", "hong", "hua", "herb_honghua" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIR "�컨�ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 80);
                set("base_weight", 20);
        }
        setup();
}

