#include "herb.h"

void create()
{
        set_name(NOR + WHT "����" NOR, ({ "chuan wu", "chuan", "wu", "herb_chuanwu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "�����ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 200);
                set("base_weight", 50);
        }
        setup();
}

