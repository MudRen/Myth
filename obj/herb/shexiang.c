#include "herb.h"

void create()
{
        set_name(HIM "����" NOR, ({ "she xiang", "she", "xiang", "herb_shexiang" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIM "ɢ����Ũ����ζ�����㣬������ҩ��\n" NOR);
                set("base_unit", "��");
                set("value", 10000);
                set("base_weight", 50);
        }
        setup();
}

