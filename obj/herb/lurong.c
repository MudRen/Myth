#include "herb.h"

void create()
{
        set_name(NOR + YEL "¹��" NOR, ({ "lu rong", "lu", "rong", "herb_lurong" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + YEL "��¹���׽ǣ�������ҩ���ǳ�������\n" NOR);
                set("base_unit", "��");
                set("value", 8000);
                set("base_weight", 150);
        }
        setup();
}

