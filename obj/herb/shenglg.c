#include "herb.h"

void create()
{
        set_name(NOR + CYN "������" NOR, ({ "sheng longgu", "sheng", "longgu", "herb_shenglg" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + CYN "����Ĺ��磬���ǳ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 4000);
                set("base_weight", 120);
        }
        setup();
}

