#include "herb.h"

void create()
{
        set_name(NOR + MAG "����" NOR, ({ "ling xian", "ling", "xian", "herb_lingxian" }));
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

