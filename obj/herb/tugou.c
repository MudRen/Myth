#include "herb.h"

void create()
{
        set_name(NOR + YEL "����" NOR, ({ "tu gou", "tu", "gou", "herb_tugou" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + YEL "�����ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 8000);
                set("base_weight", 80);
        }
        setup();
}

