#include "herb.h"

void create()
{
        set_name(NOR + WHT "��ľ" NOR, ({ "su mu", "su", "mu", "herb_sumu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "��ľ�ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 5000);
                set("base_weight", 60);
        }
        setup();
}

