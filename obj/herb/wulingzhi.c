#include "herb.h"

void create()
{
        set_name(NOR + MAG "����֬" NOR, ({ "wu lingzhi", "wu", "lingzhi", "herb_wulingzhi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + MAG "����֬�ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 5000);
                set("base_weight", 100);
        }
        setup();
}

