#include "herb.h"

void create()
{
        set_name(HIW "����" NOR, ({ "yan wo", "yan", "wo", "herb_yanwo" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "ѩ�����ͱ����Ƶ��ѳ������Ǽ�Ϊ�������ҩҩ�ġ�\n");
                set("base_unit", "��");
                set("value", 50000);
                set("base_weight", 35);
        }
        setup();
}

