#include "herb.h"

void create()
{
        set_name(NOR + YEL "��Ƥ" NOR, ({ "chen pi", "chen", "pi", "herb_chenpi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + YEL "��Ƥ�ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 10);
                set("base_weight", 20);
        }
        setup();
}

