#include "herb.h"

void create()
{
        set_name(NOR + CYN "���" NOR, ({ "chai hu", "chai", "hu", "herb_chaihu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + CYN "����ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 4000);
                set("base_weight", 60);
        }
        setup();
}

