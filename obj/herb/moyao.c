#include "herb.h"

void create()
{
        set_name(NOR + WHT "ûҩ" NOR, ({ "mo yao", "mo", "yao", "herb_moyao" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "ûҩ�ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 300);
                set("base_weight", 50);
        }
        setup();
}

