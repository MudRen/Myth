#include "herb.h"

void create()
{
        set_name(HIY "ţ��" NOR, ({ "niu huang", "niu", "huang", "herb_niuhuang" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "ţ���ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 1000);
                set("base_weight", 60);
        }
        setup();
}

