#include "herb.h"

void create()
{
        set_name(NOR + HIB "����" NOR, ({ "du huo", "du", "huo", "herb_duhuo" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + HIB "�����ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 4000);
                set("base_weight", 50);
        }
        setup();
}

