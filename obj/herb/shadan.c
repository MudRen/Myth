#include "herb.h"

void create()
{
        set_name(NOR + HIB "�赨" NOR, ({ "sha dan", "sha", "dan", "herb_shadan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + HIB "��������ĵ��࣬�Ƿǳ��������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 10000);
                set("base_weight", 35);
        }
        setup();
}

