#include "herb.h"

void create()
{
        set_name(NOR + GRN "ɽ��" NOR, ({ "shan jia", "shan", "jia", "herb_shanjia" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + GRN "ɽ���ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "Ƭ");
                set("value", 2000);
                set("base_weight", 60);
        }
        setup();
}

