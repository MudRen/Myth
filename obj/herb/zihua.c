#include "herb.h"

void create()
{
        set_name(NOR + MAG "�ϻ�" NOR, ({ "zi hua", "zi", "hua", "herb_zihua" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + MAG "�ϻ��ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 50);
                set("base_weight", 20);
        }
        setup();
}

