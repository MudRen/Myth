#include "herb.h"

void create()
{
        set_name(HIW "�˲�" NOR, ({ "ren shen", "ren", "shen", "herb_renshen" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "�˲�����Ϊ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 10000);
                set("base_weight", 90);
        }
        setup();
}

