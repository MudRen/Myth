#include "herb.h"

void create()
{
        set_name(NOR + WHT "����" NOR, ({ "sheng di", "sheng", "di", "herb_shengdi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "�����ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 500);
                set("base_weight", 60);
        }
        setup();
}

