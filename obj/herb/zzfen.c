#include "herb.h"

void create()
{
        set_name(HIW "�����" NOR, ({ "zhenzhu fen", "zhenzhu", "fen", "herb_zzfen" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "����ĥ�ɵķ�ĩ��ҩ���ºͣ���������֮����\n" NOR);
                set("base_unit", "��");
                set("value", 10000);
                set("base_weight", 30);
        }
        setup();
}

