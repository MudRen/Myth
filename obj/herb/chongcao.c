#include "herb.h"

void create()
{
        set_name(NOR + HIB "�����Ĳ�" NOR, ({ "chong cao", "chong", "cao", "herb_chongcao" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + HIB "��Ϊ�棬��Ϊ�ݡ����Ǽ�Ϊ�������ҩҩ�ġ�\n" NOR);
                set("base_unit", "��");
                set("value", 10000);
                set("base_weight", 85);
        }
        setup();
}

