#include "herb.h"

void create()
{
        set_name(NOR + WHT "��β" NOR, ({ "gui wei", "gui", "wei", "herb_guiwei" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "��β�ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 3000);
                set("base_weight", 50);
        }
        setup();
}

