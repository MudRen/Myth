#include "herb.h"

void create()
{
        set_name(HIY "�ٻ�" NOR, ({ "teng huang", "teng", "huang", "herb_tenghuang" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "�ٻ��ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 5000);
                set("base_weight", 50);
        }
        setup();
}

