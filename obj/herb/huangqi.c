#include "herb.h"

void create()
{
        set_name(NOR + YEL "����" NOR, ({ "huang qi", "huang", "qi", "herb_huangqi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + YEL "�����ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 5000);
                set("base_weight", 35);
        }
        setup();
}

