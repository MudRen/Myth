inherit ITEM;
#include <task.h>
void create()
{
        set_name("�����ƹ���", ({"yunguang po", "po"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�п������֮������������֮��\n");
                set("unit", "��");
                set("lingtaibao","fake");
                set("owner_name","�϶�");
                set("owner_id","chang e");
        }
}


