#include "herb.h"

void create()
{
        set_name(NOR + RED "Ѫ��" NOR, ({ "xue jie", "xue", "jie", "herb_xuejie" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + RED "Ѫ���ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 200);
                set("base_weight", 40);
        }
        setup();
}

