inherit ITEM;
#include <ansi.h>
#include <task.h>
void create()
{
        set_name(HIR "ǧ����" NOR, ({"qianjin qiu", "qiu"}));
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����������ƺȵģ�����������·���\n");
                set("unit", "��");
               set("owner_name","���");
               set("owner_id","li bai");
        }
}



