#include "herb.h"

void create()
{
        set_name(HIY "���" NOR, ({ "ma huang", "ma", "huang", "herb_mahuang" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "����ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 1000);
                set("base_weight", 50);
        }
        setup();
}

