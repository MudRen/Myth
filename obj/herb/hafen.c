#include "herb.h"

void create()
{
        set_name(NOR + RED "���" NOR, ({ "ha fen", "ha", "fen", "herb_hafen" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + RED "����ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 5000);
                set("base_weight", 50);
        }
        setup();
}

