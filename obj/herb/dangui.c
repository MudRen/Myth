#include "herb.h"

void create()
{
        set_name(HIG "����" NOR, ({ "dang gui", "dang", "gui", "herb_dangui" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "�����ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 1000);
                set("base_weight", 70);
        }
        setup();
}

