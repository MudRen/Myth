#include "herb.h"

void create()
{
        set_name(HIW "����" NOR, ({ "ru xiang", "ru", "xiang", "herb_ruxiang" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "�����ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 5000);
                set("base_weight", 50);
        }
        setup();
}

