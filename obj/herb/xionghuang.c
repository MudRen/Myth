#include "herb.h"

void create()
{
        set_name(HIY "�ۻ�" NOR, ({ "xiong huang", "xiong", "huang", "herb_xionghuang" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "ҩ�Լ�ǿ����ҩҩ�ģ��������Ͽ��Է�ֹ�߳漰��\n" NOR);
                set("base_unit", "��");
                set("value", 500);
                set("base_weight", 30);
        }
        setup();
}

