#include "herb.h"

void create()
{
        set_name(HIY "���" NOR, ({ "da huang", "da", "huang", "herb_dahuang" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "�������Ϊ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 7000);
                set("base_weight", 100);
        }
        setup();
}

