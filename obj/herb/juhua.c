#include "herb.h"

void create()
{
        set_name(HIY "�ջ�" NOR, ({ "ju hua", "ju", "hua", "herb_juhua" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "�ջ��ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 60);
                set("base_weight", 20);
        }
        setup();
}

