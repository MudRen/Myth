#include "herb.h"

void create()
{
        set_name(NOR + YEL "���" NOR, ({ "yang jinhua", "yang", "jinhua", "herb_yjhua" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + YEL "����ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 400);
                set("base_weight", 20);
        }
        setup();
}


