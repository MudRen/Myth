#include "herb.h"

void create()
{
        set_name(NOR + WHT "ɽ��" NOR, ({ "shan cha", "chan", "cha", "herb_shancha" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "ɽ���ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 200);
                set("base_weight", 20);
        }
        setup();
}

