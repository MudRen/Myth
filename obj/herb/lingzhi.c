#include "herb.h"

void create()
{
        set_name(HIG "��֥" NOR, ({ "ling zhi", "ling", "zhi", "herb_lingzhi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "��֥����Ϊ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 20000);
                set("base_weight", 70);
        }
        setup();
}

