#include "herb.h"

void create()
{
        set_name(NOR + CYN "��ʯ��" NOR, ({ "gan shiliu", "gan", "shiliu", "herb_gsliu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + CYN "��ʯ���ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "Ƭ");
                set("value", 200);
                set("base_weight", 75);
        }
        setup();
}

