#include "herb.h"

void create()
{
        set_name(HIW "����" NOR, ({ "hu gu", "hu", "gu", "herb_hugu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "���껢�Ĺ�ͷ��ҩ��ǿ�ң��Ƿǳ��������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 12000);
                set("base_weight", 100);
        }
        setup();
}

