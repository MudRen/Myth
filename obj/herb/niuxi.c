#include "herb.h"

void create()
{
        set_name(NOR + CYN "ţϥ" NOR, ({ "niu xi", "niu", "xi", "herb_niuxi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + CYN "ţϥ�ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 2000);
                set("base_weight", 50);
        }
        setup();
}

