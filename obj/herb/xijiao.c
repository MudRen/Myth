#include "herb.h"

void create()
{
        set_name(NOR + WHT "Ϭ��" NOR, ({ "xi jiao", "xi", "jiao", "herb_xijiao" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "Ϭţ�Ľǣ�ҩ��ǿ�ң����������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 10000);
                set("base_weight", 35);
        }
        setup();
}

