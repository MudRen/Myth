#include "herb.h"

void create()
{
        set_name(NOR + MAG "����" NOR, ({ "tao xian", "tao", "xian", "herb_taoxian" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + MAG "�����ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 5000);
                set("base_weight", 40);
        }
        setup();
}

